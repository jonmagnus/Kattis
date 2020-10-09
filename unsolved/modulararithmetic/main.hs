
main = interact $ unlines . parse . lines

parse :: [String] -> [String]
parse [] = []
parse (l:rest) = (map (show . solve n) (take t rest)) ++ (parse $ drop t rest)
    where
      [n, t] = map read (words l)

solve :: Int -> String -> Int
solve n s
  | op == "+" = (a + b) `mod` n
  | op == "-" = (a - b) `mod` n
  | op == "*" = (a * b) `mod` n
  | op == "/" = modDiv n a b
  where
    [a_, op, b_] = words s
    [a, b] = map read [a_, b_]

extendedEuler :: Int -> Int -> [Int]
extendedEuler 0 b = [0, 1, b]
extendedEuler a b = [l - k*m, k, d]
  where 
    [k, l, d] = extendedEuler (b `mod` a) a
    m = b `div` a

modInv :: Int -> Int -> Int
modInv n a
  | d /= 1 = -1
  | otherwise = k `mod` n
  where 
    [k,_,d] = extendedEuler a n

modDiv :: Int -> Int -> Int -> Int
modDiv _ _ 0 = -1
modDiv _ 0 _ = 0
modDiv n a b 
  | binv == -1 = -1
  | otherwise = (ared * binv) `mod` n
  where
    [ared, bred] = map (`div` (gcd a b)) [a, b]
    binv = modInv n bred
