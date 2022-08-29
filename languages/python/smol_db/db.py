import click

def count_args(my_argies):
    return len(list(filter(lambda x: x == True, my_argies)))

class SmolDB:
    def __init__(self):
        pass

    def list_records(self):
        pass

    def write_new_record(self):
        pass

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
    db = SmolDB()
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