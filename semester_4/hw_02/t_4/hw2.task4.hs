import Test.QuickCheck
import Data.Maybe
import Data.List

pos :: Int -> [Int] -> Maybe Int
pos _ [] = Nothing
pos n (x:_) | x == n = Just 0
pos n (x:xs) = if isNothing posInTail
                   then Nothing
                   else Just $ fromJust posInTail + 1
    where posInTail = pos n xs

main = quickCheck (\n xs -> pos n xs == elemIndex n xs)
