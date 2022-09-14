(ns smol-db.core
  (:require [smol-db.data :as db])
  (:gen-class))

(defn usage []
  (str "smol-db ver. 0.1.0\n"
       "Author: Einax\n"
       "A small videogame database app using SQLite.\n\n"
       "NOTE: the following options are mutually exclusive, but one of them is required.\n"
       "NOTE: -l, -w are flags, -t, -d and -p require a string to look up for.\n"
       "OPTIONS:\n"
       "\t--list, -l\tList all records in the database.\n"
       "\t--write, -w\tWrite a new record into the database.\n"
       "\t--title, -t <TEXT>\tLook up games in the database by title.\n"
       "\t--developer, -d <TEXT>\tLook up games in the database by developer.\n"
       "\t--publisher, -p <TEXT>\tLook up games in the database by publisher.\n"))

(defn validate-arg [args long short]
  (or (= (nth args 0) long) (= (nth args 0) short)))
(defn validate-flag [args long short]
  (and (validate-arg args long short) (= count args) 1))
(defn validate-arg-with-value [args long short]
  (and (validate-arg args long short) (= (count args) 2)))
(defn parse-args-and-run [args]
  (cond
    (validate-flag args "--list" "-l") (db/list-records)
    (validate-flag args "--write" "-w") (db/write-new-record)
    (validate-arg-with-value args "--title" "-t") (db/lookup-by-title (nth args 1))
    (validate-arg-with-value args "--developer" "-d") (db/lookup-by-developer (nth args 1))
    (validate-arg-with-value args "--publisher" "-p") (db/lookup-by-publisher (nth args 1))
    :else
    (println (str "ERROR: unknown command or misused option!\n" (usage)))))

(defn -main [& args]
  (System/setProperty "file.encoding" "UTF-8") 
  (cond
    (= (count args) 0) (println (str "ERROR: the app expects exactly one flag to determine what to do.\n" (usage)))
    (> (count args) 2) (println (str "ERROR: too many arguments. Choose exactly one from the list available.\n" (usage)))
    :else (parse-args-and-run args))
  0)

