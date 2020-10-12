import Data.Array

main = interact $ (++ "\n") . solve . lines

findAny :: [Int] -> (Int -> Bool) -> Bool
findAny [] _ = False
findAny (a:b) f = if f a then True else findAny b f

target :: Array Int Char
target = array (0,10) $ zip [0..] "ICPCASIASG"

solve :: [String] -> String
solve (n_:m:_) = if findAny [0..nsq-1] $ iterate (array (0,nsq - 1) $ zip [0..] m) 0
                   then "YES"
                   else "NO"
  where
    n :: Int
    n = read n_
    nsq = n*n
    coordinates :: Int -> (Int, Int)
    coordinates a = (a `div` n, a `mod` n)
    index :: (Int, Int) -> Int
    index (a,b) = a*n + b
    neighbours :: Int -> [Int]
    neighbours a = [index (x + dx,y + dy) |
      dx <- [-2..2],
      dy <- [-2..2],
      dx*dx + dy*dy == 5 &&
        x + dx < n && x + dx >= 0 && y + dy < n && y + dy >= 0]
        where 
          (x,y) = coordinates a
    iterate :: Array Int Char -> Int -> Int -> Bool
    iterate a i p 
      | i == 10 = True
      | a!p == target!i = findAny (neighbours p) $ iterate a (i + 1)
      | otherwise = False
