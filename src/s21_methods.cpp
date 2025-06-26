#include "s21_matrix_oop.h"

// Accessor (getters)
int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }

// Mutator (setters)
void S21Matrix::SetRows(int rows) {
  if (rows < 1)
    throw std::logic_error("Rows of matrix should be more or equal 1");
  if (rows != rows_) {
    S21Matrix result(rows, cols_);
    for (int i = 0; i < (rows_ < rows ? rows_ : rows); ++i)
      for (int j = 0; j < cols_; ++j) result.matrix_[i][j] = matrix_[i][j];
    *this = std::move(result);
  }
}

void S21Matrix::SetCols(int cols) {
  if (cols < 1)
    throw std::logic_error("Cols of matrix should be more or equal 1");
  if (cols != cols_) {
    S21Matrix result(rows_, cols);
    for (int i = 0; i < rows_; ++i)
      for (int j = 0; j < (cols_ < cols ? cols_ : cols); ++j)
        result.matrix_[i][j] = matrix_[i][j];
    *this = std::move(result);
  }
}

// Метод проверяет матрицы на равенство между собой
bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool result = true;
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    result = false;
  }
  for (int i = 0; (i < rows_) && result; i++) {
    for (int j = 0; (j < cols_) && result; j++) {
      if (matrix_[i][j] - other.matrix_[i][j] > 1e-7) {
        result = false;
      }
    }
  }
  return result;
}

// Метод прибавляет вторую матрицу к текущей
void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error("Matrix sizes must be equal for addition");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

// Метод вычитает из текущей матрицы другую
void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error("Matrix sizes must be equal for subtraction");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

// Метод умножает текущую матрицу на число
void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

// Метод умножает текущую матрицу на вторую
void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_)
    throw std::logic_error(
        "Columns of matrix 1 should be the same size as rows of matrix 2");
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < result.rows_; ++i)
    for (int j = 0; j < result.cols_; ++j)
      for (int p = 0; p < cols_; ++p)
        result.matrix_[i][j] += matrix_[i][p] * other.matrix_[p][j];
  *this = result;
}

// Метод создает новую транспонированную матрицу
S21Matrix S21Matrix::Transpose() const {
  S21Matrix transposed(cols_, rows_);
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) transposed.matrix_[j][i] = matrix_[i][j];
  return transposed;
}

// Метод вычисляет матрицу алгебраических дополнений
S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) throw std::logic_error("The matrix must be square");
  if (rows_ == 1) {
    S21Matrix result{1, 1};
    result.matrix_[0][0] = 1;
    return result;
  }
  S21Matrix result{rows_, cols_};
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      double minor = MatrixMinor(i, j).Determinant();
      bool SumIsEven = ((i + j) % 2) == 0;
      result.matrix_[i][j] = (SumIsEven) ? minor : -minor;
    }
  }
  return result;
}

// Метод вычисляет и возвращает определитель текущей матрицы
double S21Matrix::Determinant() {
  if (rows_ != cols_) throw std::logic_error("The matrix is not square");
  double result = 0;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    int power = 1;
    for (int j = 0; j < cols_; j++) {
      S21Matrix minor = MatrixMinor(0, j);
      result += power * matrix_[0][j] * minor.Determinant();
      power *= -1;
    }
  }
  return result;
}

// Метод вычисляет и возвращает обратную матрицу
S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (det == 0) throw std::logic_error("InverseError: Determinant is 0");
  S21Matrix result(rows_, cols_);
  result = CalcComplements();
  result = result.Transpose();
  return result * (1.0 / det);
}

// Вспомогательные функции
void S21Matrix::freeMatrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      if (matrix_[i]) {
        delete[] matrix_[i];
        matrix_[i] = nullptr;
      }
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
}

void S21Matrix::createMatrix(int rows, int cols) {
  double **matrix = new double *[rows];
  for (int i{}; i < rows; i++) {
    matrix[i] = new double[cols]{};
  }
  matrix_ = matrix;
}

S21Matrix S21Matrix::MatrixMinor(int row, int col) {
  S21Matrix result{rows_ - 1, cols_ - 1};
  for (int result_i = 0, i = 0; i < rows_; i++) {
    for (int result_j = 0, j = 0; j < cols_; j++) {
      if (i != row && j != col) {
        result.matrix_[result_i][result_j] = matrix_[i][j];
        result_j++;
      }
    }
    if (i != row) result_i++;
  }
  return result;
}