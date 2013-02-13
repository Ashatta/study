factorial :: Integral a => a -> a
factorial 0 = 1
factorial n | n > 0 = n * factorial (n - 1)
            | otherwise = error "Negative argument for factorial function"

main = do
    putStrLn "n! calculation. Enter n:"
    n <- readLn
    print (factorial n)
