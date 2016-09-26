#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

//Reduces fractions -> example {12/15, 1000/1000} becomes {4/5, 1/1} 
void reduce_fractions(char** arr, int* str_size); 

int main(){
    char *arr[] = {"12/15" ,"123/456", "1000/1000" };
    int* str_size = 3;
    reduce_fractions(&arr, &str_size); 
    for (int i = 0; i < str_size; i++)
        printf("Tok:%s\n", arr[i]);
    return 0;
}
int find_gcd(int a, int b){
    while(a != b){
        if ( a > b)
            a -= b;
        else
            b -= a;
    }
    return a;

}
void reduce_fractions(char** arr, int* str_size){
    const char* s = "/";
    const char* s2 = "\0";
    for (int i = 0; i < *str_size; i++){
        char* str = strdup(*arr); 
        char* tok = strtok(str, s);
        int a = atoi(tok);
        tok = strtok(NULL, s2 );
        int b = atoi(tok);
        int gcd = find_gcd(a, b);
        a /= gcd;
        b /= gcd;
        char* tmp[20], tmp2[20];
        snprintf(tmp, 9, "%d", a);
        strcat(tmp, "/");
        snprintf(tmp2, 9, "%d", b);
        strcat(tmp, tmp2);
        *arr = strdup(tmp);
        arr++;
    }
}
