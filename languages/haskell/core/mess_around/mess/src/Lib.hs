module Lib
    ( someFunc
    ) where

import Data.Word(Word64)

-- fib :: Int -> Word64
-- fib = (map fib' [0 ..] !!)
--     where
--       fib' 0 = 0
--       fib' 1 = 1
--       fib' n = fib (n - 1) + fib (n - 2)

-- fib :: Int -> Integer
-- fib n = loop 0 1 n
--     where
--         loop :: Integer -> Integer -> Int -> Integer
--         loop a b 0 = a
--         loop a b n = loop b (a + b) (n - 1)

-- fib2 :: Int -> Int
-- fib2 0 = 0
-- fib2 1 = 1
-- fib2 n = fib2 (n-1) + fib2 (n - 2)

fib :: Word -> Word64
fib = loop 0 1
  where
    loop :: Word64 -> Word64 -> Word -> Word64
    loop a _ 0 = a
    loop a b x = loop b (a + b) (x - 1)

someFunc :: IO ()
someFunc = putStrLn ("fib " ++ show (42 :: Int) ++ " is " ++ show (fib 42))
