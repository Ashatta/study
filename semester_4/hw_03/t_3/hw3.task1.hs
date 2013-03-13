import Data.List
import Data.Maybe

firstMaxSumPosition [] = 0
firstMaxSumPosition (x:xs) = 1 + (fromMaybe (-1) $ elemIndex (maximum listOfSums) listOfSums)
    where listOfSums = zipWith (+) (x:xs) xs

main = do
    putStrLn $ "firstMaxSumPosition [] = " ++ (show $ firstMaxSumPosition [])
    putStrLn $ "firstMaxSumPosition [1] = " ++ (show $ firstMaxSumPosition [1])
    putStrLn $ "firstMaxSumPosition [1, 5, 6, 2] = " ++ (show $ firstMaxSumPosition [1, 5, 6, 2])
