import Data.Maybe
import Data.List

-- быдлокоооооооооод

data Graph v e = Graph [(Int,v)] [(Int,Int,e)]

dijkstra :: (Fractional a, Eq a, Ord a) => Graph v a -> Int -> [(Int, Maybe a, Int)] 
                                                         -- принимает граф и номер начальной вершины
                                                         -- возвращает список троек: номер вершины, 
                                                         -- расстояние от начальной вершины
                                                         -- предыдущая вершина в пути от начала
dijkstra (Graph vs es) src = reform $ helper (map (\x -> (fst x, if fst x == src then 0 else 1/0, fst x)) vs) []
    where helper [] result = result
          helper nonVisited visited = if distance minNonVisited == 1/0
                                          then nonVisited ++ visited
                                          else helper (map relax $ filter (/= minNonVisited) nonVisited) (minNonVisited:visited)
              where minNonVisited = foldr (\f@(_,x,_) s@(_,y,_) -> if x < y then f else s) (head nonVisited) (tail nonVisited)
                    distance (_,x,_) = x
                    relax v@(num, dist, prev) = case findEdge num minNonVisitedNum of
                                                    Nothing -> v
                                                    Just (_,_,d) -> if distance minNonVisited + d < dist
                                                                        then (num, distance minNonVisited + d, minNonVisitedNum)
                                                                        else v
                        where minNonVisitedNum = case minNonVisited of (x,_,_) -> x
                              findEdge first second = find (\(x,y,_) -> x == first && y == second
                                                                     || x == second && y == first) es
          reform = map (\(a,x,b) -> (a, if x == 1/0 then Nothing else Just x, b))

