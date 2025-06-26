CC=g++
FLAGS=-std=c++17 -pedantic -Werror -Wextra -Wall
ADD_LIB=-lgtest -lm -lstdc++
GCOV=--coverage 
LEAK_CHECK=valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s --track-origins=yes --vgdb=full

all: s21_matrix_oop.a test leaks gcov_report clang clean 

s21_matrix_oop.a: clean
	$(CC) $(FLAGS) -c s21*.cpp
	ar rcs s21_matrix_oop.a s21*.o
	rm -rf *.o

test: clean
	$(CC) $(FLAGS) -o test s21*.cpp matrix_test.cpp $(ADD_LIB)
	./test
	rm -rf test

clang: clean
	cp ../materials/linters/.clang-format .
	clang-format -i *.cpp *.h
	clang-format -n *.cpp *.h
	rm -rf .clang-format

gcov_report: clean
	$(CC) $(FLAGS) $(GCOV) -o gcov_test s21*.cpp matrix_test.cpp $(ADD_LIB)
	./gcov_test
	lcov -c -d . --no-external -o gcov_test.info
	genhtml -o report gcov_test.info
	rm *.gcda *.gcno *.info gcov_test

gcov_report2: clean
	$(CC) $(FLAGS) $(GCOV) -o gcov_test s21*.cpp matrix_test.cpp $(ADD_LIB)
	./gcov_test
	lcov -c -d . --no-external -o gcov_test2.info --ignore-errors mismatch 
	genhtml -o report2 gcov_test2.info
	rm -rf *.gcda *.gcno *.info gcov_test	

leaks: clean
	$(CC) $(FLAGS) -o leaks_test s21*.cpp matrix_test.cpp $(ADD_LIB)
	$(LEAK_CHECK) ./leaks_test
	rm -rf leaks_test

clean:
	rm -rf leaks_test gcov_test test \
	*.o *.a *.gcda *.gcno *.info \
	report report2/ 
	