#include <iostream>

#include "../include/matrixLib.h"

using namespace std;

int** allocationInteger(int rowsNumber, int columnsNumber){
    int** matrixToAlloc = new int *[rowsNumber];

    for(int i = 0; i < rowsNumber; i++) {
        matrixToAlloc[i] = new int[columnsNumber];
    }
    return matrixToAlloc;
}

double** allocationDouble(int rowsNumber, int columnsNumber){
    double** matrixToAlloc = new double*[rowsNumber];

    for(int i = 0; i < rowsNumber; i++) {
        matrixToAlloc[i] = new double[columnsNumber];
    }
}

void tmpMatrixInteger(int** matrixA, int **tempMatrix, int currentRow, int currentColumn, int n) {
    int row = 0, column = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != currentRow && j != currentColumn) {
                tempMatrix[row][column++] = matrixA[i][j];
                if(column == n - 1) {
                    column = 0;
                    row++;
                }
            }
        }
    }
}

void tmpMatrixDouble(double** matrixA, double **tempMatrix, int currentRow, int currentColumn, int n) {
    int row = 0, column = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != currentRow && j != currentColumn) {
                tempMatrix[row][column++] = matrixA[i][j];
                if(column == n - 1) {
                    column = 0;
                    row++;
                }
            }
        }
    }
}

