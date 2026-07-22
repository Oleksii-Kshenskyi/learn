use std::result::Result;

fn throws_err(myint: i32) -> Result<i32, String> {
    if myint >=0 && myint <= 50 {
        Ok(myint)
    } else {
        Err(format!("Number {} is not between 0 and 50!", myint))
    }
}

fn main() {
    match throws_err(51) {
        Ok(value) => println!("OK: {}", value),
        Err(err) => println!("ERR: {}", err),
    }
}