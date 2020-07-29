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


   fn serve_cli_argument(&self) -> String {
      return self.medium_content.clone();
   }

   fn serve_whoops(&self) -> String {
      return String::from("ERROR: Something went horribly wrong...");
   }

   fn serve_file(&self) -> String {
      let content = std::path::Path::new(self.medium_content.as_str());
      if content.exists() && content.is_file() {
         return String::from("ALL GREEN!");
      }
      else {
         return String::from("ERROR: This path is Pepega!");
      }
   }
}