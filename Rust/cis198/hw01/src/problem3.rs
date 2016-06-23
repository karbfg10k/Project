/// Find all prime numbers less than `n`.
/// For example, `sieve(7)` should return `[2, 3, 5]`
pub fn sieve(n: u32) -> Vec<u32> {
    // Check assert and then populate vector
    //     assert!(n > 1, "Error n is less than 1");
    let mut is_prime = vec![true; (n-2) as usize];
    let sqrt = (n as f32).sqrt() as u32 + 1;
    for i in 2..sqrt {
        if is_prime[(i-2) as usize] {
            let mut k = i*i;
            loop {
                if k >= n {
                    break;
                }
                is_prime[(k-2) as usize] = false;
                k += i;
            }
        }
    }
    let mut primes = Vec::new();
    for i in 0..is_prime.len() {
        if is_prime[i] {
            primes.push((i+2) as u32);
        }
    }
    primes
}
