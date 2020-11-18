extern crate clap;
use clap::{Arg, App};

fn main() {
    let matches = App::new("Smol Clap Positional Argument Test App Pogomega")
                    .version("0.1.0")
                    .author("Oleksii Kshenskyi <archalessus@gmail.com>")
                    .about("A simple test app to figure out how positional arguments work in Clap.")
                        .arg(Arg::with_name("first_arg")
                            .required(true)
                            .help("The first argument!")
                        )
                        .arg(Arg::with_name("second_arg")
                            .required(true)
                            .help("The second argument!")
                        )
                    .get_matches();

    let mut first_arg = "";
    if matches.is_present("first_arg") {
        first_arg = matches.value_of("first_arg").unwrap();
    }

    let mut second_arg = "";
    if matches.is_present("second_arg") {
        second_arg = matches.value_of("second_arg").unwrap();
    }

    println!("First arg is [{}]!\nSecond arg is [{}]!\n", first_arg, second_arg);
}
