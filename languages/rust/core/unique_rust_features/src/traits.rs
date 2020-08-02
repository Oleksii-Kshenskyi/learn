pub struct Nums {
   num1: i32,
   num2: i32,
   num3: i32,
}

impl Nums {
   pub fn new(first: i32, second: i32, third: i32) -> Nums {
      Nums { num1: first, num2: second, num3: third }
   }
}

pub trait Sum {
   fn add_them_up(&self) -> i64;
}

impl Sum for Nums {
   fn add_them_up(&self) -> i64 {
      (self.num1 + self.num2 + self.num3) as i64
   }
}