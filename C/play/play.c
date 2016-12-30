#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

uint64_t payload_nibble_swap(uint64_t p)
{
    uint64_t nibbleSwappedVal = 0;
    for(int i = 0 ; i < 8; i++){
        uint64_t byte = (p >> (i*8))  & 0xFF ;
        uint64_t swap = ((byte & 0x0F) << 4) | ((byte & 0xF0) >> 4) ;
        nibbleSwappedVal |= swap << (i * 8) ;
    }
    return nibbleSwappedVal;
}

int main() {
    printf("%lx\n", payload_nibble_swap(0x12345678DEADBEEF)); 
    return 0;
}

