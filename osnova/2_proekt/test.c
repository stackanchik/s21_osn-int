#include <stdio.h>
#include <ctype.h>
char *strpbrk(const char *str1, const char *str2) {
    const char *ptr1 = str1;
    const char *ptr2 = str2;
    bool found = false;
    while (*ptr1) {
        if (*ptr1 == *ptr2) {
            found = true;
            break;
        }
        ptr2++; 
        if (*ptr2 == '\0') {
            ptr1++;
        }
    }
    if (found) {
        return (char *)ptr1;
    }
    return NULL;
}

int main() {
    const char *s = "Hello, World!";
    const char *accept = "oW";

    char *result = strpbrk(s, accept);

    if (result) {
        printf("Found '%c' at position %ld\n", *result, result - s);
    } else {
        printf("No match found.\n");
    }

    return 0;
}