import Data.Char

is_palindrome :: Eq a => [a] -> Bool
is_palindrome [] = True
is_palindrome xs = let len = length xs
                       halfLen = len `div` 2 in
                   take halfLen xs == reverse (drop (len - halfLen) xs)

is_str_palindrome :: String -> Bool
is_str_palindrome = is_palindrome . map toLower . filter isAlpha

main = do
    putStrLn $ "\"A Roza upala na lapu Azora\" is a palindrome - " ++ (show $ is_str_palindrome "A Roza upala na lapu Azora")
    putStrLn $ "\"A Roza upal na lapu Azora\" is a palindrome - " ++ (show $ is_str_palindrome "A Roza upal na lapu Azora")
