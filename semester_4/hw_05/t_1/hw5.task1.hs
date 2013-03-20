-- пока писала функцию для разложений, в процессе возникла она
-- не удержалась - решила оставить
-- уж больно красивая
compositions :: Int -> [[Int]]
compositions 0 = [[]]
compositions n = [1..n] >>= (\x -> map (x:) (compositions (n - x)))

partitions :: Int -> [[Int]]
partitions n = helper n n
    where helper n _ | n <= 0 = [[]]
          helper n maxToUse = [1..maxToUse] >>= (\x -> map (x:) (helper (n - x) (min x (n - x))))
