// fn sum_of_nth_sums()

fn sum_of_nth_sums(original_vec: &Vec<i64>) -> i64 {
    /*let mut sums: Vec<i64> = Vec::new();
    for (index, _item) in original_vec.iter().enumerate()
    {
        sums.push(nth_sum_of_vec(original_vec, index + 1));
    }
    sums.iter().sum()*/
    original_vec
        .iter()
        .enumerate()
        .map(|(index, _element)| original_vec[..index + 1].iter().sum::<i64>())
        .sum()
}

/*fn nth_sum_of_vec(vec: &Vec<i64>, n: usize) -> i64
{
    // println!("Here is your vec: {:?}", vec);
    /*let the_sum: i64 = */ // vec[..n].iter().sum()
    // the_sum
}*/

fn main() {
    // let a: [u32; 2] = [3, 4];
    let v: Vec<i64> = vec![11, 11, 11, 11];
    // fn sum_of_nth_sums()

    // let the_sum: i64 = nth_sum_of_vec(&v, 5);
    println!("the_sum = {}", sum_of_nth_sums(&v));
}
