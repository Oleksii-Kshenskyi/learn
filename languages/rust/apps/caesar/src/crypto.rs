use crate::Medium;

pub fn encrypt(medium: Medium) {
   let content = medium.serve_content();
   let key: u32 = 3;
   let the_codes = content.chars().enumerate().map(|(_thesize, thechar)| (thechar as u32) + key).collect::<Vec<u32>>();
   let the_chars: String = the_codes.iter().map(|code| std::char::from_u32(*code).unwrap()).collect();
   medium.dump_result(the_chars);
}

pub fn decrypt(medium: Medium) {
   let content = medium.serve_content();
   let key: u32 = 3;
   let the_codes = content.chars().enumerate().map(|(_thesize, thechar)| (thechar as u32) - key).collect::<Vec<u32>>();
   let the_chars: String = the_codes.iter().map(|code| std::char::from_u32(*code).unwrap()).collect();
   medium.dump_result(the_chars);
}