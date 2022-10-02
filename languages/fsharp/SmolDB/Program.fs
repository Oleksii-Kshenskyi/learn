open System
open Argu

type ListArgs =
    | [<ExactlyOnce; Last>] List_Fake

    interface IArgParserTemplate with
        member this.Usage =
            match this with
                | List_Fake _ -> "You don't need this argument."

type WriteArgs =
    | [<ExactlyOnce; Last>] Write_Fake

    interface IArgParserTemplate with
        member this.Usage =
            match this with
                | Write_Fake _ -> "You don't need this argument."

and TitleArgs = 
    | [<MainCommand; Mandatory; ExactlyOnce; Last>] Title of title:string

    interface IArgParserTemplate with
        member this.Usage =
            match this with
            | Title _ -> "Game title to look for."

and DeveloperArgs = 
    | [<MainCommand; Mandatory; ExactlyOnce; Last>] Developer of dev:string

    interface IArgParserTemplate with
        member this.Usage =
            match this with
            | Developer _ -> "Developer studio name to look for."

and PublisherArgs = 
    | [<MainCommand; Mandatory; ExactlyOnce; Last>] Publisher of pub:string

    interface IArgParserTemplate with
        member this.Usage =
            match this with
            | Publisher _ -> "Publisher company name to look for."

and CliArguments = 
    | [<CliPrefix(CliPrefix.None); AltCommandLine("l")>] List of ParseResults<ListArgs>
    | [<CliPrefix(CliPrefix.None); AltCommandLine("w")>] Write of ParseResults<WriteArgs>
    | [<CliPrefix(CliPrefix.None); AltCommandLine("t")>] Title of ParseResults<TitleArgs>
    | [<CliPrefix(CliPrefix.None); AltCommandLine("d")>] Developer of ParseResults<DeveloperArgs>
    | [<CliPrefix(CliPrefix.None); AltCommandLine("p")>] Publisher of ParseResults<PublisherArgs>

    interface IArgParserTemplate with
        member s.Usage =
            match s with
            | List _ -> "List all records currently in the database."
            | Write _ -> "Write a new record into the database."
            | Title _ -> "Lookup games in the database by title."
            | Developer _ -> "Lookup games in the database by developer name."
            | Publisher _ -> "Lookup games in the database by publisher name."

let parser = ArgumentParser.Create<CliArguments>(programName = "SmolDB.exe")

let run(parsed: ParseResults<CliArguments>) =
    match parsed.GetAllResults() with
        | [List _] -> "LIST KEKW YES!!"
        | [Write _] -> "WRITE KEKW YES!!"
        | [Title t] -> "TITLE KEKW YES!! => " + t.ToString()
        | [Developer d] -> "DEVELOPER KEKW YES!! => " + d.ToString()
        | [Publisher p] -> "PUBLISHER KEKW YES!! => " + p.ToString()
        | _ -> "ERROR: please give a command to execute."

[<EntryPoint>]
let main(args) =
    try
        parser.ParseCommandLine(inputs = args, raiseOnUsage = true) |> run |> printfn "%s"
    with e ->
        printfn "%s" e.Message
    0