#define D_GNU_SOURCE
#define _POSIX_C_SOURCE 200809L
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct arguments {
  int b, n, s, E, T, v;
} arguments;

arguments argument_pareser(int argc, char* argv[]);
char v_output(char ch);
void outline(arguments* arg, char* line, int n);
void output(arguments* arg, char** argv);

int main(int argc, char* argv[]) {
  arguments arg = argument_pareser(argc, argv);
  output(&arg, argv);

  return 0;
}

arguments argument_pareser(int argc, char* argv[]) {
  arguments arg = {0};
  struct option long_options[] = {{"number", no_argument, NULL, 'n'},
                                  {"number-noblank", no_argument, NULL, 'b'},
                                  {"squeeze-blank", no_argument, NULL, 's'},
                                  {0, 0, 0, 0}};
  int opt;
  opt = getopt_long(argc, argv, "bnsEeTtv", long_options, 0);
  switch (opt) {
    case 'b':
      arg.b = 1;
      break;
    case 'n':
      arg.n = 1;
      break;
    case 's':
      arg.s = 1;
      break;
    case 'e':
      arg.E = 1;
      arg.v = 1;
      break;
    case 'E':
      arg.s = 1;
      break;
    case 't':
      arg.T = 1;
      arg.v = 1;
      break;
    case 'T':
      arg.T = 1;
      break;
    default:
      break;
  }
  return arg;
}

char v_output(char ch) {
  if (ch == '\n' || ch == '\t') return ch;
  if (ch <= 31) {
    putchar('^');
    ch += 64;
  } else if (ch == 127) {
    putchar('^');
    ch = '?';
  }
  return ch;
}

void outline(arguments* arg, char* line, int n) {
  for (int i = 0; i < n; i++) {
    if (arg->T > 0 && line[i] == '\t')
      printf("^I");
    else {
      if (arg->E > 0 && line[i] == '\n') putchar('$');
      if (arg->v) {
        line[i] = v_output(line[i]);
      }
      putchar(line[i]);
    }
  }
}

void output(arguments* arg, char** argv) {
  FILE* f = fopen(argv[optind], "r");
  char* line = NULL;
  size_t memline = 0;
  int read = 0;
  int line_count = 1;
  int emptiness_count = 0;
  read = getline(&line, &memline, f);
  while (read != -1) {
    if (line[0] == '\n')
      emptiness_count++;
    else
      emptiness_count = 0;
    if (arg->s > 0 && emptiness_count > 1) {
    } else {
      if (arg->n || arg->b) {
        if (arg->b > 0 && line[0] != '\n') {
          printf("%6d\t", line_count);
          line_count++;
        } else if (arg->n) {
          printf("%6d\t", line_count);
          line_count++;
        }
      }
      outline(arg, line, read);
    }
    read = getline(&line, &memline, f);
  }
  free(line);
  fclose(f);
}
