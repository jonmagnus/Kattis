
main = interact $ unlines . map show . solve . tail . lines

solve :: [String] -> [Int]
solve [] = []
solve (_:s:rest) = (contMedian $ map read (words s)):(solve rest)

data Tree a = Node a (Tree a) (Tree a) | Empty

balance :: Tree (Int, a) -> Tree (Int, a)
balance Empty = Empty
balance t@(Node (n, a) l r)
  | size l > 2*size r = lrotate
  | size r > 2*size l = rrotate
  | otherwise = t
  where
    (Node (_, lv) ll lr) = l
    (Node (_, rv) rl rr) = r
    lrotate = (Node (n, lv) ll (Node (size lr + size r + 1, a) lr r))
    rrotate = (Node (n, rv) (Node (size l + size rl + 1, a) l rl) rr)

insert :: (Ord a) => Tree (Int, a) -> a -> Tree (Int, a)
insert (Node (n, a) l r) b
  | a < b = balance $ Node (n + 1, a) (insert l b) r
  | otherwise = balance $ Node (n + 1, a) l (insert r b)
insert Empty b = Node (1, b) Empty Empty

size :: Tree (Int, a) -> Int
size Empty = 0
size (Node (n, _) _ _) = n

(&) :: Tree (Int, a) -> Int -> a
Empty&_ = undefined
(Node (_, a) Empty _)&0 = a
(Node (_, a) l r)&i
  | lsize == i = a
  | lsize < i = r&(i - lsize - 1)
  | otherwise = l&i
  where lsize = size l

mean :: Tree (Int, Int) -> Int
mean t = (t&(tsize `div` 2) + t&((tsize - 1) `div` 2)) `div` 2
  where tsize = size t

transferAcc :: [Int] -> Tree (Int, Int) -> Int
transferAcc [] _ = 0
transferAcc (a:rest) t = mean t_ + transferAcc rest t_
  where t_ = insert t a

contMedian :: [Int] -> Int
contMedian a = transferAcc a Empty
