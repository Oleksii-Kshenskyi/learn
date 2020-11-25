(ns hello.core)
(require '[clojure.core.reducers :as r])

(defn add [a b]
  (+ a b))

(defn sum_of_list [the_list num_of_elements]
  (apply + (take num_of_elements the_list)))


(defn sum_of_n_sums [the_list] 
    (+ 
      (r/fold + the_list) 
      (if (empty? the_list) 0 (sum_of_n_sums (pop the_list)))
    )
)

(defn sum_of_n_sums_2 [xs]
  (apply + (reductions + xs)))

(defn -main [& args]
  (println "OMG ACTUALLY WROKS?! POG!!! :: " (sum_of_n_sums_2 [11, 11, 11, 11, 11, 11]))
)