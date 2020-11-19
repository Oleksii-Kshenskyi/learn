extern crate rand;
use rand::Rng;

use std::io::Write;
use std::io;
use std::cmp::Ordering;

fn main() {
    println!("Guess the number I'm thinking of! The number is between 1 and 100.");
    print!("What's your guess? Put it here ==> ");
    io::stdout().flush().unwrap();

    let secret_number = rand::thread_rng().gen_range(1, 101);

    let mut guess = String::new();
    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read your guess...");

    match guess.cmp(&secret_number) {
        Ordering::Less => println!("The number I'm thinking of is smaller!"),
        Ordering::Greater => println!("The number I'm thinking of is greater!"),
        Ordering::Equal => println!("Great job! You won, that's exactly the number I'm thinking of!"),
    }
}
