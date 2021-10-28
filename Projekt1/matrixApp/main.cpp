#include <iostream>
#include "matrixLib.h"
using namespace std;

int** allocation(int rowsNumber, int columnsNumber){
    int** matrix = new int*[rowsNumber];

    for(int i = 0; i < rowsNumber; i++) {
        matrix[i] = new int[columnsNumber];
    }
    return matrix;
}

int main()
{ /*
    int columns, rows, rowsFirstMatrix, columnsFirstMatrix, columnsSecondMatrix, rowsSecondMatrix;
    int scalar = 5;
    //cout<<"Podaj liczbe wierszy: "<<endl;
    //cin >> rows;
    //cout<<"Podaj liczbe kolumn: "<<endl;
    //cin >> columns;

    //int matrixB[10][10], matrixA[10][10], matrix[10][10];

    cout<<"\nPodaj ilosc wierszy pierwszej macierzy";
    cin>>rowsFirstMatrix;
    cout<<"\nPodaj ilosc kolumn pierwszej macierzy";
    cin>>columnsFirstMatrix;
    //cout<<"\nPodaj ilosc wierszy drugiej macierzy";
    //cin>>rowsSecondMatrix;
    //cout<<"\nPodaj ilosc kolumn drugiej macierzy";
    //cin>>columnsSecondMatrix;

    int** matrixA = allocation(rowsFirstMatrix, columnsFirstMatrix);
    int** matrixB = allocation(rowsSecondMatrix, columnsSecondMatrix);
    int** matrix =  allocation(rowsFirstMatrix, columnsFirstMatrix);

    cout<<"Podaj pierwsza macierz: "<<endl;
    for(int i = 0; i < rowsFirstMatrix; i++) {
        for(int j = 0; j < columnsFirstMatrix; j++) {
            cin>>matrixA[i][j];
        }
    }

    for(int i = 0; i < rowsFirstMatrix; i++) {
        for(int j = 0; j < columnsFirstMatrix; j++) {
            cout<<" "<<matrixA[i][j];
        }
        cout<<"\n";
    }


    for(int i = 0; i < rowsFirstMatrix; i++) {
        for(int j = 0; j < columnsFirstMatrix; j++) {
            matrix[j][i] = matrixA[i][j];
        }
    }

    for(int i = 0; i < columnsFirstMatrix; i++){
        for(int j = 0; j < rowsFirstMatrix; j++) {
            cout<<" "<<matrix[i][j];
        }
        cout<<"\n";
    }*/
    cout<<"DZIALA";
    return 0;
}