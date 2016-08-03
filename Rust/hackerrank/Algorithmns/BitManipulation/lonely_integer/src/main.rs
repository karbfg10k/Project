use std::io;
use std::collections::HashMap;

fn main() {
    let _n: u32 = read_one_line().
        trim().parse().unwrap();
    let in_vec: Vec<i32> = read_one_line()
                 .split_whitespace()
                 .map(|s| s.parse().unwrap())
                 .collect();
    println!("{}", find_lonely_int(in_vec)); 
    return;
}

fn find_lonely_int(vec: Vec<i32>) -> i32{
    let mut map = HashMap::new();
    let mut out = 0;
    for i in vec{
        let ctr = map.entry(i).or_insert(0);
        *ctr += 1;
    }
    for (key, val) in map.iter() {
        if *val == 1{
            out = *key;
            break;
        }
    }
    out
}

fn read_one_line() -> String{
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read");
    input
}
