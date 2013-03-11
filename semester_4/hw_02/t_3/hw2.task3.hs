import Data.Char

sum_of_digits :: Int -> Int
sum_of_digits n = foldr (+) 0 $ map (\char -> ord char - ord '0') $ show n

main = do
    putStrLn "Sum of digits of integral value"
    putStrLn $ "Sum of 0 = " ++ (show $ sum_of_digits 0)
    putStrLn $ "Sum of 5 = " ++ (show $ sum_of_digits 5)
    putStrLn $ "Sum of 424242 = " ++ (show $ sum_of_digits 424242)
