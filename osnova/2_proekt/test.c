#include <stdio.h>
#include <ctype.h>
#include <string.h>
void *to_upper(char *str){
    size_t len = strlen(str);
    char *str1;
    for(int i=0;i<len;i++){
        if(str[i]>='a' && str[i] <='z'){
            str1[i]= str[i]- ('a' - 'A');
        }else str1[i]= str[i];
    }
    return str1;
}
int main() {
    char word[] = "qwertyuiop1234567";
        to_upper(word);
    printf("rez:   %s\n", word);
    return 0;
}