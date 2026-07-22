use std::time::Instant;

const ITERATIONS: u64 = 2_000_000_000;

fn main() {
    println!("Rust CPU benchmark");
    println!("iterations: {ITERATIONS}");

    let started = Instant::now();
    let checksum = run_benchmark(ITERATIONS);
    let elapsed = started.elapsed();

    let seconds = elapsed.as_secs_f64();
    let million_ops_per_second = ITERATIONS as f64 / seconds / 1_000_000.0;

    println!("checksum: {checksum}");
    println!("elapsed: {:.3} seconds", seconds);
    println!("throughput: {:.2} million iterations/second", million_ops_per_second);
}

fn run_benchmark(iterations: u64) -> u64 {
    let mut value = 0x1234_5678_9abc_def0u64;

    for i in 0..iterations {
        value = value
            .wrapping_mul(6_364_136_223_846_793_005)
            .wrapping_add(i ^ (value >> 32));
        value ^= value.rotate_left(17);
    }

    value
}