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
        println!("Listing all games in the database...");
        let mut games = self.db.prepare("SELECT * FROM videogame")?;
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
        
        println!("Games in database: {}", games_vec.len());
        println!("\n============VIDEOGAMES===========\n");
        for game in games_vec {
            println!("{:#?}\n", game?);
        }
        println!("\n==========END VIDEOGAMES=========\n");

        Ok(())
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
        println!("Listing games by title: {}...", title);
        let mut games = self.db.prepare(format!("SELECT * FROM videogame WHERE title LIKE '%{}%'", title).as_str())?;
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
        
        println!("Games with title '{}': {}", title, games_vec.len());
        println!("\n============SEARCH BY TITLE===========\n");
        for game in games_vec {
            println!("{:#?}\n", game?);
        }
        println!("\n==========END SEARCH BY TITLE=========\n");

        Ok(())
    }

    pub fn lookup_by_developer(&self, developer: &str) -> Result<(), Error> {
        println!("Listing games by developer studio name: {}...", developer);
        let mut games = self.db.prepare(format!("SELECT * FROM videogame WHERE developer LIKE '%{}%'", developer).as_str())?;
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
        
        println!("Games with developer name '{}': {}", developer, games_vec.len());
        println!("\n============SEARCH BY DEV===========\n");
        for game in games_vec {
            println!("{:#?}\n", game?);
        }
        println!("\n==========END SEARCH BY DEV=========\n");

        Ok(())
    }

    pub fn lookup_by_publisher(&self, publisher: &str) -> Result<(), Error> {
        println!("Listing games by publisher name: {}...", publisher);
        let mut games = self.db.prepare(format!("SELECT * FROM videogame WHERE publisher LIKE '%{}%'", publisher).as_str())?;
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
        
        println!("Games with publisher name '{}': {}", publisher, games_vec.len());
        println!("\n============SEARCH BY PUB===========\n");
        for game in games_vec {
            println!("{:#?}\n", game?);
        }
        println!("\n==========END SEARCH BY PUB=========\n");

        Ok(())
    }

}