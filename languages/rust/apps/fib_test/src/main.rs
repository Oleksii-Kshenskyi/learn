// unsigned long long fib(int n) {
//     if (n == 0) return 0;
//     if (n == 1) return 1;

//     unsigned long long prev = 0, curr = 1;
//     for (int i = 2; i <= n; i++) {
//         unsigned long long next = prev + curr;
//         prev = curr;
//         curr = next;
//     }
//     return curr;
// }

fn fib(n: u64) -> u64 {
    match n {
        0..=1 => n,
        _ => {
            let (mut prev, mut curr) = (0 as u64, 1 as u64);
            for _ in 2..=n {
                let next: u64 = prev + curr;
                prev = curr;
                curr = next;
            }

            curr
        },

    }
}

fn main() {
    let n: u64 = 42;
    println!("Fib {}: {}", n , fib(n));
}
