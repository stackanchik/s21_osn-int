#include <stdio.h>
#include <string.h>

int main() {
    const char *text = "Hello, World!";
    char *found;

    // Поиск символа 'H' в тексте
    found = memchr(text, 'd', strlen(text));

    if (found!= NULL) {
        printf("Found '%c' at position %ld\n", *found, found - text);
    } else {
        printf("'H' not found\n");
    }

    return 0;
}