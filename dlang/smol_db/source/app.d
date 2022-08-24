import std.stdio;
import std.getopt;
import std.range;

int main(string[] args)
{
    bool list_records = false;
    bool write_new_record = false;
    string lookup_by_name = "";
    string lookup_by_developer = "";
    string lookup_by_publisher = "";
    auto parsedArgs = getopt(
        args,
        "list|l", "List all currently available game records.", &list_records,
        "write|w", "Write a new record to the database.", &write_new_record,
        "byname|n", "Lookup a game in the existing records by name.", &lookup_by_name,
        "bydev|d", "Lookup a game in the existing records by its development studio name.", &lookup_by_developer,
        "bypub|p", "Lookup a game in the existing records by its publisher name.", &lookup_by_publisher
    );
    if (parsedArgs.helpWanted) {
        defaultGetoptPrinter("A small videogame database app.\nTake a look at the options below. These are mutually exclusive, and exactly one is required.",
        parsedArgs.options);
        return 0;
    }

    ushort num_of_set = 0;
    if(list_records) num_of_set++;
    if(write_new_record) num_of_set++;
    if(!lookup_by_name.empty) num_of_set++;
    if(!lookup_by_developer.empty) num_of_set++;
    if(!lookup_by_publisher.empty) num_of_set++;
    if(num_of_set != 1) {
        writeln("ERROR: all the arguments are mutually exclusive.");
        writeln("You need to provide exactly one argument of your choosing to tell the program what you want to do.");
        writeln("To learn more, type 'smol_db -h'");
        return 1;
    }

    writeln("The number of arguments that have been set is ", num_of_set);
    return 0;
}
