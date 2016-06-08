import qualified Data.Foldable as F
import Data.Monoid

data Tree a = Nil | Node a (Tree a) (Tree a)
      deriving (Eq, Show)

flatten :: Tree a -> [a]
flatten = helper []
    where helper xs Nil = xs
          helper xs (Node x left right) = helper (x:(helper xs right)) left

negativeElements :: (Num a, Ord a) => Tree a -> [a]
negativeElements = filter (<0) . flatten

instance F.Foldable Tree where
    foldMap f Nil = mempty
    foldMap f (Node x left right) = F.foldMap f left `mappend` f x `mappend` F.foldMap f right

flatten' :: Tree a -> [a]
flatten' = F.foldMap (\x -> [x])
