powersOfTwo :: Integral a => a -> [a]
powersOfTwo n | n < 0 = error "The power must be non-negative"
                | otherwise = helper 1 n
                      where helper _ 0 = []
                            helper currValue count = currValue : helper (currValue * 2) (count - 1)

main = do
    putStrLn "Generating powers of two"
    putStrLn $ "powersOfTwo 10 = " ++ (show $ powersOfTwo 10)
    putStrLn $ "powersOfTwo 0 = " ++ (show $ powersOfTwo 0)
    putStr $ "powersOfTwo (-1) = " 
    putStrLn $ show $ powersOfTwo (-1)

