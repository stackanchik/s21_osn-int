SHELL := /bin/bash
GWWW :=  gcc -Wall -Werror -Wextra
FILE := grep_test.txt
FILES := *.txt
FILE1 := grep1_test.txt

all : s21_grep tests
s21_grep : clean
	$(GWWW) s21_grep.c -o s21_grep

clean:
	clear

tests : 
	-diff <(./s21_grep void $(FILE)) <(grep void $(FILE))
	-diff <(./s21_grep -e void $(FILE)) <(grep -e void $(FILE))
	-diff <(./s21_grep -i void $(FILE)) <(grep -i void $(FILE))
	-diff <(./s21_grep -v void $(FILE)) <(grep -v void $(FILE))
	-diff <(./s21_grep -c void $(FILE)) <(grep -c void $(FILE))
	-diff <(./s21_grep -l void $(FILE)) <(grep -l void $(FILE))
	-diff <(./s21_grep -n void $(FILE)) <(grep -n void $(FILE))
	-diff <(./s21_grep -h void $(FILE)) <(grep -h void $(FILE))
	-diff <(./s21_grep -s void $(FILE)) <(grep -s void $(FILE))
	-diff <(./s21_grep -f $(FILE1) $(FILE)) <(grep -f $(FILE1) $(FILE))
	-diff <(./s21_grep -o void $(FILE)) <(grep -o void $(FILE))
	-diff <(./s21_grep -iv void $(FILE)) <(grep -iv void $(FILE))
	-diff <(./s21_grep -in void $(FILE)) <(grep -in void $(FILE))
	-diff <(./s21_grep -vin void $(FILE)) <(grep -vin void $(FILE))

rebuild :
	clean
	all