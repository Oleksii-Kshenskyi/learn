#[derive(Debug)]

pub enum MediumType {
   File,
   CLIArg,
   Whoops,
}

pub struct Medium {
   medium_type: MediumType,
   medium_content: String,
}

impl Medium {
   pub fn new(string_type: &str, content_string: &str) -> Medium {
      Medium { medium_type: match string_type {
         "use-file" => MediumType::File,
         "use-command-line" => MediumType::CLIArg,
         _ => MediumType::Whoops,
      },
      medium_content:  String::from(content_string),
      }
   }

   pub fn serve_content(&self) -> String {
      match self.medium_type {
         MediumType::Whoops => self.serve_whoops(),
         MediumType::File => self.serve_file(),
         MediumType::CLIArg => self.serve_cli_argument(),
      }
   }

   pub fn dump_result(&self, result: String) {
      match self.medium_type {
         MediumType::Whoops => self.dump_into_whoops(),
         MediumType::File => self.dump_into_file(result),
         MediumType::CLIArg => self.dump_into_stdout(result),
      }
   }


   fn serve_cli_argument(&self) -> String {
      return self.medium_content.clone();
   }

   fn serve_whoops(&self) -> String {
      panic!("ERROR: Something went horribly wrong...");
   }

   fn serve_file(&self) -> String {
      let content = std::path::Path::new(self.medium_content.as_str());
      if content.exists() && content.is_file() {
         return std::fs::read_to_string(content).unwrap();
      }
      else {
         panic!("ERROR: This path is Pepega!");
      }
   }

   fn dump_into_whoops(&self) {
      panic!("ERROR: This should have never happened...");
   }

   fn dump_into_stdout(&self, result: String) {
      println!("{}", result);
   }

   fn dump_into_file(&self, result: String) {
      let string_path = &format!("{}{}", self.medium_content, ".result");
      let content_path = std::path::Path::new(string_path);
      std::fs::write(content_path, result).expect("ERROR: unable to write the results to a file.");
   }
}