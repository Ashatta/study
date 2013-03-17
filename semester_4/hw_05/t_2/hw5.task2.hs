import Test.QuickCheck

check1 :: (a -> Bool) -> [a] -> Bool
check1 pred = foldr ((&&) . pred) True

check2 :: (a -> Bool) -> [a] -> Bool
check2 pred xs = null [ x | x <- xs, not (pred x) ]

check3 :: (a -> Bool) -> [a] -> Bool
check3 pred = null . filter (not . pred)

main = do
    quickCheck ((\xs -> check1 (>0) xs == check2 (>0) xs) :: [Int] -> Bool)
    quickCheck ((\xs -> check3 (>0) xs == check2 (>0) xs) :: [Int] -> Bool)
