import Test.QuickCheck

func x l = map (\y -> y*x) l
-- func x = map (\y -> y*x)
-- func x = map (\y -> (*x) y)
func2 x = map (*x)

main = quickCheck ((\x l -> func x l == func2 x l) :: Int -> [Int] -> Bool)
