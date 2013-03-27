data Tree a = Nil | Node a (Tree a) (Tree a)
      deriving (Eq, Show)

flatten :: Tree a -> [a]
flatten = helper []
    where helper xs Nil = xs
          helper xs (Node x left right) = helper (x:(helper xs right)) left

negativeElements :: (Num a, Ord a) => Tree a -> [a]
negativeElements = filter (<0) . flatten
