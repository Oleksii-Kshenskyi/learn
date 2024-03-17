fn so_and_count(n: u32) {
    println!("{}th recursion happening!", n);
    so_and_count(n + 1);
}

fn main() {
    so_and_count(1);
}
