#include<stdio.h>
#include <ctype.h>
#include<stdlib.h>

void *memchr(const void *str, int c, size_t n)//1+++
int memcmp(const void *str1, const void *str2, size_t n);//2+++
void *memcpy(void *dest, const void *src, size_t n);//3+++
void *memset(void *str, int c, size_t n);//4+++
char *strncat(char *dest, const char *src, size_t n);//5+++
char *strchr(const char *str, int c);//6+++
int strncmp(const char *str1, const char *str2, size_t n);//7+++
char *strncpy(char *dest, const char *src, size_t n);//8+++
size_t strcspn(const char *str1, const char *str2);//9+++
char *strerror(int errnum);//10+++
size_t strlen(const char *str);//11+++
char *strpbrk(const char *str1, const char *str2);//12+++
char *strrchr(const char *str, int c);//13+++
char *strstr(const char *haystack, const char *needle)//14+++
char *strtok(char *str, const char *delim);//15+++
void *to_upper(const char *str);//16+++ чистить память в мейне при тестах
void *to_lower(const char *str);//17+++ чистить память в мейне при тестах
void *insert(const char *src, const char *str, size_t start_index);//18-
void *trim(const char *src, const char *trim_chars);//19-


size_t strspn(const char *str, const char *keys) {
  size_t strLength = strlen(str);
  size_t result = 0;

  for (s21_size_t x = 0; result == 0 && x < strLength; x += 1) {
    if (strchr(keys, str[x]) != NULL) result = x + 1;
  }

  return result;
}

#define MAX_ERRLIST 107
#define MIN_ERRLIST -1
#define ERROR "Unknown error: "
static const char *errorList[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"};



size_t strlen(const char *str){
    const char *str1 =str;
    while ( *str1!= '\0'){
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

char *s21_strerror(int errorNumber) {
  static char result[512] = {'\0'};

  if (errorNumber <= MIN_ERRLIST || errorNumber >= MAX_ERRLIST) {
    s21_sprintf(result, "Unknown error: %d", errorNumber);
  } else {
    s21_strcpy(result, ((char *)errorList[errorNumber]));
  }

  return result;
}

char *strpbrk(const char *str1, const char *str2) {
    const char *ptr1 = str1;
    const char *ptr2 = str2;
    while (*ptr1) {
        for (; *ptr2; ptr2++) {
            if (*ptr1 == *ptr2) {
                return (char *)ptr1;
            }
        }
        ptr1++;
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

void *to_upper(const char *str) {
  char *newstr = calloc(strlen(str) + 1, 1);
  for (unsigned long long i = 0; i < strlen(str); i++) {
    if (str[i] < 'a' || str[i] > 'z') {
      newstr[i] = str[i];
    } else {
      newstr[i] = str[i] - 32;
    }
  }
  return newstr;
}


void *to_lower(const char *str) {
  char *newstr = calloc(strlen(str) + 1, 1);
  for (unsigned long long i = 0; i < strlen(str); i++) {
    if (str[i] < 'A' || str[i] > 'Z') {
      newstr[i] = str[i];
    } else {
      newstr[i] = str[i] + 32;
    }
  }
  return newstr;
}


void *insert(const char *src, const char *str, size_t start_index){}//18-


void *trim(const char *src, const char *trim_chars){}//19-

