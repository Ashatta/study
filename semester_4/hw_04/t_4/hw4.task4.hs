import Test.QuickCheck

isUnique :: Eq a => [a] -> Bool
isUnique xs = xs == unify xs
    where unify [] = []
          unify (x:xs) = x : (unify $ filter (/= x) xs)

isUnique2 :: Eq a => [a] -> Bool
isUnique2 [] = True
isUnique2 (x:xs) = x `notElem` xs && isUnique xs

main = quickCheck ((\xs -> isUnique xs == isUnique2 xs) :: [Int] -> Bool)
