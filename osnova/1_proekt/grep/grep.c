#define D_GNU_SOURCE
#define _POSIX_C_SOURCE 200809L
#include "s21_grep.h"

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

arguments arguments_par(int argc, char* argv[]);
void output(arguments arg, int argc, char** argv);
void pattern_add(arguments* arg, char* pattern);
void regular_file(arguments* arg, char* filepath);
void compr_line(char* line, int n);
void print_match(regex_t* re, char* line);
void process_File(arguments arg, char* path, regex_t* reg);

int main(int argc, char** argv) {
  arguments arg = arguments_par(argc, argv);
  output(arg, argc, argv);
  return 0;
}

arguments arguments_par(int argc, char* argv[]) {
  arguments arg = {0};
  int opt;
  while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (opt) {
      case 'e':
        arg.e = 1;
        pattern_add(&arg, optarg);
        break;
      case 'i':
        arg.i = REG_ICASE;
        break;
      case 'v':
        arg.v = 1;
        break;
      case 'c':
        arg.c = 1;
        break;
      case 'l':
        arg.c = 1;
        arg.l = 1;
        break;
      case 'n':
        arg.n = 1;
        break;
      case 'h':
        arg.h = 1;
        break;
      case 's':
        arg.s = 1;
        break;
      case 'f':
        arg.f = 1;
        regular_file(&arg, optarg);
        break;
      case 'o':
        arg.o = 1;
        break;
      default:
        break;
    }
  }
  if (arg.len_pattern == 0) {
    pattern_add(&arg, argv[optind]);
    optind++;
  }
  if (argc - optind == 1) {
    arg.h = 1;
  }
  return arg;
}

void output(arguments arg, int argc, char** argv) {
  regex_t re;
  int error = regcomp(&re, arg.pattern, REG_EXTENDED | arg.i);
  if (error) {
    perror("Error");
  }
  for (int i = optind; i < argc; i++) {
    process_File(arg, argv[i], &re);
  }
  regfree(&re);
}

void pattern_add(arguments* arg, char* pattern) {  
  if (arg->len_pattern != 0) {
    strcat(arg->pattern + arg->len_pattern, "|");
    arg->len_pattern++;
  }
  arg->len_pattern += sprintf(arg->pattern + arg->len_pattern, "(%s)", pattern);
}

void regular_file(arguments* arg,
                  char* filepath) {  
  FILE* f = fopen(filepath, "r");
  if (f == NULL) {
    if (!arg->s)
      perror(filepath);  
                         
    exit(1);
  }
  char* line = NULL;
  size_t lstr = 0;
  int read;
  read = getline(&line, &lstr, f);
  while (read != -1) {
    if (line[read - 1] == '\n')
      line[read - 1] = '\0';  
                              
    pattern_add(arg, line);
    read = getline(&line, &lstr, f);
  }
  free(line);
  fclose(f);
}

void compr_line(char* line, int n) {
  for (int i = 0; i < n; i++) {
    putchar(line[i]);
  }
  if (line[n - 1] != '\n')
    printf("\n");  
}

void print_match(regex_t* re, char* line) {
  regmatch_t match;
  int sdvig = 0;
  while (1) {
    int result = regexec(re, line + sdvig, 1, &match, 0);
    if (result != 0) {
      break;
    }
    for (int i = match.rm_so; i < match.rm_eo;
         i++) {  
      putchar(line[i] + sdvig);
    }
    putchar('\n');
    sdvig += match.rm_eo;
  }
}

void process_File(arguments arg, char* path, regex_t* reg) {
  FILE* f = fopen(path, "r");
  if (f == NULL) {
    if (!arg.s) perror(path);
    exit(1);
  }
  char* line = NULL;
  size_t lstr = 0;
  int read = 0;
  int num_line = 1;
  int S = 0, for_l = 0;
  read = getline(&line, &lstr, f);
  while (read != -1) {
    int result = regexec(reg, line, 0, NULL, 0);
    if ((result == 0 && !arg.v) || (arg.v && result != 0)) {
      for_l = 1;
      if (!arg.c && !arg.l) {
        if (arg.n) {
          if (!arg.h && !arg.l) printf("%s:", path);
          printf("%d:", num_line);
        }  
           
        if (arg.o) {
          print_match(reg, line);
        } else
          compr_line(line, read);
      }
      S++;
    }
    read = getline(&line, &lstr, f);
    num_line++;
  }
  free(line);
  if (arg.c && !arg.l) {
    if (!arg.h)
      printf("%s:", path);  
    printf("%d\n", S);      
  }
  if (arg.l && for_l == 1) {
    printf("%s\n", path);
  }
  fclose(f);
}