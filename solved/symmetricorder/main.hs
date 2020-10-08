import Data.List

main = interact $ unlines . concat . zipWith (++)
    [["SET " ++ show t] | t <- [1..]] . (map $ (solveCase [])) . (filter (\x -> x /= [])) . splitCase . lines

splitCase :: [String] -> [[String]]
splitCase [] = []
splitCase (n:ss) = (take (read n) ss):(splitCase $ drop (read n) ss)

solveCase :: [String] -> [String] -> [String]
solveCase acc [] = acc
solveCase acc (a:b:ss) = a:(solveCase (b:acc) ss)
solveCase acc [a] = a:(solveCase acc [])
