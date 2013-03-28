data BinarySearchTree a = Nil | Node a (BinarySearchTree a) (BinarySearchTree a)
    deriving (Eq, Show)

size :: BinarySearchTree a -> Int
size Nil = 0
size (Node _ left right) = 1 + (size left) + (size right)

height :: BinarySearchTree a -> Int
height Nil = 0
height (Node _ left right) = 1 + max (height left) (height right)

search :: (Ord a) => BinarySearchTree a -> a -> Bool
search Nil _ = False
search (Node y left right) x | x < y = search left y
                             | x > y = search right y
                             | otherwise = True

add :: (Ord a) => BinarySearchTree a -> a -> BinarySearchTree a
add Nil x = Node x Nil Nil
add t@(Node y left right) x | x < y = Node y (add left x) right
                            | x > y = Node y left (add right x)
                            | otherwise = t

remove :: (Ord a) => BinarySearchTree a -> a -> BinarySearchTree a
remove Nil _ = Nil
remove (Node y left right) x | x < y = Node y (remove left x) right
                             | x > y = Node y left (remove right x)
                             | otherwise = delete
    where delete | right == Nil = left
                 | otherwise = Node (minimum right) left (remove right (minimum right))
              where minimum (Node n left right) = if left == Nil
                                                      then n
                                                      else minimum left
