use std::io;

fn main() {
    let n: usize = read_one_line().
        trim().parse().unwrap();
    for _i in 0..n{
        let inp: u64 = read_one_line().
            trim().parse().unwrap();
        println!("{:?}", find_winner(inp)); 
    }
    return;
}

fn find_winner(mut n: u64) -> String{
    
    let win = 
        if n > 0 {
            n.count_ones() + n.trailing_zeros() - 1
        } else {
            0
        };
    let winner = 
        if win % 2 == 0{
            String::from("Richard")
        } else{
            String::from("Louise")
        };
    winner
}

fn read_one_line() -> String{
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read");
    input
}
