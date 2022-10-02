open System
open CommandLine
open Database

let run(a: DbAction) =
    match a with
        | L -> listRecords()
        | W -> writeNewRecord()
        | T t -> lookupByTitle(t)
        | D d -> lookupByDeveloper(d)
        | P p -> lookupByPublisher(p)
        | E -> noCommand()

[<EntryPoint>]
let main(args) =
    try
        parser.ParseCommandLine(inputs = args, raiseOnUsage = true)
        |> determineActionType 
        |> run
    with e ->
        printfn "%s" e.Message
    0