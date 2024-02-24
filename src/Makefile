FLAGS = -Wall -Werror -Wextra -std=c11
LIB_FLAGS = -lcheck -lgcov
CODE_FILES = s21_*.c
TEST_FILES = test.c

all:
	gcc $(CODE_FILES) $(TEST_FILES) -lcheck
	./a.out

style:
	clang-format -n *.c *.h
	clang-format -i *.c *.h

checks: style
	gcc $(FLAGS) $(CODE_FILES) $(TEST_FILES)
	cppcheck *.c *.h

clean:
	rm -rf report *.a *.o *.gcda *.gcno *.gcov *.info test ./a.out

test: clean s21_math.a
	gcc $(TEST_FILES) -o test s21_math.a -lcheck
	./test
	rm ./test

s21_math.a:
	gcc -c $(CODE_FILES)
	ar rcs s21_math.a s21_*.o
	ranlib s21_math.a

gcov_report: s21_math.a
	gcc --coverage $(CODE_FILES) $(TEST_FILES) $(LIB_FLAGS) -o test
	./test
	lcov -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html
