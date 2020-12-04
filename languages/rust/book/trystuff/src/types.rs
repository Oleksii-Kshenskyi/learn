pub fn try_numeral_systems()
{
    println!("This is FA in HEX: {}", 0xFA);
    println!("This is AF in HEX: {}", 0xAF);
    println!("This is 75 in OCT: {}", 0o77);
    println!("This is 1010 1111 in BIN: {}", 0b1010_1111);
}

pub fn type_of<T>(_: &T) -> &str {
    std::any::type_name::<T>()
}

pub fn try_scalars()
{
    let i = 355;
    let f = 2.0;
    println!("'let i = 355;' defaults to {:?}", type_of(&i));
    println!("'let f = 2.0;' defaults to {:?}", type_of(&f));

    let ch1 = '1';
    let ch2 = '{';
    let chu = 'の';
    let chk = '女';
    println!("'1' as char is {}", ch1);
    println!("'{{' as char is {}", ch2);
    println!("Hiragana 'の' as char is {}", chu);
    println!("Kanji '女' as char is {}", chk);
}

pub fn try_tuples()
{
    let t1 = (1, 2.5, 'k', "kek");
    println!("A basic tuple looks like this: {:?}", t1);

    println!("You can get tuple's i-th element like so: t1.i = {:?}", t1.3);
    let (i, f, c, s) = t1;
    println!("You can destructurize a tuple with pattern matching: 'let (i, f, c, s) = t1;'");
    println!("int = {}, float = {}, char = {}, str = {}", i, f, c, s);
}

pub fn try_arrays()
{
    let a1 = [1, 2, 3, 4, 5];
    println!("A basic array looks like this: {:?}", a1);

    let a2: [i32; 5] = [1, 2, 3, 4, 5];
    println!("You can type annotate arrays like this: 'let a2: [i32; 5]' => {:?}", a2);

    let a3 = [69; 5];
    println!("You can populate arrays like this: 'let a3 = [69; 5];' => {:?}", a3);

    println!("You can access i-th element of an array: 'a[i]' => a1[2] = {}", a1[2]);

    let a4 = [1, 2, 3];
    let [a40, a41, a42] = a4;
    println!("You can destructurize arrays: 'let a4 = [1, 2, 3]; let [a40, a41, a42] = a4;'");
    println!("a40 = {}, a41 = {}, a42 = {}", a40, a41, a42);
}

pub fn five() -> i32
{
    5
}

pub fn let_expr()
{
    let x = {
        let y = 5;
        y + 5
    };

    println!("x as a result of a multiline {{}} expression is {}", x);
}

pub fn nuthin()
{
    {}
}

pub fn try_return_values()
{
    println!("five returned {}", five());
    let_expr();
    println!("nuthin() returns {:?}", nuthin());
    println!("are () and {{}} the same? ==> {}", () == {});
}

pub fn run()
{
    println!("=======TYPES TEST==========");
    try_numeral_systems();
    println!("\n================\n");
    try_scalars();
    println!("\n================\n");
    try_tuples();
    println!("\n================\n");
    try_arrays();
    println!("\n================\n");
    try_return_values();
    println!("=======END TYPES TEST======");
    println!("\n\n");
}