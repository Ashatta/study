data Tree a = Nil | Node a (Tree a) (Tree a)
     deriving (Eq, Show)

flatten :: Tree a -> [a]
flatten = helper []
    where helper xs Nil = xs
          helper xs (Node x left right) = helper (x:(helper xs right)) left

findAll :: (a -> Bool) -> Tree a -> [a]
findAll p = filter p . flatten
