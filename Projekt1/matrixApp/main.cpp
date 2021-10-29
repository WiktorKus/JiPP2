#include <iostream>
#include "matrixLib.h"

using namespace std;

int** allocationForInteger(int rowsNumber, int columnsNumber){ //funkcja ktora allokuje pamiec dla tablicy dwuwymiarowej typu int
    int** matrixToAlloc = new int *[rowsNumber];

    for(int i = 0; i < rowsNumber; i++) {
        matrixToAlloc[i] = new int[columnsNumber];
    }
    return matrixToAlloc;
}

double** allocationForDouble(int rowsNumber, int columnsNumber){ //funkcja ktora allokuje pamiec dla tablicy dwuwymiarowej typu double
    double** matrixToAlloc = new double*[rowsNumber];

    for(int i = 0; i < rowsNumber; i++) {
        matrixToAlloc[i] = new double[columnsNumber];
    }
    return matrixToAlloc;
}

void printMatrixInteger(int** matrix, int rows, int columns) { //funkcja, ktora drukuje macierz, dla macierzy typu int
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void printMatrixDouble(double** matrix, int rows, int columns) { //funkcja, ktora drukuje macierz, dla macierzy typu double
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void getElementsInteger(int** matrix, int rows, int columns) { //pobiera od uzytkownika elementy do macierzy, dla macierzy typu int
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cin>>matrix[i][j];
        }
    }
}

void getElementsDouble(double** matrix, int rows, int columns) { //pobiera od uzytkownika elementy do macierzy, dla macierzy typu double
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cin>>matrix[i][j];
        }
    }
}

