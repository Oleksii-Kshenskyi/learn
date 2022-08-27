using CommandLine;
using SmolDB;

var result = Parser.Default.ParseArguments<Options>(args)
    .WithParsed(o =>
    {
        if (o.ListRecords) Database.ListRecords();
        else if (o.WriteNewRecord) Database.WriteNewRecord();
        else if (o.Title != null) Database.LookupByTitle(o.Title);
        else if (o.Developer != null) Database.LookupByDeveloper(o.Developer);
        else if (o.Publisher != null) Database.LookupByPublisher(o.Publisher);
    });
