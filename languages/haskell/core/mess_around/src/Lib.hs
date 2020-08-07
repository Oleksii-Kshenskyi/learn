module Lib
    ( someFunc,
      multiplyList,
      incrementListElements,
      removeElementAt,
      removeElementAt2,
    ) where

import Data.List (splitAt)

someFunc :: IO ()
someFunc = putStrLn "someFunc"

multiplyList :: [Int] -> Int
multiplyList [x] = x
multiplyList (x:xs) = x * multiplyList xs

incrementListElements :: [Int] -> [Int]
incrementListElements list = map (+ 1) list

removeElementAt :: [Int] -> Int -> [Int]
removeElementAt [] _ = []
removeElementAt list index = let (left, right) = splitAt index list in left ++ drop 1 right

removeElementAt2 :: [Int] -> Int -> [Int]
removeElementAt2 [] _ = []
removeElementAt2 (x:xs) 0 = xs
removeElementAt2 (x:xs) n = x:removeElementAt2 xs (n-1)