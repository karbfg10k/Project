#![cfg(test)]

use problem1::{sum, dedup, filter};

//
// Problem 1
//

// Part 1

#[test]
fn test_sum_small() {
    let array = [1,2,3,4,5];
    assert_eq!(sum(&array), 15);
}

// Part 2

#[test]
fn test_dedup_small() {
    let vs = vec![1,2,2,3,4,1];
    assert_eq!(dedup(&vs), vec![1,2,3,4]);
}

// Part 3

fn even_predicate(x: i32) -> bool {
    (x % 2) == 0
}

#[test]
fn test_filter_small() {
    let vs = vec![1,2,3,4,5];
    assert_eq!(filter(&vs, &even_predicate), vec![2,4]);
}

