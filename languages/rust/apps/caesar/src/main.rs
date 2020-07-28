extern crate clap;
use clap::{Arg, App};

fn main() {
    let matches = App::new("Smol Caesar Cipher App")
                    .version("0.1.0")
                    .author("Oleksii Kshenskyi <archalessus@gmail.com>")
                    .about("A simple test app that can encrypt and decrypt files and text messages with the Caesar cipher.")
                        .arg(Arg::with_name("use-file")
                            .short("f")
                            .required(false)
                            .long("use-file")
                            .value_name("FILE_NAME")
                            .help("If specified, encryption and decryption are performed on a file. The value of this argument is the a path to the file being encrypted/decrypted.")
                        )
                        .arg(Arg::with_name("use-command-line")
                            .short("c")
                            .long("use-command-line")
                            .required(false)
                            .value_name("TEXT_TO_ENCRYPT")
                            .conflicts_with("use-file")
                            .help("If specified, encryption and decryption are performed on the value of this argument.")
                    ).get_matches();
    if matches.is_present("use-file") {
        println!("KEKW FILE");
    }
    if matches.is_present("use-command-line") {
        println!("KEKW COMMAND LINE");
    }
                            
}
