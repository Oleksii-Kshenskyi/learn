import click

def count_args(my_argies):
    return len(list(filter(lambda x: x == True, my_argies)))

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
    print(f"list: {list}")
    print(f"write: {write}")
    print(f"title: {title}")
    print(f"developer: {developer}")
    print(f"publisher: {publisher}")

if __name__ == "__main__":
    run_cli()