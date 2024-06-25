#include<stdio.h>
#include <errno.h>
#include <ctype.h>

void *memchr(const void *str, int c, size_t n)//1+++
int memcmp(const void *str1, const void *str2, size_t n);//2+++
void *memcpy(void *dest, const void *src, size_t n);//3+++
void *memset(void *str, int c, size_t n);//4+++
char *strncat(char *dest, const char *src, size_t n);//5+++
char *strchr(const char *str, int c);//6+++
int strncmp(const char *str1, const char *str2, size_t n);//7+++
char *strncpy(char *dest, const char *src, size_t n);//8+++
size_t strcspn(const char *str1, const char *str2);//9+++
char *strerror(int errnum);//10+???????????
size_t strlen(const char *str);//11+++
char *strpbrk(const char *str1, const char *str2);//12+
char *strrchr(const char *str, int c);//13+
char *strstr(const char *haystack, const char *needle)//14+
char *strtok(char *str, const char *delim);//15+
void *to_upper(const char *str);//16-
void *to_lower(const char *str);//17-
void *insert(const char *src, const char *str, size_t start_index);//18-
void *trim(const char *src, const char *trim_chars);//19-

const char* error_messages[] = {
    "Operation not permitted",
    "No such file or directory",
    "Not a directory",
    "Invalid argument",
    "Incorrect file descriptor number",
    "Address already in use",
    "Permission denied",
    "Resource temporarily unavailable",
    "Deadlock condition",
    "Interrupted system call",
    "I/O error",
    "No room left on device",
    "Unknown error"
};

size_t strlen(const char *str){
    const char *str1 =str;
    while ( *str1!= '\n'){
        str1++;
    }
    return str1-str;
}

void *memchr(const void *str, int c, size_t n) {
    const unsigned char* str1 = (const unsigned char*)str;
    for (size_t i = 0; i < n; ++i) {
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
        if(str11[i]!= str12[i]) {
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

size_t strcspn(const char *str1, const char *str2) {
    const char *p = str1;
    while (*p!= '\0') {
        int found = 0;
        const char *q = str2;
        while (*q!= '\0' &&!found) {
            if (*p == *q) {
                found = 1;
            }
            q++;
        }
        if (!found) {
            p++;
        } else {
            break;
        }
    }
    return p - str1;
}

char *strchr(const char *str, int c) {
    while(*str!= '\0') {
        if(*str == c) {
            return (char*)str;
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

char* strerror(int errnum) {
    if (errnum >= 0 && errnum < sizeof(error_messages)/sizeof(char*)) {
        return error_messages[errnum];
    } else {
        return "Unknown error";
    }
}//?????

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

char *strrchr(const char *str, int c) {
    const char* start = str;
    const char* end = str + strlen(str); 
    while (end >= start) {
        if (*end == c) {
            return (char*)end; 
        }
        end--;
    }
    return NULL; 
}

char *strstr(const char *haystack, const char *needle) {
    const char* h = haystack;
    const char* n = needle;
    if (*n == '\0') {
        return (char*)haystack;
    }
    while (*h) {
        if (*h == *n && memcmp(h, n, strlen(n)) == 0) {
            return (char*)h;
        }
        h++;
    }
    return NULL;
}

char *strtok(char *str, const char *delim) {
    static char* buffer = NULL;
    }
    if(str != NULL){
        buffer = str;
        char* saveptr = buffer;
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

void *to_upper(const char *str){}//16-


void *to_lower(const char *str){}//17-


void *insert(const char *src, const char *str, size_t start_index){}//18-


void *trim(const char *src, const char *trim_chars){}//19-

