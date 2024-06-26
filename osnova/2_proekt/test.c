#include <stdio.h>
#include <string.h>

// Функция my_strtok с дополнительными параметрами
char *my_strtok(char *str, const char *delim) {
    static char* buffer;
    static char* saveptr;
    if(str != NULL){
        buffer = str;
        saveptr = buffer;
        char* token = strpbrk(buffer, delim);
        if (token) {
            *token = '\0';
            token++;
    } else {
        token = buffer + strlen(buffer);
    }
    buffer = token;
    } else saveptr = NULL;

    return saveptr;
}

int main() {
    char str[] = "123 qwe 43.fdfgdg.  gdsfogjsdlkgd../////fdgdgdfgdsgdgd";
    char *token;
    char ptr[] = " ./";
    int flag=0;

    // Используем my_strtok для разбиения строки на токены
    token = my_strtok(str, ptr);

    // Цикл для прохода по всем токенам
    while (token != NULL) {
        printf("%d\n", flag);
        flag++;
        printf("%s\n", token);
        token = my_strtok(NULL, ptr); // Второй аргумент NULL указывает, что следующий вызов должен продолжить разбиение той же строки
    }

    return 0;
}
