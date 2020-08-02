mod traits;
use traits::*;

fn main() {
    let nums = Nums::new(1, 55, 44);
    println!("Sum of nums pog: {}!", nums.add_them_up());
}
