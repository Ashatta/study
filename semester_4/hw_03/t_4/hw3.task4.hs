data Tree a = Nil | Node a (Tree a) (Tree a)
    deriving (Eq, Show)

height :: Tree a -> Int
height Nil = 0
height (Node _ left right) = 1 + max (height left) (height right)

main = do
    putStrLn "Binary tree height:"
    putStrLn $ "height Nil = " ++ (show $ height Nil)
    putStrLn $ "height (Node 10 Nil Nil) = " ++ (show $ height (Node 10 Nil Nil))
    let t = (Node 5 
                  (Node 10 
                        Nil 
                        (Node 20 Nil Nil)) 
                  (Node 4 
                        Nil 
                        (Node 4 
                              (Node 7 Nil Nil)
                              (Node 5 Nil Nil))))
    putStrLn $ "height " ++ (show t) ++ " = " ++ (show $ height t)
