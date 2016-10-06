#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

//Compute sign of integer
int sign(int n);
bool sign_bool(int n);

//Detect opposite signs of integers
bool opp_sign(int a, int b);

//Abs val of int
unsigned int int_abs(int n);

//Find max/min of two numbers
int max(int a, int b);
int min(int a, int b);

//Is power of 2
bool is_power_of_2(int n);

int main(){
    printf("%d\n", is_power_of_2(1));
    printf("%d\n", is_power_of_2(2));
    printf("%d\n", is_power_of_2(-2));
    return 0;
}

bool is_power_of_2(int n){
     unsigned int x = int_abs(n);
     return x && !(x & (x - 1));
}


int max(int a, int b){
    //also a ^ ((a ^ b) & -(a < b));
    return a > b ? a : b; 
}

int min(int a, int b){
    //also b ^ ((a ^ b) & -(a < b));
    return a < b ? a : b; 
}

unsigned int int_abs(int n){
    return (n < 0) ? - (unsigned) n : n;
}

bool opp_sign(int a, int b){
    // in a signed int, the top digit must be 1 if neg
    return ((a ^ b ) < 0);
}

int sign(int n){
    return (-(n < 0));
}

bool sign_bool(int n){
    return (n > 0);
}
