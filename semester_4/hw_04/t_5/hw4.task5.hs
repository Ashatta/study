import System.IO

sortedInsert :: Int -> [Int] -> [Int]
sortedInsert x [] = [x]
sortedInsert x (y:ys) = if x > y
                            then y : (sortedInsert x ys)
                            else x:y:ys

loop :: [Int] -> IO ()
loop list = do
    putStr "> "
    command <- getLine
    case command of
        "h" -> do 
                   putStrLn ("Usage:\n" ++
                             "0 - exit\n" ++
                             "1 - add value to sorted list\n" ++ 
                             "2 - remove value from list\n" ++
                             "3 - print list\n" ++
                             "h - print this help")
                   loop list
        "0" -> putStrLn "Goodbye!"
        "1" -> do 
                   putStr "Value to insert: "
                   value <- readLn
                   loop (sortedInsert value list)
        "2" -> do 
                   putStr "Value to remove: "
                   value <- readLn
                   loop (filter (/= value) list)
	"3" -> do  putStrLn $ show list
                   loop list
        _   -> do  putStrLn "Wrong command. Try again. Type 'h' for help"
                   loop list

main = do
    hSetBuffering stdout NoBuffering
    putStrLn "Handling a sorted list. 'h' for help"
    loop []
