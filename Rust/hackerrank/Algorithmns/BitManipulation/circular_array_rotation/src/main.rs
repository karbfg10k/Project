use std::io;

fn main(){
    let in_vec: Vec<usize> = read_one_line()
                 .split_whitespace()
                 .map(|s| s.parse().unwrap())
                 .collect();
    let n = in_vec[0];                        
    let k = in_vec[1] % n ;
    let q = in_vec[2];
    let vec: Vec<i32>  = read_one_line()
             .split_whitespace()
             .map(|s| s.parse().unwrap())
             .collect();
    for _i in 0..q {
        let temp:usize  = read_one_line()
                 .trim()
                 .parse().unwrap();
        let index: usize = 
            if temp  >= k{
                temp - k
            }else{
                temp - k + n
            };
        println!("{}", vec[index]);
    }
}

fn read_one_line() -> String{
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read");
    input
}

