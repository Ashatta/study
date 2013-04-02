data Expression a = Const a |
                    Variable |
                    Add (Expression a) (Expression a) |
                    Subtract (Expression a) (Expression a) |
                    Multiply (Expression a) (Expression a) |
                    Divide (Expression a) (Expression a) |
                    Power (Expression a) Int
    deriving Show

derivation (Const _) = Const 0
derivation Variable = Const 1
derivation (Add first second) = Add (derivation first) (derivation second)
derivation (Subtract first second) = Subtract (derivation first) (derivation second)
derivation (Multiply first second) = Add (Multiply (derivation first) second) (Multiply first (derivation second))
derivation (Divide first second) = Divide
                                        (Subtract
                                             (Multiply (derivation first) second)
                                             (Multiply first (derivation second)))
                                        (Power second 2)
derivation (Power base power) = if power == 0
                                    then Const 0
                                    else Multiply (Const power) (Multiply (Power base (power-1)) (derivation base))

reduceHelper (Multiply (Const 1) second) = second
reduceHelper (Multiply first (Const 1)) = first
reduceHelper (Multiply (Const 0) _) = Const 0
reduceHelper (Multiply _ (Const 0)) = Const 0
reduceHelper (Add (Const 0) second) = second
reduceHelper (Add first (Const 0)) = first
reduceHelper (Subtract first (Const 0)) = first
reduceHelper (Subtract (Const 0) (Const x)) = Const (-x)
reduceHelper (Subtract first (Const x)) | x < 0 = Add first (Const (-x))
reduceHelper (Divide first (Const 1)) = first
reduceHelper (Power _ 0) = Const 1
reduceHelper (Power base 1) = base
reduceHelper (Power (Const 0) _) = Const 0
reduceHelper (Power (Const 1) _) = Const 1
reduceHelper other = other

reduce (Add first second) = reduceHelper (Add (reduce first) (reduce second))
reduce (Subtract first second) = reduceHelper (Subtract (reduce first) (reduce second))
reduce (Multiply first second) = reduceHelper (Multiply (reduce first) (reduce second))
reduce (Divide first second) = reduceHelper (Divide (reduce first) (reduce second))
reduce (Power base power) = reduceHelper (Power (reduce base) power)
reduce other = other
