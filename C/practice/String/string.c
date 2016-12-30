#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
//reverses word
void reverse_word(char* word, int len);

//Reverses words in a string
char* reverser(char *sentence);

int main(){
    char* str = "Hi lets do this";
    char* ret = reverser(str);
    printf("Org:%s|%d\n", str, (int)strlen(str));
    printf("Rev:%s|%d\n", ret, (int)strlen(ret));
    free(ret);
    return 0;
}
//reverses word
void reverse_word(char* word, int len){
    for(int i = 0; i< (int)len/2; i++){
        char temp = word[i];
        word[i] = word[len - i - 1];
        word[len - i - 1] = temp;
    }
}

//Reverses words in a string
char* reverser(char *sentence) {
    int str_size = strlen(sentence);
    char sentence_copy[str_size];
    strcpy(sentence_copy, sentence);
    char* ret_str = (char*)calloc(str_size, sizeof(char));
    const char s[2] = " ";
    char* tok = strtok(sentence_copy, s);
    if (!tok)
        strcpy(ret_str, sentence_copy);
    while(tok){
        int tok_len = strlen(tok);
        reverse_word(tok, tok_len);
        strncat(ret_str, tok, tok_len);
        if(tok)
            strcat(ret_str, s);
        tok = strtok(NULL, s);
    }
    return ret_str;
}
