/// Computes the sum of all elements in the input i32 slice named `slice`
pub fn sum(slice: &[i32]) -> i32 {
    let mut sum: i32 = 0;
    for n in slice{
        sum = sum + n;
    }
    sum
}
/// Deduplicates items in the input vector `vs`. Produces a vector containing
/// the first instance of each distinct element of `vs`, preserving the
/// original order.
pub fn dedup(vs: &Vec<i32>) -> Vec<i32> {
    let mut vec = Vec::new();
    // More efficent, old implementation is shitty
    for i in vs{
        if !vec.contains(i){
            vec.push(*i)
        }
    }
    /*
    for i in vs{
        if vec.is_empty(){
            vec.push(*i);
        }
        else{
            let mut k = 0;
            for j in 0..vec.len(){
                if vec[j] == *i{
                    k = k +1;
                }
            }
            if k == 0{
                vec.push(*i);
            }
        }
    }*/
    vec
}

/// Filters a vector `vs` using a predicate `pred` (a function from `i32` to
/// `bool`). Returns a new vector containing only elements that satisfy `pred`.
pub fn filter(vs: &Vec<i32>, pred: &Fn(i32) -> bool) -> Vec<i32> {
    let mut vec = Vec::new();
    for i in vs{
        if pred(*i){
            vec.push(*i)
        }  
    }
    vec
}
