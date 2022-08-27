using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SQLite;
using SQLitePCL;

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
        private SQLiteConnection _db;

        public Database(string Folder) {
            var databasePath = Path.Combine(Folder, "database.db");
            _db = new SQLiteConnection(databasePath);
            _db.CreateTable<DBSchema>();
        }
        public void ListRecords() {
            Console.WriteLine("Games in database: " + _db.Table<DBSchema>().Count());
            Console.WriteLine("===========VIDEOGAMES=========="); Console.WriteLine();
            var selectAll = _db.Table<DBSchema>();
            foreach (var record in selectAll) {
                Console.WriteLine("ID: " + record.Id);
                Console.WriteLine("Title: " + record.Title);
                Console.WriteLine("Year: " + record.Year);
                Console.WriteLine("Developer: " + record.Developer);
                Console.WriteLine("Publisher: " + record.Publisher);
                Console.WriteLine("Genre: " + record.Genre);
                Console.WriteLine();
            }
            Console.WriteLine("===========VIDEOGAMES==========");
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
        public void LookupByTitle(string Title) { }
        public void LookupByDeveloper(string Developer) { }
        public void LookupByPublisher(string Publisher) { }
    }
}
