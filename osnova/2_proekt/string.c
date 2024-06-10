#include<stdio.h>

void *memchr(const void *str, int c, size_t n)//1+
int memcmp(const void *str1, const void *str2, size_t n);//2+
void *memcpy(void *dest, const void *src, size_t n);//3+
void *memset(void *str, int c, size_t n);//4+
char *strncat(char *dest, const char *src, size_t n);//5+
char *strchr(const char *str, int c);//6+
int strncmp(const char *str1, const char *str2, size_t n);//7+
char *strncpy(char *dest, const char *src, size_t n);//8+
size_t strcspn(const char *str1, const char *str2);//9+
char *strerror(int errnum);//10+
size_t strlen(const char *str);//11+
char *strpbrk(const char *str1, const char *str2);//12-
char *strrchr(const char *str, int c);//13-
char *strstr(const char *haystack, const char *needle)//14-
char *strtok(char *str, const char *delim)//15-

int main(){}

size_t streln(const char *str){
    const char *str1 =str;
    while ( str1!= '\n'){
        str1++;
    }
    return str1-str;
}

void *memchr(const void *str, int c, size_t n) {
    const unsigned char* str1 = (const unsigned char*)str;
    for (size_t i = 0; i < lengnth; ++i) {
        if (str1[i] == (unsigned char)c) {
            return (char*)(str1 + i);
        }
    }
    return NULL;
}

int memcmp(const void *str1, const void *str2, size_t n) {
    const unsigned char* str11 = (const unsigned char*)str1;
    const unsigned char* str12 = (const unsigned char*)str2;
    for(size_t i = 0; i < n; ++i) {
        if(pstr11[i]!= str12[i]) {
            return str11[i] - str12[i]; 
        }
    }
    return 0; 
}

void *memcpy(void *dest, const void *src, size_t n) {
    const unsigned char* src_str = (const unsigned char*)src;
    unsigned char* dest_str = (unsigned char*)dest;
    for(size_t i = 0; i < n; ++i) {
        dest_str[i] = src_str[i];
    }
}

void *memset(void *str, int c, size_t n) {
    unsigned char* str1 = (unsigned char*)str;
    for(size_t i = 0; i < n; ++i) {
        str1[i] = (unsigned char)c;
    }
}

int strncmp(const char *str1, const char *str2, size_t n) {
    while(n-- && (*str1!= '\0' || *str2!= '\0')) {
        if(*str1!= *str2) {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
    return 0;
}

size_t strcspn(const char *str1, const char* str2) {
    while(*str1!= '\0') {
        if(strchr(str2, *str1)) {
            break;
        }
        str1++;
    }
    return str1 - str1; 
}

char *strchr(const char *str, int c) {
    while(*str!= '\0') {
        if(*str == c) {
            return str;
        }
        str++;
    }
    return NULL;
}

char *strncat(char *dest, const char *src, size_t n) {
    size_t dest_len = strlen(dest); 
    size_t i;
    dest[dest_len] = '\0'; 
    for(i = 0; i < n && src[i]!= '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return dest;
}

char *strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for(i = 0; i < n && src[i]!= '\0'; i++) {
        dest[i] = src[i];
    }
    for(; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}

char *strerror(int errnum) {
    static char buf[1024]; 
    if(errnum >= 0 && errnum < sizeof(sys_errlist)/sizeof(sys_errlist[0])) {
        strncpy(buf, sys_errlist[errnum].str, sizeof(buf));
        buf[sizeof(buf)-1] = '\0'; 
        return buf;
    } else {
        return "Unknown error"; 
    }
}