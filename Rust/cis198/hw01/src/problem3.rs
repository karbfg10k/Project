/// Find all prime numbers less than `n`.
/// For example, `sieve(7)` should return `[2, 3, 5]`
pub fn sieve(n: u32) -> Vec<u32> {
    //Check assert and then populate vector
    assert!(n > 1, "Error n is less than 1");
    let mut is_prime: Vec<bool> = vec![true; (n-1) as usize];
    let sqrt: u32 = (n as f32).sqrt() as u32 + 1;
    for i in 2..sqrt{
        if is_prime[i as usize] == true{
            let mut k = i*i;
            loop{
                if k > n{
                    break;
                }
                is_prime[(k-2) as usize] = false;
                k += i;
                println!("i:{} k:{}", i, n);
            }
        }
    }
    let mut primes: Vec<u32> = Vec::new();
    for i in 0..is_prime.len(){
        if is_prime[i] == true{
            primes.push((i+2) as u32 );
        }
    }
    println!("SQ{}", sqrt);
    println!("Vec {:?}", primes);
    primes
}
