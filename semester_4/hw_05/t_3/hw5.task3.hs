nLengthLists :: Int -> [[Int]]
nLengthLists n | n <= 0 = []
nLengthLists 1 = [[1],[2],[3]]
nLengthLists n = [1, 2, 3] >>= (\x -> map (x:) (nLengthLists (n - 1)))

