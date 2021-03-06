module Ex4_4 where

import qualified Data.Set as Set

cartProd :: [a] -> [b] -> [(a, b)]
cartProd xs ys = [(x,y) | x <- xs, y <- ys]
makeList :: [Int]-> [Int]
makeList = \x -> [1..x]

sundExcl :: Int -> [Int]
sundExcl n = (filter (\x->x<n) . map (\(i,j)->i+j+2*i*j) . filter (\(i,j)->i<=j) . \x->cartProd x x) $ makeList n
