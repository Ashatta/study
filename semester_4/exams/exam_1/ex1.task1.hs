primeNumbers = filter isPrime [1..]
    where isPrime n = filter ((0==) . (rem n)) [2..nRoot] == [] 
            where nRoot = truncate $ sqrt $ fromIntegral n
