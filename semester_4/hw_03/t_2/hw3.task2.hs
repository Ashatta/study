powersOfTwo = 1 : (map (*2) powersOfTwo)

main = do
    putStrLn $ "10 first powers of two: " ++ (show $ take 10 powersOfTwo)
