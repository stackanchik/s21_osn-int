#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "123 qwe 43. fdfgdg.  gdsfogjsdlkgd../////fdgdgdfgdsgdgd";
    char *token;
    char ptr[] = " ./";
    // Используем strtok для разбиения строки на токены
    token = strtok(str, ptr);

    // Цикл для прохода по всем токенам
    while(token!= NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ptr); // Второй аргумент NULL указывает, что следующий вызов должен продолжить разбиение той же строки
    }

    return 0;
}
