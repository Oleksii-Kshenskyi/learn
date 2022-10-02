module Database

open System.Data.SQLite

type Database() =
    let _conn = new SQLiteConnection("Data Source=database.db")
    do
        _conn.Open()
    let creationSql = "CREATE TABLE IF NOT EXISTS videogame (" +
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
                      "title TEXT NOT NULL, " +
                      "year INTEGER, " +
                      "developer TEXT, " +
                      "publisher TEXT, " +
                      "genre TEXT" +
                      ")"
    let creationCommand = new SQLiteCommand(creationSql, _conn)
    do
        creationCommand.ExecuteNonQuery |> ignore

let listRecords() =
    printfn "LIST KEKW"

let writeNewRecord() =
    printfn "WRITE KEKW"

let lookupByTitle(t: string) =
    printfn "TITLE KEKW => %s" t

let lookupByDeveloper(d: string) =
    printfn "DEVELOPER KEKW => %s" d

let lookupByPublisher(p: string) =
    printfn "PUBLISHER KEKW => %s" p