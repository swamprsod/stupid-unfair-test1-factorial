module Fact

fact : Integer -> Integer
fact 0 = 1
fact i=i * fact(i - 1)

main : IO ()
main=putStrLn (show(fact 20))
