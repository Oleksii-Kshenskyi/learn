(ns hello.core-test
  (:require [clojure.test :refer :all]
            [hello.core :refer :all]))

(deftest a-test
  (testing "Tests that hello.core has an add function"
    (is (= (add 55 45)) 100)))

(deftest n-sum
    (testing "Tests summing n elements"
    (is (= (sum_of_list [11 11 11 11 11 11] 6) 66))
    (is (= (sum_of_list [11 11 11 11 11 11] 5) 55))
    (is (= (sum_of_list [11 11 11 11 11 11] 4) 44))
    (is (= (sum_of_list [11 11 11 11 11 11] 3) 33))
    (is (= (sum_of_list [11 11 11 11 11 11] 2) 22))
    (is (= (sum_of_list [11 11 11 11 11 11] 1) 11))
    (is (= (sum_of_list [11 11 11 11 11 11] 0) 0))
  )
)
