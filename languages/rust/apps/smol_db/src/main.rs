extern crate clap;
use clap::Parser;

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

fn main() {
    let cli = Cli::parse();
    dbg!(cli.list_records);
    dbg!(cli.write_new_record);
    dbg!(cli.lookup_by_title);
    dbg!(cli.lookup_by_developer);
    dbg!(cli.lookup_by_publisher);
}
