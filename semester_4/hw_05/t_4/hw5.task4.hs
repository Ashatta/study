multTable :: Int -> [Int]
multTable n = nFirst >>= (\x -> nFirst >>= (\y -> [x*y]))
    where nFirst = take n [1..]
