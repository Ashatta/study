data Tree a = Nil | Node a (Tree a) (Tree a)
    deriving (Eq, Show)

toString :: Tree Char -> String
toString node = helper "" node
    where helper str Nil = 'e':str
          helper str (Node x left right) = 'n':x:(helper (helper str right) left)

treeFromString :: String -> Tree Char
treeFromString str = if snd parsed == "" then fst parsed else error "parse error"
    where parsed = parse str
            where parse ('e':cs) = (Nil, cs)
                  parse ('n':c:cs) = let (left, second) = parse cs in
                                         let (right, rest) = parse second in
                                             (Node c left right, rest)
                  parse _ = error "parse error"

main = do
    let t = Node 't' 
                (Node 'b' 
                     (Node 'e' 
                          Nil 
                          (Node 't' 
                               (Node 'b' Nil Nil) 
                               (Node 'e' Nil Nil))) 
                     (Node 'o' 
                          (Node 'n' Nil Nil) 
                          Nil)) 
                (Node 'o' 
                     (Node 'r' Nil Nil) 
                     (Node 'o' 
                          (Node 't' 
                               Nil 
                               (Node 'o' Nil Nil)) 
                          Nil))
    let str = "ntnbneentnbeeneeenonneeenonreenontenoeee"
    if treeFromString str /= t 
        then error "treeFromString incorrect" 
        else if toString t /= str 
                 then error "toString incorrect" 
                 else putStrLn "OK"
