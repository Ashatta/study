import Control.Monad

localMaximum :: (Ord a) => [a] -> Maybe a
localMaximum [] = Nothing
localMaximum [x] = Nothing
localMaximum xs@(x:y:ys) = foldr mplus Nothing (zip3 xs (y:ys) ys >>= return . middle)
    where middle (a,b,c) = if (a < b && b > c) then Just b else Nothing
