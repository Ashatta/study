areBracketsBalanced :: String -> Bool
areBracketsBalanced = realWorker "" . filter (`elem` "()<>{}[]")
     where realWorker stack "" = null stack
           realWorker stack (c:cs) = if opening c
                                         then realWorker (c:stack) cs
                                         else if (null stack || not (pair (head stack) c))
                                                  then False
                                                  else realWorker (tail stack) cs
           opening c = c `elem` "(<{["
           pair c1 c2 = (c1:c2:[]) `elem` ["()", "<>", "{}", "[]"]
