import Test.QuickCheck

check1 :: (a -> Bool) -> [a] -> Bool
check1 pred = foldr ((&&) . pred) True

check2 :: (a -> Bool) -> [a] -> Bool
check2 pred xs = null [ x | x <- xs, not (pred x) ]

main = quickCheck ((\xs -> check1 (>0) xs == check2 (>0) xs) :: [Int] -> Bool)
