extern crate rand;
use rand::Rng;
use std::{io,process,str};

fn input_check(s: &str, size: u32) -> bool{
    //Check if number is positive valid number
    let mut res = true;
    let guess_num: u64 = match s.trim().parse() {
        Ok(num) => num,
        Err(_)  => {
            println!("Guess is not a valid ");
            res = false;
            return res;
        }
    };
    //Check if the number contains unique numbers and it has the right number of characters
    let unique_check: Vec<char> = s.chars().collect();
    let mut t = unique_check.clone();
    t.dedup();
    if t.len() != unique_check.len() {
        println!("Guess must have unique characters ");
        res = false;
        return res;
    }
    if t.len() != size as usize {
        println!("Guess is not of correct size ");
        res = false;
        return res;
    }
    res
}
fn main() {
    //Main game loop
    loop{
        let mut secret_num_seed: Vec<_>= (48..58).collect();
        let mut rng = rand::thread_rng();
        rng.shuffle(&mut secret_num_seed);
        let mut in_size = String::new();
        println!("Enter the number digit for the Secret number");
        io::stdin().read_line(&mut in_size).expect("Failed to read");
        let size: u32 = match in_size.trim().parse() {
            Ok(num) => num,
            Err(_)  => {
                println!("Enter a number please");
                continue;
            }
        };
        if size < 1 || size > 10 {
            println!("Enter a number between 1 and 10");
            continue;
        }
        let mut secret_num = str::from_utf8(&mut secret_num_seed[0..size as usize]).unwrap();
        println!("{:?}", secret_num);
        println!("Secret number generated, let the games begin!");
        let mut guess = String::new();
        loop{
            let (mut bulls, mut cows) = (0, 0);
            println!("Enter your guess");
            guess = String::new();
            io::stdin().read_line(&mut guess).expect("Failed to read");
            match input_check(&mut guess.trim(), size){
                true  => (),
                false => continue
            }
            for (i, j)  in guess.chars().zip( secret_num.chars() ){
                if i == j{
                    bulls += 1;
                }
                else if secret_num.contains(i){
                    cows += 1;
                }
            }
            
            if bulls == size{
                println!("Congrats, you've won!, The number is: {} \nWould you like to play again Y?", secret_num);
                let mut op_in = String::new();
                io::stdin().read_line(&mut op_in).expect("Failed to read");
                if op_in.trim() == "Y"{
                    break;
                }
                else{
                	println!("See you next time");
                    process::exit(0);
                }
            }
            println!("Bulls: {}, Cows: {}", bulls, cows);
        }
    }
}
