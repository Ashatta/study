data Tree a = Nil | Node a (Tree a) (Tree a)
    deriving (Eq, Show)

minimumHeight :: Tree a -> Int
minimumHeight Nil = 0
minimumHeight (Node _ left right) = 1 + min (minimumHeight left) (minimumHeight right)

main = do
    putStrLn "Length of the shortest path from a root to a leaf in a binary tree:"
    putStrLn $ "height Nil = " ++ (show $ minimumHeight Nil)
    putStrLn $ "height (Node 10 Nil Nil) = " ++ (show $ minimumHeight (Node 10 Nil Nil))
    let t = (Node 5 
                  (Node 10 
                        Nil 
                        (Node 20 Nil Nil)) 
                  (Node 4 
                        Nil 
                        (Node 4 
                              (Node 7 Nil Nil)
                              (Node 5 Nil Nil))))
    putStrLn $ "height " ++ (show t) ++ " = " ++ (show $ minimumHeight t)
