use crate::Medium;

#[derive(PartialEq)]

pub enum ActionType {
   Encrypt,
   Decrypt,
}

pub fn perform_crypto_action(medium: Medium, key: u16, action: ActionType) {
   let content = medium.serve_content();
   let the_codes = content.chars().enumerate().map(|(_thesize, thechar)| if action == ActionType::Encrypt { (thechar as u32) + key as u32 } else { (thechar as u32) - key as u32 } ).collect::<Vec<u32>>();
   let the_chars: String = the_codes.iter().map(|code| std::char::from_u32(*code).unwrap()).collect();
   medium.dump_result(the_chars);
}

pub fn key_from_string(key_str: String) -> u16 {
   if !key_str.chars().all(|ch| ch.is_numeric()) {
      panic!("ERROR: Key has to be a number.");
   }

   let key_num = key_str.parse::<u32>().unwrap();
   if key_num > std::u16::MAX as u32 {
      panic!(format!("The key is too large. Has to be no larger than {}.", std::u16::MAX));
   }

   return key_num as u16;
}