(ns smol-db.data
  (:require [clojure.pprint :as p]
            [clojure.java.jdbc :as j]))

(def db {:classname "org.sqlite.JDBC"
         :subprotocol "sqlite"
         :subname "./database.db"})

(defn read-with-prompt [prompt]
  (print prompt)
  (flush)
  (read-line))
(defn init-db [] (j/execute! db (str "CREATE TABLE IF NOT EXISTS videogame("
                                  "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                  "title TEXT NOT NULL,"
                                  "year INTEGER,"
                                  "developer TEXT,"
                                  "publisher TEXT,"
                                  "genre TEXT)")))
(defn list-records []
  (p/print-table (j/query db (str "SELECT * FROM videogame"))))
(defn write-new-record []
  (let [title (read-with-prompt "Game's title? => ")
        year (Integer/parseInt (read-with-prompt "Game's year of release? => "))
        developer (read-with-prompt "Game's developer? => ")
        publisher (read-with-prompt "Game's publisher? => ")
        genre (read-with-prompt "Game's genre? => ")]
    (j/execute! db (str "INSERT INTO videogame(title, year, developer, publisher, genre)"
                        "values("
                        "'" title "', "
                        year ", "
                        "'" developer "', "
                        "'" publisher "', "
                        "'" genre "'"
                        ")"))))
(defn lookup-by-title [title]
  (p/print-table (j/query db (str "SELECT * FROM videogame "
                                  "WHERE title LIKE '%"
                                  title
                                  "%'"))))
(defn lookup-by-developer [developer]
  (p/print-table (j/query db (str "SELECT * FROM videogame "
                                  "WHERE developer LIKE '%"
                                  developer
                                  "%'"))))
(defn lookup-by-publisher [publisher]
  (p/print-table (j/query db (str "SELECT * FROM videogame "
                                  "WHERE publisher LIKE '%"
                                  publisher
                                  "%'"))))