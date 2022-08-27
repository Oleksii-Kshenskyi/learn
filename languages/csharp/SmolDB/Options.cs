using CommandLine;

class Options
{
    [Option('l', "list", HelpText = "List all videogames in the database.")]
    public bool ListRecords { get; set; }

    [Option('w', "write", HelpText = "Write info about a new game to the database.")]
    public bool WriteNewRecord { get; set; }

    [Option('t', "title", HelpText = "Lookup games in the database by their title.")]
    public string? Title { get; set; }

    [Option('d', "developer", HelpText = "Lookup games in the database by their developer studio name.")]
    public string? Developer { get; set; }

    [Option('p', "publisher", HelpText = "Lookup games in the database by their publisher name.")]
    public string? Publisher { get; set; }
}