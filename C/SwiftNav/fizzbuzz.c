#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

void fib_fizzbuzz(uint32_t n);

bool check_prime(uint32_t n);


//  Tests if number is prime 

bool check_prime(uint32_t n){
    if(n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;
    else{
        for(uint32_t i = 5 ; i < floor(sqrt(n)); i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }
    return false;
}

/*  Generates fibonacci series using 1, 1 as initial values
 *  Uses check_prime for prime test
 */

void fib_fizzbuzz(uint32_t n){
    uint32_t f0 = 1;
    uint32_t f1 = 1;
    uint32_t fn;
    bool is_prime = false;
    for(uint32_t i = 0; i < n; i++){
        if(i <= 1)
            fn = f0;
        else{
            fn = f0 + f1;
            f0 = f1;
            f1 = fn;
        }
        is_prime = check_prime(fn);
        
        if( is_prime )
            printf("BuzzFizz");
        else if( fn % 15 == 0)
            printf("FizzBuzz");
        else if( fn % 5 == 0)
            printf("Fizz");
        else if( fn % 3 == 0)
            printf("Buzz");
        else
            printf("%u", fn);
        
        if( i + 1 !=  n)
            printf(", ");
    }
    printf("\n");
}

// Main, just validates input
int main(int argc, char** argv){
    if(argc <= 1)
        printf("Usage:./fizzbuzz 'n'\n");
    else{
        int n = atoi(argv[1]);
        if (n <= 0)
            printf("n must be a positive number up to INT_MAX\n");
        else
            fib_fizzbuzz((uint32_t)n);
    }
    return 0;
}
