function xs = fst result / snd result
    where result = helper 0 1 xs
              where helper sum prod [] = (sum, prod)
                    helper sum prod (x:xs) = helper (sum+x) (prod * (cos x)) xs
