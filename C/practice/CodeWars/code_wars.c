#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int *split_odd_and_even(int value, size_t *pcount){
    if ( value <= 0){
        *pcount = 0;
        return NULL;
    }
    size_t index = 0; 
    int mul_index = 0;
    int ret[8] = {0, 0, 0, 0, 0, 0, 0, 0}; 
    int n = value;
    int prev = -1 ; // 0 -> even | 1 -> odd | -1 -> initial
    while(n){
        int digit = n % 10;
        if( prev == -1){
            ret[index] = digit;
            prev = digit % 2;
        }
        else if (prev == 0){
            if( digit % 2 == 0)
                ret[index] = (int)pow(10, mul_index++) * digit + ret[index];
            else{
                ret[++index] = digit;  
                mul_index = 0;
            }
            prev = digit % 2;
        }
        else{
            if( digit % 2 == 1)
                ret[index] = (int)pow(10, mul_index++) * digit + ret[index];
            else{
                ret[++index] = digit;  
                mul_index = 0;
            }
            prev = digit % 2;
        }
        n /= 10;
    }
    *pcount = index;
    static int out[8];
    memcpy(out, ret, index);
    for(size_t i = 0 ; i < index; i++)
        printf("%d ", ret[i]);
    printf("\n");
    return out;
}

int main() {
    int value = 123;
    size_t count = 0;

    int *received = split_odd_and_even(value, &count);
    for(size_t i = 0 ; i < count; i++)
        printf("%d ", *received++);
    printf("\n%lu\n", count);
    
  
 /* 
    value = 223;
    count = 0;
    
    expected[] = { 22,3 };
    int *received = split_odd_and_even(value, &count);    
    ASSERT_DYNAMIC_ARRAY_EQUALS(received, count, expected, sizeof(expected)/sizeof(expected[0]));
    
    free(received);
  }
  
  {
    int value = 111;
    size_t count = 0;
    
    int expected[] = { 111 };
    int *received = split_odd_and_even(value, &count);    
    ASSERT_DYNAMIC_ARRAY_EQUALS(received, count, expected, sizeof(expected)/sizeof(expected[0]));
    
    free(received);
  }
  
  {
    int value = 13579;
    size_t count = 0;
    
    int expected[] = { 13579 };
    int *received = split_odd_and_even(value, &count);    
    ASSERT_DYNAMIC_ARRAY_EQUALS(received, count, expected, sizeof(expected)/sizeof(expected[0]));
    
    free(received);
  }
  
  {
    int value = 2468642;
    size_t count = 0;
    
    int expected[] = { 2468642 };
    int *received = split_odd_and_even(value, &count);    
    ASSERT_DYNAMIC_ARRAY_EQUALS(received, count, expected, sizeof(expected)/sizeof(expected[0]));
    
    free(received);
  }
  
  {
    int value = 135246;
    size_t count = 0;
    
    int expected[] = { 135,246 };
    int *received = split_odd_and_even(value, &count);    
    ASSERT_DYNAMIC_ARRAY_EQUALS(received, count, expected, sizeof(expected)/sizeof(expected[0]));
    
    free(received);
  }
  
  {
    int value = 123456;
    size_t count = 0;
    
    int expected[] = { 1,2,3,4,5,6 };
    int *received = split_odd_and_even(value, &count);    
    ASSERT_DYNAMIC_ARRAY_EQUALS(received, count, expected, sizeof(expected)/sizeof(expected[0]));
    
    free(received);
  }
  
  {
    int value = 8123456;
    size_t count = 0;
    
    int expected[] = { 8,1,2,3,4,5,6 };
    int *received = split_odd_and_even(value, &count);    
    ASSERT_DYNAMIC_ARRAY_EQUALS(received, count, expected, sizeof(expected)/sizeof(expected[0]));
    
    free(received);
  }
  
  {
    int value = 82123456;
    size_t count = 0;
    
    int expected[] = { 82,1,2,3,4,5,6 };
    int *received = split_odd_and_even(value, &count);    
    ASSERT_DYNAMIC_ARRAY_EQUALS(received, count, expected, sizeof(expected)/sizeof(expected[0]));
    
    free(received);
  }
  
  {
    int value = 88123456;
    size_t count = 0;
    
    int expected[] = { 88,1,2,3,4,5,6 };
    int *received = split_odd_and_even(value, &count);    
    ASSERT_DYNAMIC_ARRAY_EQUALS(received, count, expected, sizeof(expected)/sizeof(expected[0]));
    
    free(received);
  }*/
    return 0;
}


