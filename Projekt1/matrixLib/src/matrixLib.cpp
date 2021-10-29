#include <iostream>
#include "../include/matrixLib.h"

using namespace std;

int** allocationInteger(int rowsNumber, int columnsNumber){ //funkcja ktora allokuje pamiec dla tablicy dwuwymiarowej typu int
    int** matrixToAlloc = new int *[rowsNumber];

    for(int i = 0; i < rowsNumber; i++) {
        matrixToAlloc[i] = new int[columnsNumber];
    }
    return matrixToAlloc;
}

double** allocationDouble(int rowsNumber, int columnsNumber){ //funkcja ktora allokuje pamiec dla tablicy dwuwymiarowej typu double
    double** matrixToAlloc = new double*[rowsNumber];

    for(int i = 0; i < rowsNumber; i++) {
        matrixToAlloc[i] = new double[columnsNumber];
    }
    return matrixToAlloc;
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

int** addMatrix(int** matrixA, int** matrixB, int rowsNumber, int columnsNumber) { //dodawanie dwoch macierzy dla typu int
    int** sumOfMatrices = allocationInteger(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            sumOfMatrices[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return sumOfMatrices;
}

double** addMatrix(double** matrixA, double** matrixB, int rowsNumber, int columnsNumber) { //dodawanie dwoch macierzy dla typu double
    double** sumOfMatrices = allocationDouble(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            sumOfMatrices[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return sumOfMatrices;
}

int** subtractMatrix(int** matrixA, int** matrixB, int rowsNumber, int columnsNumber) { //odejmowanie dwoch macierzy dla typu int
    int** differenceOfMatrices = allocationInteger(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            differenceOfMatrices[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return differenceOfMatrices;
}

double** subtractMatrix(double** matrixA, double** matrixB, int rowsNumber, int columnsNumber) { //odejmowanie dwoch macierzy dla typu double
    double** differenceOfMatrices = allocationDouble(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            differenceOfMatrices[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return differenceOfMatrices;
}

int** multiplyMatrix(int** matrixA, int** matrixB, int rowsQuantityFirstMatrix, int columnsQuantityFirstMatrix, int columnsQuantitySecondMatrix){
    int** productOfMatrices = allocationInteger(rowsQuantityFirstMatrix, columnsQuantitySecondMatrix); //mnozenie dwoch macierzy dla typu int

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
    double** productOfMatrices = allocationDouble(rowsQuantityFirstMatrix, columnsQuantitySecondMatrix); //mnozenie dwoch macierzy dla typu double

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

int** multiplyByScalar(int** matrixA, int rowsNumber, int columnsNumber, int scalar) { //mnozenie macierzy przez skalar dla typu int
    int** matrixByScalar = allocationInteger(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            matrixByScalar[i][j] = scalar * matrixA[i][j];
        }
    }
    return matrixByScalar;
}

double** multiplyByScalar(double** matrixA, int rowsNumber, int columnsNumber, double scalar){ //mnozenie macierzy przez skalar dla typu double
    double** matrixByScalar = allocationDouble(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++) {
        for(int j = 0; j < columnsNumber; j++) {
            matrixByScalar[i][j] = scalar * matrixA[i][j];
        }
    }
    return matrixByScalar;
}

int** transpozeMatrix(int** matrixA, int rowsNumber, int columnsNumber) { //transponowanie macierzy dla typu int
    int** transposeMatrix = allocationInteger(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++){
        for(int j = 0; j < columnsNumber; j++) {
            transposeMatrix[j][i] = matrixA[i][j];
        }
    }
    return transposeMatrix;
}

double** transpozeMatrix(double** matrixA, int rowsNumber, int columnsNumber){ //transponowanie macierzy dla typu double
    double** transposeMatrix = allocationDouble(rowsNumber, columnsNumber);

    for(int i = 0; i < rowsNumber; i++){
        for(int j = 0; j < columnsNumber; j++) {
            transposeMatrix[j][i] = matrixA[i][j];
        }
    }
    return transposeMatrix;
}

int** powerMatrix(int** matrixA, int rowsNumber, int columnsNumber, unsigned int exponent) { //podnoszenie macierzy do potegi dla typu int
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
                    matrixToPower[i][j] += matrixA[i][k] * matrixA[k][j];
                }
            }
        }
        exponent--;
    }
    return matrixToPower;
}

double** powerMatrix(double** matrixA, int rowsNumber, int columnsNumber, unsigned int exponent) { //podnoszenie macierzy do potegi dla typu double
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
                    matrixToPower[i][j] += matrixA[i][k] * matrixA[k][j];
                }
            }
        }
        exponent--;
    }
    return matrixToPower;
}

int determinantMatrix(int** matrixA, int rowsNumber, int columnsNumber) { //obliczanie wyznacznika macierzy dla typu int
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
double determinantMatrix(double** matrixA, int rowsNumber, int columnsNumber) { //obliczanie wyznacznika macierzy dla typu double
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

bool matrixIsDiagonal(int** matrixA, int rowsNumber, int columnsNumber) { //sprawdzanie czy macierz jest diagonalna, macierz typu int
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

bool matrixIsDiagonal(double** matrixA, int rowsNumber, int columnsNumber) { //sprawdzanie czy macierz jest diagonalna, macierz typu double
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

void swap(int &a, int &b) { //zamiana dwoch liczb dla typu int
    int temp;
    temp = a;
    a = b;
    b = temp;

}

void swap(double &a, double &b) { //zamiana dwoch liczb dla typu double
    double temp;
    temp = a;
    a = b;
    b = temp;
}

void sortRow(int* array, int columnsNumber) { //sorotwanie babelkowe tablicy dla typu int
    for(int i = 0; i < columnsNumber - 1; i++) {
        for(int j = 0; j < columnsNumber - i - 1; j++) {
            if(array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

void sortRow(double* array, int columnsNumber) { //sorotwanie babelkowe tablicy dla typu double
    for(int i = 0; i < columnsNumber - 1; i++) {
        for(int j = 0; j < columnsNumber - i - 1; j++) {
            if(array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

void sortRowsInMatrix(int** matrixA, int rowsNumber, int columnsNumber) { //sortowanie wszystkich wierszy w macierzy za pomoca sortowania babelkowego dla typu int
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

void sortRowsInMatrix(double** matrixA, int rowsNumber, int columnsNumber) { //sortowanie wszystkich wierszy w macierzy za pomoca sortowania babelkowego dla typu double
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

void help() {  //dokumentacja
    cout<<"DOKUMENTACJA\n\n";
    cout<<"Obliczenia na macierzach\n\n";
    cout<<"1. addMatrix [dodawanie dwoch macierzy]\nDzialanie addMatrix [macierz a] [macierz b]\n\tNalezy podac macierz a, macierz b, ilosc wierszy, ilosc kolumn\n\n";
    cout<<"2. subtractMatrix [odejmowanie dwoch macierzy]\nDzialanie subtractMatrix [macierz a] [macierz b]\n\tNalezy podac macierz a, macierz b ilosc wierszy, ilosc kolumn\n\n";
    cout<<"3. multiplyMatrix [mnozenie dwoch macierzy]\nDzialanie multiplyMatrix [macierz a] [macierz b]\n\tNalezy podac macierz a, macierz b, ilosc wierszy pierwszej macierzy, ilosc kolumn pierwszej macierzy, ilosc kolumn drugiej macierzy\n\n";
    cout<<"4. multiplyByScalar [mnozenie przez skalar]\nDzialanie multiplyByScalar [macierz a] [skalar]\n\tNalezy podac macierz a, ilosc wierszy, ilosc kolumn, skalar (takiego samego typu, jak macierz)\n\n";
    cout<<"5. transpozeMatrix [transponowanie macierzy]\nDzialanie transpozeMatrix [macierz a]\n\tNalezy podac macierz a, ilosc wierszy, ilosc kolumn\n\n";
    cout<<"6. powerMatrix [potegowanie macierzy]\nDzialanie powerMatrix [macierz a] [stopien potegi]\n\tNalezy podac macierz a, ilosc wierszy, ilosc kolumn, stopien potegi\n\n";
    cout<<"7. determinantMatrix [wyznacznik macierzy]\nDzialanie determinantMatrix [macierz a]\n\tNalezy podac macierz a, ilosc wierszy, ilosc kolumn\n\n";
    cout<<"8. matrixIsDiagonal [czy macierz jest diagonalna]\nDzialanie matrixIsDiagonal [macierz a]\n\tNalezy podac macierz a, ilosc wierszy, ilosc kolumn\n\n";
    cout<<"9. swap [zamiana dwoch wartosci miejscami]\nDzialanie swap [a] [b]\n\tNalezy podac liczbe a, liczbe b\n\n";
    cout<<"10. sortRow [sortowanie tablicy]\nDzialanie sortRow [tablica]\n\tNalezy podac tablice, ilosc kolumn\n\n";
    cout<<"11. sortRowsInMatrix [sortowanie wszystkich wierszy w macierzy]\nDzialanie sortRow [macierz a]\n\tNalezy podac macierz a, ilosc wierszy, ilosc kolumn\n\n";
}