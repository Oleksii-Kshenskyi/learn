extern crate clap;
use clap::Parser;
use rusqlite::Error;

mod db;
use crate::db::*;

#[derive(Parser)]
#[clap(author = "Oleksii Kshenskyi")]
#[clap(version = "0.1.0")]
#[clap(about = "A basic videogame console database app using Clap and SQLite.")]
struct Cli {
    #[clap(short = 'l', long = "list", help = "List all videogame records currently in the DB.", group="l", conflicts_with_all=&["w", "t", "d", "p"])]
    list_records: bool, 

    #[clap(short = 'w', long = "write", help = "Write a new videogame record into the database.", group="w", conflicts_with_all=&["l", "t", "d", "p"])]
    write_new_record: bool,

    #[clap(short = 't', long = "title", help = "Lookup videogames by game title.", group="t", conflicts_with_all=&["l", "w", "d", "p"])]
    lookup_by_title: Option<String>,

    #[clap(short = 'd', long = "developer", help = "Lookup videogames by developer studio name.", group="d", conflicts_with_all=&["l", "w", "t", "p"])]
    lookup_by_developer: Option<String>,

    #[clap(short = 'p', long = "publisher", help = "Lookup videogames by publisher name.", group="p", conflicts_with_all=&["l", "w", "t", "d"])]
    lookup_by_publisher: Option<String>
}

fn main() -> Result<(), Error> {
    let cli = Cli::parse();
    
    let db = Database::new()?;

    if cli.list_records {
        return db.list_records();
    }
    else if cli.write_new_record {
        return db.write_new_record();
    }
    else if let Some(title) = cli.lookup_by_title {
        return db.lookup_by_title(&title);
    }
    else if let Some(developer) = cli.lookup_by_developer {
        return db.lookup_by_developer(&developer);
    }
    else if let Some(publisher) = cli.lookup_by_publisher {
        return db.lookup_by_publisher(&publisher);
    }
    else { unreachable!("None of the options are true. This should be impossible."); }
}
