<<<<<<< HEAD
# Matrix_plus

В данном проекте реализована библиотека для работы с матрицами, используя объектно-ориентированный подход. Объектно-ориентированный подход позволяет реализовать библиотеку для работы с матрицами в виде отдельного класса, над объектами которого определены операции, представленные как методами, так и стандартными операторами +, -, * и т. д.

## Операции над матрицами

Ниже представлено краткое описание операций над матрицами, которые реализованы в библиотеке.

| Операция    | Описание   | Исключительные ситуации |
| ----------- | ----------- | ----------- |
| `bool EqMatrix(const S21Matrix& other)` | Проверяет матрицы на равенство между собой. |  |
| `void SumMatrix(const S21Matrix& other)` | Прибавляет вторую матрицу к текущей | различная размерность матриц. |
| `void SubMatrix(const S21Matrix& other)` | Вычитает из текущей матрицы другую | различная размерность матриц. |
| `void MulNumber(const double num)` | Умножает текущую матрицу на число. |  |
| `void MulMatrix(const S21Matrix& other)` | Умножает текущую матрицу на вторую. | число столбцов первой матрицы не равно числу строк второй матрицы. |
| `S21Matrix Transpose()` | Создает новую транспонированную матрицу из текущей и возвращает ее. |  |
| `S21Matrix CalcComplements()` | Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает ее. | Матрица не является квадратной. |
| `double Determinant()` | Вычисляет и возвращает определитель текущей матрицы. | Матрица не является квадратной. |
| `S21Matrix InverseMatrix()` | Вычисляет и возвращает обратную матрицу. | Определитель матрицы равен 0. |

Помимо реализации данных операций, реализованы конструкторы и деструкторы:

| Метод    | Описание   |
| ----------- | ----------- |
| `S21Matrix()` | Базовый конструктор, инициализирующий матрицу некоторой заранее заданной размерностью. |  
| `S21Matrix(int rows, int cols)` | Параметризированный конструктор с количеством строк и столбцов. | 
| `S21Matrix(const S21Matrix& other)` | Конструктор копирования. |
| `S21Matrix(S21Matrix&& other)` | Конструктор переноса. |
| `~S21Matrix()` | Деструктор. |

Реализована перегрузка следующих операторов, частично соответствующих операциям выше:

| Оператор    | Описание   | Исключительные ситуации |
| ----------- | ----------- | ----------- |
| `+`      | Сложение двух матриц.  | Различная размерность матриц. |
| `-`   | Вычитание одной матрицы из другой. | Различная размерность матриц. |
| `*`  | Умножение матриц и умножение матрицы на число. | Число столбцов первой матрицы не равно числу строк второй матрицы. |
| `==`  | Проверка на равенство матриц (`EqMatrix`). | |
| `=`  | Присвоение матрице значений другой матрицы. | |
| `+=`  | Присвоение сложения (`SumMatrix`).   | Различная размерность матриц. |
| `-=`  | Присвоение разности (`SubMatrix`). | Различная размерность матриц. |
| `*=`  | Присвоение умножения (`MulMatrix`/`MulNumber`). | Число столбцов первой матрицы не равно числу строк второй матрицы. |
| `(int i, int j)`  | Индексация по элементам матрицы (строка, колонка). | Индекс за пределами матрицы. |

## Сборка

- make s21_matrix_oop.a - Компиляция статической библиотеки
- make test - Покрытие unit-тестами функций вычисления c помощью библиотеки GTest
- make gcov_report - Формирование отчёта gcov в виде html страницы
- make leaks - Проверка тестов на утечки памяти
- make clang - Проверка кода на Google style
- make clean - Удаление ненужных файлов

## Описание

- Программа разработана на языке C++ стандарта C++17 с использованием компилятора gcc.
- При написании кода использовался Google Style.
- Матрица реализована в виде класса `S21Matrix`.
- Храни только приватные поля `matrix_`, `rows_` и `cols_`.
- Доступ к приватным полям rows_ и cols_ реализован через accessor и mutator. При увеличении размера матрица дополняется нулевыми элементами, при уменьшении - лишнее просто отбрасывается.
- Решение оформлено как статическая библиотека (с заголовочным файлом s21_matrix_oop.h).
- Полное покрытие unit-тестами функций библиотеки c помощью библиотеки GTest.
=======
<h1 align="center">Hi 👋, I'm Oleg</h1>
<h3 align="center">Студент Школы 21 от Сбер</h3>


<h3 align="left">Languages:</h3>
<p align="left"> <a href="https://www.cprogramming.com/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/> </a> <a href="https://www.w3schools.com/cpp/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="cplusplus" width="40" height="40"/> <a href="https://www.python.org" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/python/python-original.svg" alt="python" width="40" height="40"/> </a> <h3 align="left">Tools:</h3><a href="https://www.docker.com/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/docker/docker-original-wordmark.svg" alt="docker" width="40" height="40"/> </a> <a href="https://git-scm.com/" target="_blank" rel="noreferrer"> <img src="https://www.vectorlogo.zone/logos/git-scm/git-scm-icon.svg" alt="git" width="40" height="40"/> </a> <a href="https://www.linux.org/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/linux/linux-original.svg" alt="linux" width="40" height="40"/> </a> <a href="https://www.nginx.com" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/nginx/nginx-original.svg" alt="nginx" width="40" height="40"/> </a> <a href="https://www.postgresql.org" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/postgresql/postgresql-original-wordmark.svg" alt="postgresql" width="40" height="40"/> </a> </a> <a href="https://www.qt.io/" target="_blank" rel="noreferrer"> <img src="https://upload.wikimedia.org/wikipedia/commons/0/0b/Qt_logo_2016.svg" alt="qt" width="40" height="40"/> </a> </p>
>>>>>>> c4c684d (1)
