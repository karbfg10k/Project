use std::io;

fn main() {
    let n: usize = read_one_line().trim()
                .parse::<usize>().unwrap();
    let mut out_vec = vec![0; n];
    for i in 0..n{
        let in_vec: Vec<i64> = read_one_line()
                 .split_whitespace()
                 .map(|s| s.parse().unwrap())
                 .collect();
        out_vec[i] = bitwise_and(in_vec); 
    }
    for i in 0..n{
        println!("{}", out_vec[i]);
    }
}

fn read_one_line() -> String{
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("Failed to read");
    line
}

fn bitwise_and(vec: Vec<i64>) -> i64{
    let mut res = vec[0];
    for i in vec[0]..vec[1]{
        res = res & i;
    }
    res
}
