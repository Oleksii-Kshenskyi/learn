use std::env;

fn main() {
    let myargs: Vec<String> = env::args().collect::<Vec<_>>();
    let num = myargs.get(1).unwrap().parse::<i64>().unwrap();

    println!(
        "The num: {}",
        (0..num).map(|x| x * 2).filter(|x| x % 2 == 0).sum::<i64>()
    );
}
