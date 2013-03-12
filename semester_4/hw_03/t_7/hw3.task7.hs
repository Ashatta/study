import Test.QuickCheck

func f g l = filter f (map g l)
-- func f g = filter f . map g
-- func f g = ((filter f) .) (map g)
-- func f = ((filter f) .) . map
-- func f = (.) ((filter f) .) map
-- func f = flip (.) map ((filter f) .)
func2 = flip (.) map . (.) . filter

main = quickCheck ((\l -> func odd (*3) l == func2 odd (*3) l) :: [Int] -> Bool)

