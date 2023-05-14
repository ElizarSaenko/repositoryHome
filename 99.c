#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

void add_spaces(char* s){
    char* p = s;
    while(*p){
        if(*p == '+' || *p == '-'){
            *(p-1) = ' ';
            *p++ = *p;
            *p++ = ' ';
        }
        else{
            ++p;
        }
    }
}

int main(void){
    char s[128];
    setlocale(LC_ALL, "Russia");

    fgets(s, sizeof(s), stdin);
    add_spaces(s);
    printf("modified string: %s\n", s);
    return 0;
}
