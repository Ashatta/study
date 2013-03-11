import Test.QuickCheck

_reverse :: [a] -> [a]
_reverse [] = []
_reverse xs = foldl (\l x -> x:l) [] xs

main = quickCheck ((\xs -> _reverse xs == reverse xs) :: [Int] -> Bool)
