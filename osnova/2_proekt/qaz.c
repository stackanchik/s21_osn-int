#include <stdio.h>
#include <string.h>

// Функция my_strtok с дополнительными параметрами
char *my_strtok(char *str, const char *delim) {
  static int next, restok;
  static size_t idx;
  static char *ptr;
  static char *addr;

  if (str) {
    restok = 1;
    idx = 0, next = 0;
    addr = str + strspn(str, delim);
    ptr = str + strlen(str);
  }
  char *res = NULL;
  if (!(addr >= ptr || next)) {
    int exdelim = 1;
    for (int i = 0; addr[i]; i++) {
      size_t step = strspn(addr + i, delim);
      if (step != 0) {
        exdelim = 0;
        for (size_t j = i; j < i + step; j++) addr[j] = '\0';

        idx = step + i;
        break;
      }
    }
    if (restok == 1 && exdelim) next = 1;
    res = addr;
    addr += idx;
  }
  restok += 1;
  return res;
}

int main() {
    char str[] = "123 qwe 43.fdfgdg.  gdsfogjsdlkgd../////fdgdgdfgdsgdgd";
    char *token;
    char ptr[] = " ./";

    // Используем my_strtok для разбиения строки на токены
    token = my_strtok(str, ptr);

    // Цикл для прохода по всем токенам
    while (token != NULL) {
        printf("%s\n", token);
        token = my_strtok(NULL, ptr); // Второй аргумент NULL указывает, что следующий вызов должен продолжить разбиение той же строки
    }

    return 0;
}
