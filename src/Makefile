gcov:
	gcc --coverage -c s21_math.c  # -Wall -Werror -Wextra -std=c11
	ar rcs s21_math.a s21_math.o
	ranlib s21_math.a
	gcc -c test.c test.c 
	gcc test.o s21_math.a -lcheck -lgcov -o test
	./test