module Lib
    ( stringFromFile,
      numsFromString
    ) where

{-# LANGUAGE OverloadedStrings #-}
import qualified Data.Text as T
import qualified Data.Text.IO as I
import qualified System.IO.Unsafe as U
import qualified Data.Text.Read as R
import qualified Data.Either as E

stringFromFile :: String -> T.Text
stringFromFile fileName = U.unsafePerformIO $ I.readFile fileName

numsFromString :: T.Text -> [Integer]
numsFromString contents = map fst $ E.rights $ map R.decimal $ T.lines contents
