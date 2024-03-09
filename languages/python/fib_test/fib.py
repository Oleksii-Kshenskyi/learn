def fib(n: int) -> int:
    if n == 0 or n == 1:
        return n
    else:
        return fib(n - 1) + fib(n - 2)

if __name__ == "__main__":
    n = 42
    print(f"Fib {n} is { fib(n)} ")