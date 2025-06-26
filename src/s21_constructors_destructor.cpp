#include "s21_matrix_oop.h"

// конструктор по умолчанию
S21Matrix::S21Matrix() {
  rows_ = cols_ = 1;
  createMatrix(1, 1);
}

// конструктор с параметрами
S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) throw std::logic_error("Incorrect matrix size");
  rows_ = rows;
  cols_ = cols;
  createMatrix(rows_, cols_);
}

// конструктор копирования из другой матрицы
S21Matrix::S21Matrix(const S21Matrix &other)
    : S21Matrix(other.rows_, other.cols_) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

// конструктор перемещения данных из другой матрицы
S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

// деструктор
S21Matrix::~S21Matrix() {
  freeMatrix();
  rows_ = cols_ = 0;
}