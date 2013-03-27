data Printed = Book { title :: String,
                      author:: String,
                      price :: Double } |
               Magazine { title :: String,
                          year  :: Int,
                          number:: Int,
                          price :: Double }
       deriving (Eq, Show)

totalPrice :: [Printed] -> Double
totalPrice = foldr ((+) . price) 0
