use rand::thread_rng;
use rand::seq::SliceRandom;
use itertools::Itertools;
use std::iter::FromIterator;

fn main() {
    let mut rng = thread_rng();
    let mut v: Vec<u32> = (1..20).collect();
    let keke = String::from("AHAHA").chars().collect_vec();
    let skeke = keke.iter().collect::<String>();

    let MONKERS = String::from("ARE YOU FUCKING SHITTING ME?!");
    let mut kek = MONKERS.chars().permutations(MONKERS.chars().count()).take(100).collect_vec();
    let mut pobeda = "abc";
    let graphemesp = unicode_segmentation::UnicodeSegmentation::graphemes(pobeda, true).collect_vec();
    println!("pobeda {:?}", graphemesp);
    let vekek = kek.iter().map(|elem| elem.iter().collect::<String>() ).collect_vec();
    v.shuffle(& mut rng);
    println!("The Vec: {:?}", vekek);
    println!("Num of permutations: {:?}", kek.iter().count());
}
