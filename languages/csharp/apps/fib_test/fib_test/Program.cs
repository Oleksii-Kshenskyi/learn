UInt64 n = 42;
Console.WriteLine($"Fib {n} is {fib(n)}");

static UInt64 fib(UInt64 n) {
    if ((n == 0) || (n == 1)) { return n; } else return (fib(n - 1) + fib(n - 2));
}
