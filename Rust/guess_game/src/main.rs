extern crate rand;

use std::io;
use std::cmp::Ordering;
use rand::Rng;

fn main() {
    println!("Enter your guess!");
    

    let sec_number = rand::thread_rng().gen_range(1,5);
    loop{
        let mut guess = String::new(); //immutable 

        io::stdin().read_line(&mut guess).expect("Failed to read");
        
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_)  => continue,
        };  
    
        match guess.cmp(&sec_number) {
            Ordering::Less    => println!("Small"),
            Ordering::Greater => println!("Big"),
            Ordering::Equal   => {
                println!("Perfect!");
                break;
            }
        }
    }
}
