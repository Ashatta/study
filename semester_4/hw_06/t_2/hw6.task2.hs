import Data.List

-- много быдлокода =(

data Polynomial a = Polynomial [(a, Int)]

toList :: Polynomial a -> [(a, Int)]
toList (Polynomial xs) = xs

instance (Num a, Ord a, Show a) => Show (Polynomial a) where
    show (Polynomial []) = "0"
    show xs = (toList (reduce xs) >>= showMonomial)
         where showMonomial (x,y) = if y == 0 
                                        then show x 
                                        else showSign ++ showCoeff ++ "x" ++ showPower
                where showSign = if x > 0 then " + " else if x < 0 then " - " else ""
                      showCoeff = if abs x == 1 then "" else show $ abs x
                      showPower = if y == 1 then "" else '^':(show y)

multiply :: Num a => Polynomial a -> Polynomial a -> Polynomial a
multiply xs ys = reduce $ Polynomial [ (x*u,y+v) | (x,y) <- (toList xs), (u,v) <- (toList ys) ]

add :: Num a => Polynomial a -> Polynomial a -> Polynomial a
add (Polynomial xs) (Polynomial ys) = reduce $ Polynomial (xs ++ ys)

reduce :: Num a => Polynomial a -> Polynomial a
reduce = Polynomial . reduceList . toList
    where reduceList = map foldList . groupBy equalPower . sortBy compareMonomials
           where compareMonomials (_,f) (_,s) | f == s = EQ
                                              | f < s = LT
                                              | f > s = GT
                 equalPower (_,f) (_,s) = f == s
                 addMonomials (x,f) (y,s) | f == s = (x + y, f)
                 foldList (x:xs) = foldr addMonomials x xs
