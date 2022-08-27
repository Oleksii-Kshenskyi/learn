using CommandLine;
using SmolDB;

var db = new Database(".");
var result = Parser.Default.ParseArguments<Options>(args)
    .WithParsed(o =>
    {
        if (o.ListRecords) db.ListRecords();
        else if (o.WriteNewRecord) db.WriteNewRecord();
        else if (o.Title != null) db.LookupByTitle(o.Title);
        else if (o.Developer != null) db.LookupByDeveloper(o.Developer);
        else if (o.Publisher != null) db.LookupByPublisher(o.Publisher);
    });
