pos ::  Int -> [Int] -> Maybe Int
pos n xs = if (withoutn == xs) then Nothing else Just (length withoutn)
    where withoutn = takeWhile (/= n) xs

