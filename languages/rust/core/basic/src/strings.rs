use std::env;

#[allow(dead_code)]

fn filter_out_even_elements_from_cl_arguments()
{
   env::args().collect::<Vec<String>>().iter().enumerate().filter(|(index, _element)|{ index % 2 != 0 }).for_each(|(index, element)| {println!("elem #{}: {};", index, element);});
}

fn how_does_string_work()
{
   // let mut strng = ;
   let mut chars: Vec<char> = "kekerek".chars().collect();
   println!("\n[STATUS] Trying to change two letters in the string...");
   chars[2] = 'b';
   chars[4] = 'b';
   println!("This is your string: [{}]\n", chars.into_iter().collect::<String>());
}

fn main()
{
   how_does_string_work();
   // println!("CL ARGS Pog: {:?}", args);
}