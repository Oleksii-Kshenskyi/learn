use rusqlite::{Connection, Result, Error};
use std::io::{self, Write};
use std::fmt::Debug;

#[derive(Debug)]
pub struct Videogame {
    pub id: i32,
    pub title: String,
    pub year: u16,
    pub developer: String,
    pub publisher: String,
    pub genre: String
}

#[derive(Debug)]
pub struct TextUI {
    pub action_message: String,
    pub record_count_message: String,
    pub search_result_header: String
}

pub struct Database {
    db: Connection,
}

impl Database {
    pub fn new() -> Result<Self, Error> {
        let new_db = Connection::open("./database.db");
        match new_db {
            Ok(conn) => {
                conn.execute(
                    "CREATE TABLE IF NOT EXISTS videogame (
                        id INTEGER PRIMARY KEY AUTOINCREMENT,
                        title TEXT NOT NULL,
                        year INTEGER,
                        developer TEXT,
                        publisher TEXT,
                        genre TEXT
                    )", ()
                )?;
                Ok(Self { db: conn })
            },
            Err(err) => Err(err)
        }
    }

    pub fn list_records(&self) -> Result<(), Error> {
        self.select_query(TextUI {
            action_message: "Listing all games in the database...".to_owned(),
            record_count_message: "Games in database".to_owned(),
            search_result_header: "VIDEOGAMES".to_owned()
        },
        "SELECT * FROM videogame".to_string())
    }

    pub fn write_new_record(&self) -> Result<(), Error> {
        println!("Please give me some info about a videogame...");
        
        
        print!("Game's title? => "); io::stdout().flush().unwrap(); let mut title = String::new();
        let stdin = io::stdin(); stdin.read_line(&mut title).expect("ERROR reading videogame title from command line.");

        print!("Game's year of release? => "); io::stdout().flush().unwrap(); let mut year_str = String::new();
        stdin.read_line(&mut year_str).expect("ERROR reading videogame year from command line.");
        let year: u16 = year_str.trim().parse::<u16>().expect("ERROR: year is not a valid number.");

        print!("Game's developer studio name? => "); io::stdout().flush().unwrap(); let mut developer = String::new();
        stdin.read_line(&mut developer).expect("ERROR reading videogame developer studio name from command line.");

        print!("Game's publisher name? => "); io::stdout().flush().unwrap(); let mut publisher = String::new();
        stdin.read_line(&mut publisher).expect("ERROR reading videogame publisher name from command line.");

        print!("Game's genre? => "); io::stdout().flush().unwrap(); let mut genre = String::new();
        stdin.read_line(&mut genre).expect("ERROR reading videogame genre from command line.");

        self.db.execute("INSERT INTO videogame (title, year, developer, publisher, genre)
                              VALUES (?1, ?2, ?3, ?4, ?5)",
                            (title.trim(), year, developer.trim(), publisher.trim(), genre.trim()))?;

        Ok(())
    }

    pub fn lookup_by_title(&self, title: &str) -> Result<(), Error> {
        self.select_query( TextUI {
            action_message: format!("Listing games by title: {}...", title),
            record_count_message: format!("Games with title '{}'", title),
            search_result_header: "SEARCH BY TITLE".to_owned()
        }, 
        format!("SELECT * FROM videogame WHERE title LIKE '%{}%'", title))
    }

    pub fn lookup_by_developer(&self, developer: &str) -> Result<(), Error> {
        self.select_query( TextUI {
            action_message: format!("Listing games by developer studio name: {}...", developer),
            record_count_message: format!("Games with developer studio name '{}'", developer),
            search_result_header: "SEARCH BY DEV".to_owned()
        }, 
        format!("SELECT * FROM videogame WHERE developer LIKE '%{}%'", developer))
    }

    pub fn lookup_by_publisher(&self, publisher: &str) -> Result<(), Error> {
        self.select_query( TextUI {
            action_message: format!("Listing games by publisher name: {}...", publisher),
            record_count_message: format!("Games with publisher name '{}'", publisher),
            search_result_header: "SEARCH BY PUB".to_owned()
        }, 
        format!("SELECT * FROM videogame WHERE publisher LIKE '%{}%'", publisher))
    }

    fn select_query(&self, ti: TextUI, query: String) -> Result<(), Error> {
        println!("{}", ti.action_message);
        let mut games = self.db.prepare(query.as_str())?;
        let games_iter = games.query_map([], |row| {
            Ok(Videogame {
                id: row.get(0)?,
                title: row.get(1)?,
                year: row.get(2)?,
                developer: row.get(3)?,
                publisher: row.get(4)?,
                genre: row.get(5)?,
            })
        })?;
        let games_vec = games_iter.collect::<Vec<_>>();
        
        println!("{}: {}", ti.record_count_message, games_vec.len());
        println!("\n============{}===========\n", ti.search_result_header);
        for game in games_vec {
            println!("{:#?}\n", game?);
        }
        println!("==========END {}=========\n", ti.search_result_header);

        Ok(())
    }

}