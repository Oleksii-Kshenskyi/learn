using CommandLine;

var result = Parser.Default.ParseArguments<Options>(args)
    .WithParsed(o =>
    {
        Console.WriteLine("list? " + o.ListRecords);
        Console.WriteLine("write? " + o.WriteNewRecord);
        Console.WriteLine("bytitle? " + (o.Title != null ? o.Title : "null"));
        Console.WriteLine("bydev? " + (o.Developer != null ? o.Developer : "null"));
        Console.WriteLine("bypub? " + (o.Publisher != null ? o.Publisher : "null"));
    });
