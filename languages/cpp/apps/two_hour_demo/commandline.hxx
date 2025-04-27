#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <regex>

enum class CommandType {
    AddTimeDiffs,
    SubTimeDiffs,
    DateDifference,
    Borked,
};

struct DateDiff {
    uint32_t hours;
    uint32_t minutes;
    uint32_t seconds;
};

struct Date {
    uint32_t year;
    uint32_t month;
    uint32_t day;
};

struct Args {
    std::vector<std::string> args;
    bool valid;
};

CommandType command_type(const Args& args);

std::shared_ptr<DateDiff> _diff_from_regex(const std::string& diff, const std::string& re);

std::shared_ptr<DateDiff> new_diff(const std::string& diff);

std::shared_ptr<Date> new_date(const std::string& date_str);
void print_date(const Date& dt);

bool are_diffs_valid(const Args& args);
bool are_dates_valid(const Args& args);
bool are_args_valid(const Args& args);

Args new_args(int argc, char** argv);