int** addMatrix(int** matrixA, int** matrixB, int rowsNumber, int columnsNumber) {
    int** sumOfMatrices = allocationInteger(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            sumOfMatrices[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return sumOfMatrices;
}

double** addMatrix(double** matrixA, double** matrixB, int rowsNumber, int columnsNumber) {
    double** sumOfMatrices = allocationDouble(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            sumOfMatrices[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return sumOfMatrices;
}

int** subtractMatrix(int** matrixA, int** matrixB, int rowsNumber, int columnsNumber) {
    int** differenceOfMatrices = allocationInteger(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            differenceOfMatrices[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return differenceOfMatrices;
}

double** subtractMatrix(double** matrixA, double** matrixB, int rowsNumber, int columnsNumber) {
    double** differenceOfMatrices = allocationDouble(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            differenceOfMatrices[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return differenceOfMatrices;
}

int** multiplyMatrix(int** matrixA, int** matrixB, int rowsQuantityFirstMatrix, int columnsQuantityFirstMatrix, int columnsQuantitySecondMatrix){
    int** productOfMatrices = allocationInteger(rowsQuantityFirstMatrix, columnsQuantitySecondMatrix);

    for(int i = 0; i < rowsQuantityFirstMatrix; i++){
        for(int j = 0; j < columnsQuantitySecondMatrix; j++) {
            productOfMatrices[i][j] = 0;
        }
    }
    cout<<"\n";

    for(int i = 0; i < rowsQuantityFirstMatrix; i++) {
        for(int j = 0; j < columnsQuantitySecondMatrix; j++) {
            for(int k = 0; k < columnsQuantityFirstMatrix; k++) {
                productOfMatrices[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return productOfMatrices;

}

double** multiplyMatrix(double** matrixA, double** matrixB, int rowsQuantityFirstMatrix, int columnsQuantityFirstMatrix, int columnsQuantitySecondMatrix) {
    double** productOfMatrices = allocationDouble(rowsQuantityFirstMatrix, columnsQuantitySecondMatrix);

    for(int i = 0; i < rowsQuantityFirstMatrix; i++){
        for(int j = 0; j < columnsQuantitySecondMatrix; j++) {
            productOfMatrices[i][j] = 0;
        }
    }
    cout<<"\n";

    for(int i = 0; i < rowsQuantityFirstMatrix; i++) {
        for(int j = 0; j < columnsQuantitySecondMatrix; j++) {
            for(int k = 0; k < columnsQuantityFirstMatrix; k++) {
                productOfMatrices[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return productOfMatrices;
}

int** multiplyByScalar(int** matrixA, int rowsNumber, int columnsNumber, int scalar) {
    int** matrixByScalar = allocationInteger(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            matrixByScalar[i][j] = scalar * matrixA[i][j];
        }
    }
    return matrixByScalar;
}

double** multiplyByScalar(double** matrixA, int rowsNumber, int columnsNumber, double scalar){
    double** matrixByScalar = allocationDouble(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            matrixByScalar[i][j] = scalar * matrixA[i][j];
        }
    }
    return matrixByScalar;
}

int** transpozeMatrix(int** matrixA, int rowsNumber, int columnsNumber) {
    int** transposeMatrix = allocationInteger(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++){
        for(int j = 0; j < columnsNumber; j++) {
            transposeMatrix[j][i] = matrixA[i][j];
        }
    }
    return transposeMatrix;
}

double** transpozeMatrix(double** matrixA, int rowsNumber, int columnsNumber){
    double** transposeMatrix = allocationDouble(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++){
        for(int j = 0; j < columnsNumber; j++) {
            transposeMatrix[j][i] = matrixA[i][j];
        }
    }
    return transposeMatrix;
}

int** powerMatrix(int** matrixA, int rowsNumber, int columnsNumber, unsigned exponent) {
    int** matrixToPower = allocationInteger(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            matrixToPower[i][j] = 0;
        }
    }

    while((exponent - 1) > 0) {
        for (int i = 0; i < rowsNumber; i++) {
            for (int j = 0; j < columnsNumber; j++) {
                for (int k = 0; k < columnsNumber; k++) {
                    matrixToPower[i][j] = matrixA[i][k] * matrixA[k][j];
                }
            }
        }
        exponent--;
    }
    return matrixToPower;
}

double** powerMatrix(double** matrixA, int rowsNumber, int columnsNumber, unsigned exponent) {
    double** matrixToPower = allocationDouble(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            matrixToPower[i][j] = 0;
        }
    }

    while((exponent - 1) > 0) {
        for (int i = 0; i < rowsNumber; i++) {
            for (int j = 0; j < columnsNumber; j++) {
                for (int k = 0; k < columnsNumber; k++) {
                    matrixToPower[i][j] = matrixA[i][k] * matrixA[k][j];
                }
            }
        }
        exponent--;
    }
    return matrixToPower;
}

int determinantMatrix(int** matrixA, int rowsNumber, int columnsNumber) {
    int det = 0, mark = 1;
    int** tempMatrix = allocationInteger(rowsNumber, columnsNumber);
    if(rowsNumber == 1) {
        return matrixA[0][0];
    }
    if(rowsNumber == 2) {
        return (matrixA[0][0] * matrixA[1][1]) - (matrixA[0][1] * matrixA[1][0]);
    }
    for(int i = 0; i < rowsNumber; i++) {
        tmpMatrixInteger(matrixA, tempMatrix, 0, i, rowsNumber);
        det += mark * matrixA[0][i] * determinantMatrix(tempMatrix, rowsNumber - 1, columnsNumber);
        mark = -mark;
    }
    return det;
}
double determinantMatrix(double** matrixA, int rowsNumber, int columnsNumber) {
    double det = 0, mark = 1;
    double** tempMatrix = allocationDouble(rowsNumber, columnsNumber);
    if(rowsNumber == 1) {
        return matrixA[0][0];
    }
    if(rowsNumber == 2) {
        return (matrixA[0][0] * matrixA[1][1]) - (matrixA[0][1] * matrixA[1][0]);
    }
    for(int i = 0; i < rowsNumber; i++) {
        tmpMatrixDouble(matrixA, tempMatrix, 0, i, rowsNumber);
        det += mark * matrixA[0][i] * determinantMatrix(tempMatrix, rowsNumber - 1, columnsNumber);
        mark = -mark;
    }
    return det;
}

bool matrixIsDiagonal(int** matrixA, int rowsNumber, int columnsNumber) {
    int tmp = 0;
    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            if(i == j) {
                if(matrixA[i][j] == 0) {
                    tmp = 1;
                }
            } else {
                if(matrixA[i][j] != 0) {
                    tmp = 1;
                }
            }
        }
    }
    if(tmp == 1) {
        return false;
    } else {
        return true;
    }
}

bool matrixIsDiagonal(double** matrixA, int rowsNumber, int columnsNumber) {
    int tmp = 0;
    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            if(i == j) {
                if(matrixA[i][j] == 0) {
                    tmp = 1;
                }
            } else {
                if(matrixA[i][j] != 0) {
                    tmp = 1;
                }
            }
        }
    }
    if(tmp == 1) {
        return false;
    } else {
        return true;
    }
}

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;

}
void swap(double &a, double &b) {
    double temp;
    temp = a;
    a = b;
    b = temp;
}

int* sortRow(int* array, int columnsNumber) {
    for(int i = 0; i < columnsNumber - 1; i++) {
        for(int j = 0; j < columnsNumber - i - 1; j++) {
            if(array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

double* sortRow(double* array, int columnsNumber) {
    for(int i = 0; i < columnsNumber - 1; i++) {
        for(int j = 0; j < columnsNumber - i - 1; j++) {
            if(array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

int** sortRowsInMatrix(int** matrixA, int rowsNumber, int columnsNumber) {
    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            for(int k = 0; k < columnsNumber - j - 1; k++) {
                if(matrixA[i][k] > matrixA[i][k+1]) {
                    swap(matrixA[i][k], matrixA[i][k+1]);
                }
            }
        }
    }
}

double** sortRowsInMatrix(double** matrixA, int rowsNumber, int columnsNumber) {
    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            for(int k = 0; k < columnsNumber - j - 1; k++) {
                if(matrixA[i][k] > matrixA[i][k+1]) {
                    swap(matrixA[i][k], matrixA[i][k+1]);
                }
            }
        }
    }
}