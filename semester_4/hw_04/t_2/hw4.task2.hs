data Tree a = Nil | Node a (Tree a) (Tree a)
     deriving (Eq, Show)

flatten :: Tree a -> [a]
flatten = helper []
    where helper xs Nil = xs
          helper xs (Node x left right) = helper (x:(helper xs right)) left

treeSymmetricFold :: (a -> b -> a) -> a -> Tree b -> a
treeSymmetricFold func init = foldl func init . flatten
