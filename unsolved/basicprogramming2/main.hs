import Data.List

main = interact $ (++ "\n") . solve . (map ((map read) . words)) . lines

sumsTo :: Int -> [Int] -> [Int] -> Bool
sumsTo _ [] _ = False
sumsTo _ _ [] = False
sumsTo s left@(l:ls) right@(r:rs)
  | l + r == s = True
  | l + r > s = sumsTo s left rs
  | otherwise = sumsTo s ls right

unique :: Int -> [Int] -> Bool
unique _ [] = True
unique a (b:rest)
  | a == b = False
  | otherwise = unique b rest

findMajority :: [Int] -> Int -> Int -> Int
findMajority [] _ _ = -1
findMajority (a:b:rest) n c
  | 2*c > n = a
  | a == b = findMajority (b:rest) n (c + 1)
  | otherwise = findMajority (b:rest) n 1
findMajority (a:rest) n c 
  | 2*c > n = a
  | otherwise = -1

findMedians :: [Int] -> Int -> Int -> [Int]
findMedians (a:rest) n i
  | 2*i == n + 1 = [a]
  | 2*i == n = [a,b]
  | otherwise = findMedians rest n (i + 1)
  where
    (b:_) = rest

solve :: [[Int]] -> String
solve [[n, t], a] 
  | t == 1 = if (sumsTo 7777 sa (reverse sa)) then "Yes" else "No"
  | t == 2 = if (unique (-1) sa) then "Unique" else "Contains duplicate"
  | t == 3 = show $ findMajority sa n 1
  | t == 4 = unwords $ (map show) $ findMedians sa n 1
  where 
    sa = sort a
