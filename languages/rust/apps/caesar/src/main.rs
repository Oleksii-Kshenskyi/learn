extern crate clap;
use clap::{Arg, ArgGroup, App};

mod caesar;
use caesar::*;

fn main() {
    let matches = App::new("Smol Caesar Cipher App")
                    .version("0.1.0")
                    .author("Oleksii Kshenskyi <archalessus@gmail.com>")
                    .about("A simple test app that can encrypt and decrypt files and text messages with the Caesar cipher.")
                        .arg(Arg::with_name("use-file")
                            .short("f")
                            .long("use-file")
                            .value_name("FILE_NAME")
                            .help("If specified, encryption and decryption are performed on a file. The value of this argument is the a path to the file being encrypted/decrypted.")
                        )
                        .arg(Arg::with_name("use-command-line")
                            .short("c")
                            .long("use-command-line")
                            .value_name("TEXT_TO_ENCRYPT")
                            .help("If specified, encryption and decryption are performed on the value of this argument.")
                        )
                        .arg(Arg::with_name("encrypt")
                            .short("e")
                            .long("encrypt")
                            .takes_value(false)
                            .help("If specified, the application encrypts the text specified in the <-c|-f> option's value.")
                        )
                        .arg(Arg::with_name("decrypt")
                            .short("d")
                            .long("decrypt")
                            .takes_value(false)
                            .help("If specified, the application decrypts the text specified in the <-c|-f> option's value.")
                        ).group(ArgGroup::with_name("text-medium")
                            .args(&["use-file", "use-command-line"])
                            .required(true)
                            .multiple(false)
                        ).group(ArgGroup::with_name("application-mode")
                            .args(&["encrypt", "decrypt"])
                            .required(true)
                            .multiple(false)
                    ).get_matches();

    let mut medium_type = "";
    if matches.is_present("use-file") {
        println!("FILE KEKW");
        medium_type = "use-file";
    }
    if matches.is_present("use-command-line") {
        println!("CLI KEKW");
        medium_type = "use-command-line";
    }

    if matches.is_present("encrypt") {
        encrypt(matches.value_of(medium_type).unwrap());
    }
    if matches.is_present("decrypt") {
        decrypt(matches.value_of(medium_type).unwrap());
    }
}
