import click
import sqlite3

def count_args(my_argies):
    return len(list(filter(lambda x: x == True, my_argies)))

class SmolDB:
    def __init__(self):
        self.db = sqlite3.connect("./database.db")
        self.db.execute("""CREATE TABLE IF NOT EXISTS videogame (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT NOT NULL,
            year INTEGER,
            developer TEXT,
            publisher TEXT,
            genre TEXT
        )""")
        self.db.commit()
    
    def __enter__(self):
        return self
    def __exit__(self, exc_type, exc_value, traceback):
        self.db.close()

    def list_records(self):
        rows = self.db.execute("SELECT * FROM videogame").fetchall()
        count = len(rows)
        print(f"\nGames in database: {count}")
        print("========VIDEOGAMES===========\n")
        for record in rows:
            print(f"ID: {record[0]}");
            print(f"Game Title: {record[1]}");
            print(f"Year of Release: {record[2]}");
            print(f"Developer: {record[3]}");
            print(f"Publisher: {record[4]}");
            print(f"Genre: {record[5]}"); print()
        print("========END VIDEOGAMES=======\n")

    def write_new_record(self):
        print("Please share some info about a videogame to put in the database...")
        print("Game's title? => ", end='', sep=""); t = str(input())
        print("Game's year of release? => ", end='', sep=""); y = int(input())
        print("Game's developer studio? => ", end='', sep=""); d = str(input())
        print("Game's publisher? => ", end='', sep=""); p = str(input())
        print("Game's genre? => ", end='', sep=""); g = str(input())
        self.db.execute(f"""INSERT INTO videogame (title, year, developer, publisher, genre)
                           VALUES ('{t}', {y}, '{d}', '{p}', '{g}')""")
        self.db.commit()

    def lookup_by_title(self, title):
        pass

    def lookup_by_developer(self, developer):
        pass

    def lookup_by_publisher(self, publisher):
        pass

@click.command()
@click.option('-l', '--list', is_flag=True, help="List all the games currently in the database.")
@click.option('-w', '--write', is_flag=True, help="Write info about a new game to the database.")
@click.option('-t', '--title', type=str, help="Lookup a game in the database by its title.")
@click.option('-d', '--developer', type=str, help="Lookup a game in the database by its developer studio name.")
@click.option('-p', '--publisher', type=str, help="Lookup a game in the database by its publisher name.")
def run_cli(list, write, title, developer, publisher):
    if count_args([list, write, title != None, developer != None, publisher != None]) != 1:
        print("ERROR: all the arguments are mutually exclusive, and the app expects exactly one to be provided.")
        return
    with SmolDB() as db:
        if list:
            db.list_records()
        elif write:
            db.write_new_record()
        elif title != None:
            db.lookup_by_title(title)
        elif developer != None:
            db.lookup_by_developer(developer)
        elif publisher != None:
            db.lookup_by_publisher(publisher)
        else: raise "ERROR: None of the arguments are used, this code should be unreachable!"

if __name__ == "__main__":
    run_cli()