void deleteMatrixInteger(int** matrix, int rows){ //nastepuje dealokacja dla macierzy typu int
    for(int i = 0; i < rows; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

void deleteMatrixDouble(double** matrix, int rows){ //nastepuje dealokacja dla macierzy typu double
    for(int i = 0; i < rows; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

bool isCorrectAction(string action) { //funkcja, ktora sprawdza czy podane dzialanie zawiera sie w programie
    string operation[] = {"addMatrix", "subtractMatrix", "multiplyMatrix", "multiplyByScalar", "transpozeMatrix", "powerMatrix", "determinantMatrix", "matrixIsDiagonal", "swap", "sortRow", "sortRowsInMatrix"};
    for(string x : operation) {
        if(x == action) {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {

        int rowsQuantityFirstMatrix, rowsQuantitySecondMatrix, columnsQuantityFirstMatrix, columnsQuantitySecondMatrix;
        int **finalMatrixInteger;
        double **finalMatrixDouble;
        string type;
        string action = string(argv[1]);

        if (argc == 1) {
            help();
        } else if (argc == 2) {
            if (isCorrectAction(argv[1]) == false) { //sprawdzamy czy podana opcja jest mozliwa, jesli z funkcji otrzymujemy falsz to wyswietlamy nie ma takiej opcji
                cout << "Nie ma takiej opcji!\n\n";        //i wyswietlamy dokumentacje oraz konczymy program
                help();
                exit(0);
            }
        }
        cout << "Na jakiego typu macierzach chcesz operowac\nDo wyboru: integer lub double\nWpisz swoj wybor:";
        cin >> type;
        cout << "\n";

        if (type == "integer") { //jesli typ podany przez uzytkownika to integer to dzialamy na liczbach typu int i wszystkie funkcje sa wywolywane z int
            //informujemy uzytkownika, ze do podanych nizej dzialan posluzy pierwsza podana przez uzytkownika macierz
            cout<< "Do mnozenia przez skalar, transponowania macierzy, potegowania macierzy, liczenia wyznacznika, sprawdzania czy \nmacierz jest diagonalna, sortowania macierzy uzywana bedzie pierwsza podana macierz przez uzytkownika!!!\n\n";

            cout << "Podaj ilosc wierszy pierwszej macierzy: ";
            cin >> rowsQuantityFirstMatrix;
            cout << "\nPodaj ilosc kolumn pierwszej macierzy: ";
            cin >> columnsQuantityFirstMatrix;
            cout << "\nPodaj ilosc wierszy drugiej macierzy: ";
            cin >> rowsQuantitySecondMatrix;
            cout << "\nPodaj ilosc kolumn drugiej macierzy: ";
            cin >> columnsQuantitySecondMatrix;

            int **matrixA = allocationForInteger(rowsQuantityFirstMatrix, columnsQuantityFirstMatrix); //alokujemy dynamicznie pamiec dla pierwszej macierzy
            int **matrixB = allocationForInteger(rowsQuantitySecondMatrix, columnsQuantitySecondMatrix); //alokujemmy dynamicznie pamiec dla drugiej macierzy

            cout << "\nPodaj wartosci pierwszej macierzy: ";
            getElementsInteger(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);
            cout << "\nPodaj wartosci drugiej macierzy: ";
            getElementsInteger(matrixB, rowsQuantitySecondMatrix, columnsQuantitySecondMatrix);

            cout << "\nTwoja pierwsza macierz:\n";
            printMatrixInteger(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);

            cout << "Twoja druga macierz:\n";
            printMatrixInteger(matrixB, rowsQuantitySecondMatrix, columnsQuantitySecondMatrix);

            //za pomoca instrukcji warunkowych sprawdzamy, ktora opcja zostala wybrana
            if (action == "addMatrix") {
                finalMatrixInteger = addMatrix(matrixA, matrixB, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);
            }
            if (action == "subtractMatrix") {
                finalMatrixInteger = subtractMatrix(matrixA, matrixB, rowsQuantityFirstMatrix,
                                                    columnsQuantityFirstMatrix);
            }
            if (action == "multiplyMatrix") {
                finalMatrixInteger = multiplyMatrix(matrixA, matrixB, rowsQuantityFirstMatrix,
                                                    columnsQuantityFirstMatrix, columnsQuantitySecondMatrix);
            }
            if (action == "multiplyByScalar") {
                int scalar;
                cout << "\nPodaj skalar: ";
                cin >> scalar;
                finalMatrixInteger = multiplyByScalar(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix, scalar);
            }
            if (action == "transpozeMatrix") {
                finalMatrixInteger = transpozeMatrix(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);
            }
            if (action == "powerMatrix") {
                unsigned int exponent;
                cout << "Podaj potege do jakiej chcesz podniesc macierz: ";
                cin >> exponent;
                finalMatrixInteger = powerMatrix(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix, exponent);
            }
            if (action == "determinantMatrix") {
                int determinant;
                determinant = determinantMatrix(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);
                cout << "Wyznacznik = " << determinant << endl;
                exit(0);
            }
            if (action == "matrixIsDiagonal") {
                bool isDiagonal;
                isDiagonal = matrixIsDiagonal(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);
                if (isDiagonal == true) {
                    cout << "Macierz jest diagonalna" << endl;
                } else {
                    cout << "Macierz nie jest diagonalna" << endl;
                }
                exit(0);
            }
            if (action == "swap") {
                int a, b;
                cout << "Podaj dwie liczby do zamiany: ";
                cin>>a>>b;
                swap(a, b);
                cout << "Liczby po zamianie: " <<a<<", "<<b<<endl;
                exit(0);
            }
            if (action == "sortRow") {
                int *arrayToSort;
                int elements;
                cout << "Podaj ilosc elementow tablicy, ktora chcesz posortowac: ";
                cin >> elements;
                arrayToSort = new int[elements]; //alokacja pamieci dla tablicy jednowymiarowej
                cout << "Podaj elementy tablicy: ";
                for (int i = 0; i < elements; i++) {
                    cin >> arrayToSort[i];
                }
                sortRow(arrayToSort, elements);
                cout << "Posortowana tablica: ";
                for (int i = 0; i < elements; i++) {
                    cout<<" "<<arrayToSort[i];
                }
                delete[] arrayToSort; //dealokacja dla tablicy jednowymiarowej
                exit(0);
            }
            if (action == "sortRowsInMatrix") {
                sortRowsInMatrix(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);
                cout << "Posortowana macierz: \n";
                printMatrixInteger(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);
                exit(0);
            }
            if (action == "help") {
                help();
                exit(0);
            }

            cout << "\nMacierz po dzialaniach: \n";
            printMatrixInteger(finalMatrixInteger, rowsQuantityFirstMatrix, columnsQuantitySecondMatrix);

            deleteMatrixInteger(matrixA, rowsQuantityFirstMatrix); //dealokacja pamieci dla pierwszej macierzy
            deleteMatrixInteger(matrixB, rowsQuantitySecondMatrix); //dealokacja pamieci dla drugiej macierzy
            deleteMatrixInteger(finalMatrixInteger, rowsQuantityFirstMatrix); //dealokacja pamieci dla wynikowej macierzy

        } else if (type == "double") { //jesli typ podany przez uzytkownika to double to dzialamy na liczbach typu double i wszystkie funkcje sa wywolywane z double

            //informujemy uzytkownika, ze do podanych nizej dzialan posluzy pierwsza podana przez uzytkownika macierz
            cout<< "Do mnozenia przez skalar, transponowania macierzy, potegowania macierzy, liczenia wyznacznika, sprawdzania czy \nmacierz jest diagonalna, sortowania macierzy uzywana bedzie pierwsza podana macierz przez uzytkownika!!!\n\n";

            cout << "Podaj ilosc wierszy pierwszej macierzy: ";
            cin >> rowsQuantityFirstMatrix;
            cout << "\nPodaj ilosc kolumn pierwszej macierzy: ";
            cin >> columnsQuantityFirstMatrix;
            cout << "\nPodaj ilosc wierszy drugiej macierzy: ";
            cin >> rowsQuantitySecondMatrix;
            cout << "\nPodaj ilosc kolumn drugiej macierzy: ";
            cin >> columnsQuantitySecondMatrix;

            double **matrixA = allocationForDouble(rowsQuantityFirstMatrix, columnsQuantityFirstMatrix); //alokujemy dynamicznie pamiec dla pierwszej macierzy
            double **matrixB = allocationForDouble(rowsQuantitySecondMatrix, columnsQuantitySecondMatrix); //alokujemy dynamicznie pamiec dla drugiej macierzy

            cout << "\nPodaj wartosci pierwszej macierzy: ";
            getElementsDouble(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);
            cout << "\nPodaj wartosci drugiej macierzy: ";
            getElementsDouble(matrixB, rowsQuantitySecondMatrix, columnsQuantitySecondMatrix);

            cout << "\nTwoja pierwsza macierz:\n";
            printMatrixDouble(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);

            cout << "Twoja druga macierz:\n";
            printMatrixDouble(matrixB, rowsQuantitySecondMatrix, columnsQuantitySecondMatrix);

            if (action == "addMatrix") {
                finalMatrixDouble = addMatrix(matrixA, matrixB, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);
            }
            if (action == "subtractMatrix") {
                finalMatrixDouble = subtractMatrix(matrixA, matrixB, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);
            }
            if (action == "multiplyMatrix") {
                finalMatrixDouble = multiplyMatrix(matrixA, matrixB, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix, columnsQuantitySecondMatrix);
            }
            if (action == "multiplyByScalar") {
                double scalar;
                cout << "\nPodaj skalar: ";
                cin >> scalar;
                finalMatrixDouble = multiplyByScalar(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix, scalar);
            }
            if (action == "transpozeMatrix") {
                finalMatrixDouble = transpozeMatrix(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);
            }
            if (action == "powerMatrix") {
                unsigned int exponent;
                cout << "Podaj potege do jakiej chcesz podniesc macierz: ";
                cin >> exponent;
                finalMatrixDouble = powerMatrix(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix, exponent);
            }
            if (action == "determinantMatrix") {
                double determinant;
                determinant = determinantMatrix(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);
                cout << "Wyznacznik = " << determinant << endl;
                exit(0);
            }
            if (action == "matrixIsDiagonal") {
                bool isDiagonal;
                isDiagonal = matrixIsDiagonal(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);
                if (isDiagonal == true) {
                    cout << "Macierz jest diagonalna" << endl;
                } else {
                    cout << "Macierz nie jest diagonalna" << endl;
                }
                exit(0);
            }
            if (action == "swap") {
                double a, b;
                cout << "Podaj dwie liczby do zamiany: ";
                cin>>a>>b;
                swap(a, b);
                cout << "Liczby po zamianie: " <<a<<", "<<b<< endl;
                exit(0);
            }
            if (action == "sortRow") {
                double *arrayToSort;
                int elements;
                cout << "Podaj ilosc elementow tablicy, ktora chcesz posortowac: ";
                cin >> elements;
                arrayToSort = new double[elements]; //alokacja pamieci dla tablicy jednowymiarowej
                cout << "Podaj elementy tablicy: ";
                for (int i = 0; i < elements; i++) {
                    cin >> arrayToSort[i];
                }
                sortRow(arrayToSort, elements);
                cout << "Posortowana tablica: ";
                for (int i = 0; i < elements; i++) {
                    cout <<" "<<arrayToSort[i];
                }
                delete[] arrayToSort; //dealokacja pamieci dla tablicy jednowymiarowej
                exit(0);
            }
            if (action == "sortRowsInMatrix") {
                sortRowsInMatrix(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);
                cout << "Posortowana macierz: \n";
                printMatrixDouble(matrixA, rowsQuantityFirstMatrix, columnsQuantityFirstMatrix);
                exit(0);
            }
            cout << "\nMacierz po dzialaniach: \n";
            printMatrixDouble(finalMatrixDouble, rowsQuantityFirstMatrix, columnsQuantitySecondMatrix);

            deleteMatrixDouble(matrixA, rowsQuantityFirstMatrix); //dealokacja pamieci dla pierwszej macierzy
            deleteMatrixDouble(matrixB, rowsQuantitySecondMatrix); //dealokacja pamieci dla drugiej macierzy
            deleteMatrixDouble(finalMatrixDouble, rowsQuantityFirstMatrix); //dealokacja pamieci dla wynikowej macierzy
            if (action == "help") {
                help();
                exit(0);
            }
        } else {
            cout << "Podales nieprawidlowy typ!!\n";
            help();
            exit(0);
        }

        return 0;
}