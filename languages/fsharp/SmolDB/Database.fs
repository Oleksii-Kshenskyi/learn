module Database

open System.Data.SQLite
open System

type Database() =
    let _conn = new SQLiteConnection(@"URI=file:.\database.db")
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
        creationCommand.ExecuteNonQuery() |> ignore
    member this.C with get() = _conn

type SelectType =
    | CountAll
    | CountLike of string * string
    | SelectAll
    | SelectLike of string * string
    | Insert of string * int32 * string * string * string

let select(t: SelectType) =
    match t with
        | CountAll -> "SELECT count(*) FROM videogame"
        | CountLike (field, what) -> sprintf "SELECT count(*) FROM videogame WHERE %s LIKE '%%%s%%'" field what
        | SelectAll -> "SELECT * FROM videogame"
        | SelectLike (field, what) -> sprintf "SELECT * FROM videogame WHERE %s LIKE '%%%s%%'" field what
        | Insert (t, y, d, p, g) -> sprintf "INSERT INTO videogame(title, year, developer, publisher, genre) VALUES ('%s', %d, '%s', '%s', '%s')" t y d p g

let printResult(reader: SQLiteDataReader, count: int32) =
    printfn "Games selected: %d;" count
    printfn "===============VIDEOGAMES============\n"
    while(reader.Read()) do
        printfn "Videogame {\n\tID: %d,\n\tGame Title: '%s',\n\tYear of Release: %d,\n\tDeveloper: '%s',\n\tPublisher: '%s',\n\tGenre: '%s'\n}\n"
            (reader.GetInt32(0))
            (reader.GetString(1))
            (reader.GetInt32(2))
            (reader.GetString(3))
            (reader.GetString(4))
            (reader.GetString(5))
    printfn "\n=============END VIDEOGAMES=========="

let listRecords() =
    let db = new Database()
    let sql = select(SelectType.SelectAll)
    let reader = (new SQLiteCommand(sql, db.C)).ExecuteReader()
    let count = Convert.ToInt32((new SQLiteCommand(select(SelectType.CountAll), db.C)).ExecuteScalar())
    printResult(reader, count)

let requestRecord(): string * int32 * string * string * string =
    printfn "I need some info about a videogame to put into the database from you..."
    printf "Game's title? => "
    let t = Console.ReadLine()
    printf "Game's year of release? => "
    let y = Convert.ToInt32(Console.ReadLine())
    printf "Game's developer? => "
    let d = Console.ReadLine()
    printf "Game's publisher? => "
    let p = Console.ReadLine()
    printf "Game's genre? => "
    let g = Console.ReadLine()
    (t, y, d, p, g)

let writeNewRecord() =
    let db = new Database()
    match requestRecord() with
    | (t, y, d, p, g) -> (new SQLiteCommand(select(SelectType.Insert (t, y, d, p, g)), db.C)).ExecuteNonQuery() |> ignore

let lookupByTitle(t: string) =
    let db = new Database()
    let sql = select(SelectType.SelectLike ("title", t))
    let reader = (new SQLiteCommand(sql, db.C)).ExecuteReader()
    let count = Convert.ToInt32((new SQLiteCommand(select(SelectType.CountLike ("title", t)), db.C)).ExecuteScalar())
    printResult(reader, count)

let lookupByDeveloper(d: string) =
    let db = new Database()
    let sql = select(SelectType.SelectLike ("developer", d))
    let reader = (new SQLiteCommand(sql, db.C)).ExecuteReader()
    let count = Convert.ToInt32((new SQLiteCommand(select(SelectType.CountLike ("developer", d)), db.C)).ExecuteScalar())
    printResult(reader, count)

let lookupByPublisher(p: string) =
    let db = new Database()
    let sql = select(SelectType.SelectLike ("publisher", p))
    let reader = (new SQLiteCommand(sql, db.C)).ExecuteReader()
    let count = Convert.ToInt32((new SQLiteCommand(select(SelectType.CountLike ("publisher", p)), db.C)).ExecuteScalar())
    printResult(reader, count)