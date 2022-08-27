using CommandLine;

class Options
{
    [Option('l', "list", SetName = "List", HelpText = "List all videogames in the database.")]
    public bool ListRecords { get; set; }

    [Option('w', "write", SetName = "Write", HelpText = "Write info about a new game to the database.")]
    public bool WriteNewRecord { get; set; }

    [Option('t', "title", SetName = "Title", HelpText = "Lookup games in the database by their title.")]
    public string? Title { get; set; }

    [Option('d', "developer", SetName = "Dev", HelpText = "Lookup games in the database by their developer studio name.")]
    public string? Developer { get; set; }

    [Option('p', "publisher", SetName = "Pub", HelpText = "Lookup games in the database by their publisher name.")]
    public string? Publisher { get; set; }
}