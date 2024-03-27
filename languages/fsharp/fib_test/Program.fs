let rec fib n = match n with
                | 0 -> 0
                | 1 -> 1
                | n -> fib (n - 1) + fib (n - 2)

printfn $"F# fib {42} is {fib 42}"
