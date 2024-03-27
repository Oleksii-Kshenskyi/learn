module Lib
    ( someFunc
    ) where

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib (n-1) + fib (n - 2)

someFunc :: IO ()
someFunc = putStrLn ("fib " ++ show (42 :: Int) ++ " is " ++ show (fib 42))
