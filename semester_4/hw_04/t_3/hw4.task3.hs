import Test.QuickCheck

numberOfEven1 :: [Int] -> Int
numberOfEven1 = length . filter even

numberOfEven2 :: [Int] -> Int
numberOfEven2 = foldr (\y -> if even y then (+1) else id) 0

numberOfEven3 :: [Int] -> Int
numberOfEven3 = foldr (+) 0 . map ((1-) . (flip mod) 2)

main = do
    quickCheck $ \l -> numberOfEven1 l == numberOfEven2 l
    quickCheck $ \l -> numberOfEven1 l == numberOfEven3 l
