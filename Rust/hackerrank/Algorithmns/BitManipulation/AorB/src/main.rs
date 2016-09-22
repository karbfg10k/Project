use std::io;
use std::u64;

fn main(){
    let n = read_one_line().trim()
                 .parse().unwrap();
    
    for _i in 0..n{
        let k: u32  = read_one_line().trim()
                    .parse().unwrap();

        let mut inp = read_one_line();
        let a = u64::from_str_radix(&inp.trim(), 16).unwrap();

        inp = read_one_line();
        let b = u64::from_str_radix(&inp.trim(), 16).unwrap();

        inp = read_one_line();
        let c = u64::from_str_radix(&inp.trim(), 16).unwrap();
        
        calc_a_or_b(k, a, b, c);
    }
}

fn calc_a_or_b(k: u32, a: u64, b: u64, c: u64){
   let mut amask = a & !c; 
   let mut bmask = b & !c;
    
   if amask.count_ones() + bmask.count_ones() > k {
        println!("-1");
        return;
   }

   let mut temp_mask = c & ( (a ^ amask) | (b ^ bmask) ) ;
   
   if temp_mask.count_ones() > k {
        println!("-1");
        return;
   }

   amask = amask | temp_mask;

   temp_mask = (a ^ amask) | (! (b ^ bmask));
    
   amask = amask ^ temp_mask; 
   bmask = bmask ^ temp_mask;  
   
   println!("A:{}, B:{}", amask as u32, bmask as u32);
}

fn read_one_line() -> String{
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read");
    input
}


