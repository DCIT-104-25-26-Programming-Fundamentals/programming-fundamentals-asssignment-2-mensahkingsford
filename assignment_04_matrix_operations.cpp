// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// #include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int result[10][10],
                       int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int total = 0;
            for (int k = 0; k < colsA; k++) {
                total += a[i][k] * b[k][j];
            }
            result[i][j] = total;
        }
    }
}

int main() {
    // ---------- Part A: Transpose ----------
    cout << "=== Part A: Transpose a Matrix ===" << endl;
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrix[10][10];
    readMatrix(matrix, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrix, rows, cols);

    int transposed[10][10];
    transposeMatrix(matrix, transposed, rows, cols);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, cols, rows);

    // ---------- Part B: Add Two Matrices ----------
    cout << "\n=== Part B: Add Two Matrices ===" << endl;
    int rowsB, colsB;
    cout << "Enter number of rows for both matrices: ";
    cin >> rowsB;
    cout << "Enter number of columns for both matrices: ";
    cin >> colsB;

    int matrix1[10][10], matrix2[10][10];
    cout << "Matrix 1:" << endl;
    readMatrix(matrix1, rowsB, colsB);
    cout << "Matrix 2:" << endl;
    readMatrix(matrix2, rowsB, colsB);

    int sumResult[10][10];
    addMatrices(matrix1, matrix2, sumResult, rowsB, colsB);

    cout << "\nSum of Matrices:" << endl;
    printMatrix(sumResult, rowsB, colsB);

    // ---------- Part C: Multiply Two Matrices ----------
    cout << "\n=== Part C: Multiply Two Matrices ===" << endl;
    int m, n, p;
    cout << "Enter rows of Matrix A: ";
    cin >> m;
    cout << "Enter columns of Matrix A (= rows of Matrix B): ";
    cin >> n;
    cout << "Enter columns of Matrix B: ";
    cin >> p;

    int matrixA[10][10], matrixB[10][10];
    cout << "Matrix A:" << endl;
    readMatrix(matrixA, m, n);
    cout << "Matrix B:" << endl;
    readMatrix(matrixB, n, p);

    int product[10][10];
    multiplyMatrices(matrixA, matrixB, product, m, n, p);

    cout << "\nProduct of Matrices (A x B):" << endl;
    printMatrix(product, m, p);

    return 0;
}
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

