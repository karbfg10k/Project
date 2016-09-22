use std::io;

fn main() {
    let n: u32 = read_one_line().
        trim().parse().unwrap();
    for _i in 0..n{
        let _vec_size: usize = read_one_line().
            trim().parse().unwrap();
        let vec: Vec<usize> = read_one_line()
                 .split_whitespace()
                 .map(|s| s.parse().unwrap())
                 .collect();
        println!("{}", find_sansa_xor(vec));
    }
    return;
}

fn find_sansa_xor(vec: Vec<usize>) -> u64{
    let mut s_xor = 0;
    for i in 0..vec.len(){
       if (i + 1) % 2 == 1 && (vec.len() - i) % 2 == 1{
           s_xor ^= vec[i];
       } 
    }
    s_xor as u64
}

fn read_one_line() -> String{
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read");
    input
}


