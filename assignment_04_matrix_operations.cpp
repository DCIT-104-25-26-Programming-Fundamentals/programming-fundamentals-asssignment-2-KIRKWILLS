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
// YOUR CODE BELOW
// =============================================================================

#include <iostream>
using namespace std;

void readMatrix(int matrix[10][10], int &rows, int &cols) {
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
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
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int matrix_trans[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix_trans[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int matrixA[10][10], int matrixB[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[10][10], int matrixB[10][10], int result[10][10], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int matrixA[10][10], matrixB[10][10], matrixC[10][10];
    int rows, cols, colsB;
    int choice;
    
    cout << "Matrix Operations Menu" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            cout << "\n--- Transpose Matrix ---" << endl;
            readMatrix(matrixA, rows, cols);
            cout << "\nOriginal Matrix:" << endl;
            printMatrix(matrixA, rows, cols);
            
            transposeMatrix(matrixA, matrixB, rows, cols);
            cout << "\nTransposed Matrix:" << endl;
            printMatrix(matrixB, cols, rows);
            break;
            
        case 2:
            cout << "\n--- Add Two Matrices ---" << endl;
            cout << "Enter first matrix:" << endl;
            readMatrix(matrixA, rows, cols);
            
            cout << "\nEnter second matrix (same dimensions):" << endl;
            int dummyRows, dummyCols;
            readMatrix(matrixB, dummyRows, dummyCols);
            
            cout << "\nMatrix A:" << endl;
            printMatrix(matrixA, rows, cols);
            cout << "\nMatrix B:" << endl;
            printMatrix(matrixB, rows, cols);
            
            addMatrices(matrixA, matrixB, matrixC, rows, cols);
            cout << "\nSum (A + B):" << endl;
            printMatrix(matrixC, rows, cols);
            break;
            
        case 3:
            cout << "\n--- Multiply Two Matrices ---" << endl;
            cout << "Enter first matrix (M x N):" << endl;
            readMatrix(matrixA, rows, cols);
            
            cout << "\nEnter second matrix (N x P):" << endl;
            int rowsB;
            readMatrix(matrixB, rowsB, colsB);
            
            if (cols != rowsB) {
                cout << "Error: Number of columns in first matrix must equal number of rows in second matrix." << endl;
                break;
            }
            
            cout << "\nMatrix A:" << endl;
            printMatrix(matrixA, rows, cols);
            cout << "\nMatrix B:" << endl;
            printMatrix(matrixB, rowsB, colsB);
            
            multiplyMatrices(matrixA, matrixB, matrixC, rows, cols, colsB);
            cout << "\nProduct (A x B):" << endl;
            printMatrix(matrixC, rows, colsB);
            break;
            
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

