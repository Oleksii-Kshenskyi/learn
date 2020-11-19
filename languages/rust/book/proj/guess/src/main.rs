extern crate rand;
use rand::Rng;

use std::io::Write;
use std::io;

fn main() {
    println!("Guess the number I'm thinking of! The number is between 1 and 100.");
    print!("What's your guess? Put it here ==> ");
    io::stdout().flush().unwrap();

    let secret_number = rand::thread_rng().gen_range(1, 101);

    let mut guess = String::new();
    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read your guess...");

    println!("I'm thinking of this: [{:?}]", secret_number);
    println!("This is what you guessed: [{:?}]", guess);
}
