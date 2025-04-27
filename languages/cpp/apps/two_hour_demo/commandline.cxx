#include "commandline.hxx"

CommandType command_type(const Args& args) {
    if (args.args[1] == "adddiff") {
        return CommandType::AddTimeDiffs;
    }
    else if (args.args[1] == "subdiff") {
        return CommandType::SubTimeDiffs;
    }
    else if (args.args[1] == "datediff") {
        return CommandType::DateDifference;
    }
    else return CommandType::Borked;
}

std::shared_ptr<DateDiff> _diff_from_regex(const std::string& diff, const std::string& re) {
    std::smatch match;
    DateDiff dd = {};
    std::regex diffre(re);
    if (std::regex_search(diff, match, diffre)) {
        if (match.size() != 4) {
            return nullptr;
        }
        dd.hours = std::stoul(match[1].str());
        dd.minutes = std::stoul(match[2].str());
        dd.seconds = std::stoul(match[3].str());
    }
    else return nullptr;

    return std::make_shared<DateDiff>(std::move(dd));
}

std::shared_ptr<DateDiff> new_diff(const std::string& diff) {
    DateDiff dd = {};
    std::smatch match;
    try {
        auto _the_diff = _diff_from_regex(diff, R"(^(\d+)\:(\d+)\:(\d+)$)");
        if (_the_diff) {
            return _the_diff;
        }
        else {
            return _diff_from_regex(diff, R"(^(((\d+)[h|m|s]){0,1}){1,3}$)"); // this is borked
        }
    }
    catch (...) {
        return nullptr;
    }

    return std::make_shared<DateDiff>(std::move(dd));
}

void print_date(const Date& dt) {
    std::cout << dt.day << "." << dt.month << "." << dt.year;
}

std::shared_ptr<Date> new_date(const std::string& date_str) {
    Date dt;
    std::smatch match;
    std::regex re(R"(^(\d{1,2})\.(\d{1,2})\.(\d{1,4})$)");
    if (std::regex_search(date_str, match, re)) {
        if (match.size() != 4) {
            return nullptr;
        }

        dt.day = std::stoul(match[1].str());
        dt.month = std::stoul(match[2].str());
        dt.year = std::stoul(match[3].str());
    }
    else return nullptr;

    return std::make_shared<Date>(std::move(dt));
}

bool are_diffs_valid(const Args& args) {
    return new_diff(args.args[2]) != nullptr && new_diff(args.args[3]) != nullptr;
}

bool are_dates_valid(const Args& args) {
    std::cout << "what" << std::endl;
    return new_date(args.args[2]) != nullptr && new_date(args.args[3]) != nullptr;
}

bool are_args_valid(const Args& args) {
    if (args.args.size() != 4) {
        std::cout << "k" << std::endl;
        return false;
    }
    auto cmdtype = command_type(args);
    if (cmdtype == CommandType::Borked) {
        std::cout << "kk" << std::endl;
        return false;
    }
    else if (cmdtype == CommandType::AddTimeDiffs || cmdtype == CommandType::SubTimeDiffs) {
        std::cout << "kkk" << std::endl;
        return are_diffs_valid(args);
    }
    else if (cmdtype == CommandType::DateDifference) {
        std::cout << "kkkk" << std::endl;
        return are_dates_valid(args);
    }
    return true;
}

Args new_args(int argc, char** argv) {
    Args args = {};
    for (int i = 0; i < argc; i++) {
        args.args.push_back(argv[i]);
    }

    args.valid = are_args_valid(args);

    return args;
}