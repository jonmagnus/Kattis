
main = interact $ show . (\x -> solve (sieve [2..(intSqrt x)]) x) . read

intSqrt :: Int -> Int
intSqrt = floor . sqrt . fromInteger . toInteger

sieve :: [Int] -> [Int]
sieve [] = []
sieve (p:ps) = p:[q | q <- ps, q `mod` p /= 0]

solve :: [Int] -> Int -> Int
solve _ 1 = 0
solve [] a = 1
solve primes@(p:ps) a
  | r == 0 = 1 + solve primes d
  | otherwise = solve ps a
  where (d, r) = divMod a p
