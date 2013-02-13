fibonacci :: Integral a => a -> a
fibonacci = fibHelper 0 1
    where fibHelper _ _ n | n < 0 = error "Negative argument for fibonacci function"
          fibHelper result _ 0 = result
          fibHelper _ result 1 = result
          fibHelper curr next n = fibHelper next (curr + next) (n - 1)

main = do
    putStrLn "Calculation of n-th Fibonacci number. Enter n:"
    n <- readLn
    print (fibonacci n)
