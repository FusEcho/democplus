
fn test1(){
    let company_string = "TutorialsPoint";  // string 类型
    let rating_float = 4.5;                 // float 类型
    let is_growing_boolean = true;          // boolean 类型
    let icon_char = '♥';                    //unicode character 类型
 
    println!("company name is:{}",company_string);
    println!("company rating on 5 is:{}",rating_float);
    println!("company is growing :{}",is_growing_boolean);
    println!("company icon is:{}",icon_char);
}

fn test2(){
    let result = 10;    // 默认类型为i32
   let age:u32 = 20;
   let sum:i32 = 5-15;
   let mark:isize = 10;
   let count:usize = 30;
   println!("result value is {}",result);
   println!("sum is {} and age is {}",sum,age);
   println!("mark is {} and count is {}",mark,count);
}

// add --release while compile
// fn test3(){
//     let age:u8 = 255;

//    // u8数据范围为0~255
//    let weight:u8 = 256;   //溢出值为 1
//    let height:u8 = 257;   //溢出值为 2
//    let score:u8 = 258;    //溢出值为 3

//    println!("age is {} ",age);
//    println!("weight is {}",weight);
//    println!("height is {}",height);
//    println!("score is {}",score);
// }

fn test4(){
    let result = 10.00;        //默认为 f64 浮点型
   let interest:f32 = 8.35;
   let cost:f64 = 15000.600;  //双精度浮点型

   println!("result value is {}",result);
   println!("interest is {}",interest);
   println!("cost is {}",cost);
}

fn test5() {
    let float_with_separator = 11_000.555_001;
    println!("float value {}",float_with_separator);
 
    let int_with_separator = 50_000;
    println!("int value {}",int_with_separator);
}

fn test6() {
    let isfun:bool = true;
    println!("Is Rust Programming Fun ? {}",isfun);
}

fn test7() {
    let special_character = '@'; //默认为字符型
    let alphabet:char = 'A';
    let emoji:char = '😁';
 
    println!("special character is {}",special_character);
    println!("alphabet is {}",alphabet);
    println!("emoji is {}",emoji);
}

fn main() {
    println!("======test1======");
    test1();
    println!("======test2======");
    test2();
    println!("======test3======");
    // test3();
    println!("======test4======");
    test4();
    println!("======test5======");
    test5();
    println!("======test6======");
    test6();
    println!("======test7======");
    test7();
}