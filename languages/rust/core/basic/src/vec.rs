use std::time::Instant;
use std::collections::VecDeque;

const NUM_ITERS: i32 = 1_000_000;

fn main() {
    let mut vec: VecDeque<i32> = VecDeque::new();

    let start = Instant::now();

    for i in 0..NUM_ITERS {
        vec.insert(0, i);
    }

    let duration = start.elapsed();

    println!("{} ms", duration.as_millis());
    println!("Length of vector: {}", vec.len());
    println!("Last inserted element is {}", vec[0]);
}
