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
