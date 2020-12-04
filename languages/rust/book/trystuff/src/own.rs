pub fn start()
{
   println!("====START OWNERSHIP TEST====");
}

pub fn sep()
{
   println!("============================");
}

pub fn end()
{
   println!("=====END OWNERSHIP TEST=====");
}

pub fn simple_strings()
{
   let s = "huhlo";
   // s.push("kek"); // can't push into a string literal, error
   println!("{}", s.chars().nth(2).expect("Kaboom")); // can get an nth char though
   let mut sm = String::from("huhlo"); // mutable
   println!("freshly created string: {}", sm);
   sm.push_str(" kekw");
   println!("^^ same string, but appended: {}", sm);
}

pub fn simple_string_clone()
{
   let s1 = String::from("Huhlo im string one pog");
   let s2 = s1;
   println!("s2: {}", s2); // try to print s1 here and you get a compile time error pog
                           // the reason is that you're trying to use a moved value
   // now explicitly clone s2 into s1 so they're both valid
   let s1 = s2.clone();
   println!("Both valid now! s1: [{}], s2: [{}]", s1, s2);
}

pub fn string_accepter(gimme: String)
{
   println!("Accepted a string: [{}]", gimme);
}

pub fn check_passing_arguments_to_functions()
{
   println!("Declaring a string...");
   let s1 = String::from("Going into a fuction, yay!");
   println!("Declared. The string is: [{}]", s1);
   println!("Passing the string into a function...");
   string_accepter(s1);
   //println!("s1 still available in the calling function WTF?! {}", s1); // this should be a compiler error
   // And it is FeelsOkayMan
   // this is because by the time println! is called, s1 has been already moved into string_accepter()
}

pub fn run()
{
   start();

   simple_strings();
   
   sep();

   simple_string_clone();

   sep();

   check_passing_arguments_to_functions();

   end();
}