use std::io;

fn main() {
    println!("Guess the number I'm thinking of!");
    println!("What's your guess? Put it here ==> ");

    let mut guess = String::new();
    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read your guess...");

    println!("This is what you guessed: [{:?}]", guess);
}
