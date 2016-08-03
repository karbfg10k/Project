use std::io;

fn main() {
    let in_1: u32 = read_one_line().
        trim().parse().unwrap();
    let in_2: u32 = read_one_line().
        trim().parse().unwrap();

    println!("{}", find_max_xor(in_1, in_2)); 
    return;
}

fn find_max_xor(inp1: u32, inp2: u32) -> u32{
    let mut max_xor = 0;
    for i in inp1..inp2+1{
        for j in inp1..inp2+1{
            if max_xor < i^j{
                max_xor = i^j;
            }
        }
    }
    max_xor
}

fn read_one_line() -> String{
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read");
    input
}

