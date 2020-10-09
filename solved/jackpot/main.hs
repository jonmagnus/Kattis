
main = interact $ unlines 
    . map ((\x -> if (x <= 1000000000) then show x else "More than a billion.") . foldr lcm 1 . map read . words) 
    . skipEven . tail . lines

skipEven :: [a] -> [a]
skipEven [] = []
skipEven (a:b:rest) = b:(skipEven rest)

