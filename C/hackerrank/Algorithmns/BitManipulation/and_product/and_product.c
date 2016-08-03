#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long bitwise_and(long from, long to);
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    long n;
    scanf("%ld", &n);
    long arr_in[2];
    for(long i = 0 ; i < n; i++){
        scanf("%ld %ld", &arr_in[0], &arr_in[1]);
        printf("%ld\n", bitwise_and(arr_in[0], arr_in[1] ) );
    }
    return 0;
}

long bitwise_and(long from, long to){
    long out = from & to;
    long k = 1;
    long i = from + k;
    while(i < to){
        out = out & i;
        k = k * 2;
        i = i + k;
    } 
    return out;
}

