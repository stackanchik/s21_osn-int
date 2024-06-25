#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Для malloc

void *to_upper(const char *str) {
    size_t len = strlen(str); // Определяем длину строки
    char* newStr[];
    int flag=1;
    if (newStr == NULL) {
        fprintf(stderr, "Ошибка выделения памяти.\n");
        flag=0;
    }
    if (flag){
    for (size_t i = 0; i < len; ++i) {
        // Проверяем, находится ли символ в диапазоне от 'a' до 'z'
        if (str[i] >= 'a' && str[i] <= 'z') {
            // Вычисляем разницу между символами в нижнем и верхнем регистрах
            newStr[i] = str[i] - ('a' - 'A');
        } else {
            newStr[i] = str[i]; // Копируем символ без изменений, если он не в диапазоне 'a'..'z'
        }
    }
    newStr[len] = '\0'; 
    } else newStr= NULL;// Добавляем нулевой символ в конце строки

    return newStr;
}

int main() {
    const char str[] = "qwertyui123456789jhgfd";
    char* upperStr = to_upper(str);

    printf("Исходная строка: %s\n", str);
    printf("Строка в верхнем регистре: %s\n", upperStr);
    return 0;
}