fn fib(n: u64) -> u64 {
    if n == 0 || n == 1 { n } else { fib(n - 1) + fib (n - 2)}
}

fn main() {
    let n: u64 = 42;
    println!("Fib {}: {}", n , fib(n));
}
