(ns smol-db.core)

(defn foo
  "I don't do a whole lot."
  [x]
  (println x "Hello, World!"))


(defn -main [& args]
  (System/setProperty "file.encoding" "UTF-8") 
  (println "The args are: " args))
