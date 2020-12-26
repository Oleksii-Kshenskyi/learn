module Main where

import Lib
import qualified Text.Printf as P
import qualified Data.Foldable as F
import qualified Data.Text as T

{-# LANGUAGE OverloadedStrings #-}

fileName :: String
fileName = "kekw.txt"

main :: IO ()
main = do
    P.printf "Read from file -> to lines -> to list of ints -> each element * 2 -> sum up the results: "
    print $ F.foldl1 (+) $ map (* 2) $ numsFromString $ stringFromFile fileName
