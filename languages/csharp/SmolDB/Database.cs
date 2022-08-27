using SQLite;

namespace SmolDB
{
    internal class DBSchema {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }

        [NotNull]
        public string? Title { get; set; }

        public ushort Year { get; set; }

        public string? Developer { get; set; }

        public string? Publisher { get; set; }

        public string? Genre { get; set; }
    }
    internal class Database
    {
        private readonly SQLiteConnection _db;
        private void PrintQuery(TableQuery<DBSchema> query, string withPrompt = "") {
            Console.WriteLine($"=========={ withPrompt }==========="); Console.WriteLine();
            foreach (var record in query)
            {
                Console.WriteLine("ID: " + record.Id);
                Console.WriteLine("Title: " + record.Title);
                Console.WriteLine("Year: " + record.Year);
                Console.WriteLine("Developer: " + record.Developer);
                Console.WriteLine("Publisher: " + record.Publisher);
                Console.WriteLine("Genre: " + record.Genre);
                Console.WriteLine();
            }
            Console.WriteLine($"===========END { withPrompt }==========");
        }

        public Database(string Folder) {
            var databasePath = Path.Combine(Folder, "database.db");
            _db = new SQLiteConnection(databasePath);
            _db.CreateTable<DBSchema>();
        }
        public void ListRecords() {
            var query = _db.Table<DBSchema>();
            Console.WriteLine("Games in database: " + query.Count());
            PrintQuery(query, "VIDEOGAMES");
        }
        public void WriteNewRecord() {
            Console.WriteLine("Please provide info for a new videogame record in the database...");
            Console.Write("Game's Title? => "); var title = Console.ReadLine();

            ushort year = 0;
            var intProvided = false;
            while (!intProvided)
            {
                try
                {
                    Console.Write("Year of Release? => "); year = Convert.ToUInt16(Console.ReadLine());
                    intProvided = true;
                }
                catch { intProvided = false; Console.WriteLine("You have to provide a number ranging 0-65535 for year of release."); }
            }
            
            Console.Write("Game's Developer? => "); var developer = Console.ReadLine();
            Console.Write("Game's Publisher? => "); var publisher = Console.ReadLine();
            Console.Write("Game's Genre? => "); var genre = Console.ReadLine();

            var record = new DBSchema { 
                Title = title,
                Year = year,
                Developer = developer,
                Publisher = publisher,
                Genre = genre
            };
            _db.Insert(record);
        }
        public void LookupByTitle(string Title) {
            if (Title == null) {
                Console.WriteLine("ERROR: title to look for cannot be empty!");
                return;
            }
            Console.WriteLine("Looking up games by title...");
            var lookedUp = _db.Table<DBSchema>().Where(game => game.Title != null && game.Title.Contains(Title));
            Console.WriteLine($"Games found: { lookedUp.Count()}");
            PrintQuery(lookedUp);
        }
        public void LookupByDeveloper(string Developer) {
            if (Developer == null)
            {
                Console.WriteLine("ERROR: developer name to look for cannot be empty!");
                return;
            }
            Console.WriteLine("Looking up games by developer studio name...");
            var lookedUp = _db.Table<DBSchema>().Where(game => game.Developer != null && game.Developer.Contains(Developer));
            Console.WriteLine($"Games found: {lookedUp.Count()}");
            PrintQuery(lookedUp);
        }
        public void LookupByPublisher(string Publisher) {
            if (Publisher == null)
            {
                Console.WriteLine("ERROR: publisher name to look for cannot be empty!");
                return;
            }
            Console.WriteLine("Looking up games by publisher name...");
            var lookedUp = _db.Table<DBSchema>().Where(game => game.Publisher != null && game.Publisher.Contains(Publisher));
            Console.WriteLine($"Games found: {lookedUp.Count()}");
            PrintQuery(lookedUp);
        }
    }
}
