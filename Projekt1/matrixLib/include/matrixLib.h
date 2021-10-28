#ifndef PROJEKT1_MATRIXLIB_H
#define PROJEKT1_MATRIXLIB_H

int** addMatrix(int** matrixA, int** matrixB, int rowsNumber, int columnsNumber);
double** addMatrix(double** matrixA, double** matrixB, int rowsNumber, int columnsNumber);

int** subtractMatrix(int** matrixA, int** matrixB, int rowsNumber, int columnsNumber);
double** subtractMatrix(double** matrixA, double** matrixB, int rowsNumber, int columnsNumber);

int** multiplyMatrix(int** matrixA, int** matrixB, int rowsQuantityFirstMatrix, int columnsQuantityFirstMatrix, int columnsQuantitySecondMatrix);
double** multiplyMatrix(double** matrixA, double** matrixB, int rowsQuantityFirstMatrix, int columnsQuantityFirstMatrix, int columnsQuantitySecondMatrix);

int** multiplyByScalar(int** matrixA, int rowsNumber, int columnsNumber, int scalar);
double** multiplyByScalar(double** matrixA, int rowsNumber, int columnsNumber, double scalar);

int** transpozeMatrix(int** matrixA, int rowsNumber, int columnsNumber);
double** transpozeMatrix(double** matrixA, int rowsNumber, int columnsNumber);

int** powerMatrix(int** matrixA, int rowsNumber, int columnsNumber, unsigned exponent);
double** powerMatrix(double** matrixA, int rowsNumber, int columnsNumber, unsigned exponent);

int determinantMatrix(int** matrixA, int rowsNumber, int columnsNumber);
double determinantMatrix(double** matrixA, int rowsNumber, int columnsNumber);

bool matrixIsDiagonal(int** matrixA, int rowsNumber, int columnsNumber);
bool matrixIsDiagonal(double** matrixA, int rowsNumber, int columnsNumber);

void swap(int &a, int &b);
void swap(double &a, double &b);

int* sortRow(int* array, int columnsNumber);
double* sortRow(double* array, int columnsNumber);

int** sortRowsInMatrix(int** matrixA, int rowsNumber, int columnsNumber);
double** sortRowsInMatrix(double** matrixA, int rowsNumber, int columnsNumber);

void help();

#endif //PROJEKT1_MATRIXLIB_H
