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

int** powerMatrix(int** matrixA, int rowsNumber, int columnsNumber, unsigned int exponent);
double** powerMatrix(double** matrixA, int rowsNumber, int columnsNumber, unsigned int exponent);

int determinantMatrix(int** matrixA, int rowsNumber, int columnsNumber);
double determinantMatrix(double** matrixA, int rowsNumber, int columnsNumber);

bool matrixIsDiagonal(int** matrixA, int rowsNumber, int columnsNumber);
bool matrixIsDiagonal(double** matrixA, int rowsNumber, int columnsNumber);

void swap(int &a, int &b);
void swap(double &a, double &b);

void sortRow(int* array, int columnsNumber);
void sortRow(double* array, int columnsNumber);

void sortRowsInMatrix(int** matrixA, int rowsNumber, int columnsNumber);
void sortRowsInMatrix(double** matrixA, int rowsNumber, int columnsNumber);

void help();
#endif
