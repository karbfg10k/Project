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

//Sign extend unknown width
int sign_extend();

//Conditionally set/clear bits
unsigned int set_clear_bits(unsigned int num, unsigned int mask, bool flag);

//Negate if cond = true
int cond_negate(int num, bool cond);

//Bit set count
unsigned int bitset_count(int n);

//Finds parity of n
bool parity(unsigned int n);

//Swap without temp vars
void num_swap(int* a, int* b);

//Swap bits temp vars
void bit_swap(int* a, int* b);



int main(){
    int a = 1U;
    printf("%d\n", a );
    return 0;
}

//Swap without temp vars
void num_swap(int* a, int* b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

//Finds parity of n
bool parity(unsigned int n){
    bool parity = false;
    while (n){
        parity = ! parity;
        n &= n - 1;
    }
    return parity;
}

//Bit set count
unsigned int bitset_count(int n){
    unsigned int ctr = 0;
    for(ctr = 0; n; ctr++)
        n &= n - 1;
    return ctr; 
}

//Negate if cond = true
int cond_negate(int num, bool cond){
    cond = !cond;
    return (cond ^ (cond - 1)) * num;
}

unsigned int set_clear_bits(unsigned int num, unsigned int mask, bool flag){
    return ( ( num & ~mask ) | ( -flag & mask ) );
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
