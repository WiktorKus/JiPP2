#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

double PI = 3.14;

int square(int a) {
    return pow(a, 2);
}

double square(double a) {
    return pow(a, 2);
}

double triangle(double a) {
    return (pow(a,2) * sqrt(3)) / 4;
}

double triangle(double a, double b, double c){
    double p;
    p = (a + b + c) / 2;
    return sqrt(p * (p-a) * (p-b) * (p-c));
}

int circle(int r) {
    return PI * pow(r, 2);
}

double circle(double r){
    return PI * pow(r,2);
}

int randomNumber(int a, int b) {
    srand(time(nullptr));
    return rand() % b + a;
}

int maxInArray(const int *array){
    int max = array[0];
    for(int i = 1; i < 10; i++) {
        if(max < array[i]) {
            max = array[i];
        }
    }
    return max;
}

void swapArray(int *array) {
    for(int i = 9; i >= 0; i --) {
        cout<<array[i]<<" ";

    }
}

double average(const double *number1, const double *number2) {
    double avg;
    avg = (*number1 * *number2) / 2;
    return avg;
}

void moreThanZero(int *array) {
    for(int i = 0; i < 10; i++) {
        if(array[i] > 0) {
           cout<<array[i]<<" ";
        }
    }
}

void sort(int *number1, int *number2, int *number3) {
    if(*number1 > *number2) {
        swap(*number1, *number2);
    }
    if(*number1 > *number3) {
        swap(*number1, *number3);
    }
    if(*number2 > *number3) {
        swap(*number2, *number3);
    }
}

void insertNumber(int x, int *w) {
    *w = x;
}

int division(int a, int b) {
    if(b == 0) {
        throw "Dzielenie przez 0\n";
    }
    return a/b;

}

int main() {

    int *array = new int[10];

    int array2[10] = {0, 1, 2, 0, 10, 3, -5, -6};

    double number1 = 3.5;
    double number2 = 4.9;

    double *wskNumber1 = &number1;
    double *wskNumber2 = &number2;

    int num1 = 7;
    int num2 = 10;
    int num3 = 3;

    int x = 10;
    int number;
    int *w = &number;

    int a = 10;
    int b = 0;

    string text;
    int temp;

    cout<<"ZADANIE 1\nPole kwadratu z wartoscia int: = "<<square(5)<<"\nPole kwadratu z wartoscia double: = "<<square(6.15)<<endl;
    cout<<"Pole trojkata z jedna wartoscia: = "<<triangle(5)<<"\nPole trojkata z trzema wartosciami: = "<<triangle(3,4,5)<<endl;
    cout<<"Pole kola z wartoscia int: = "<<circle(5)<<"\nPole kola z wartoscia dobule: = "<<circle(5.75)<<endl;

    cout<<"\nZADANIE 2\nPseudolosowa liczba z przedzialu: <1, 100>: "<<randomNumber(1, 100)<<endl;

    for(int i = 0; i < 10; i++) {
        array[i] = rand() % 100 + 1;
    }

    cout<<"\nZADANIE 3\nNajwieszka liczba w tablicy to = "<<maxInArray(array)<<endl;

    cout<<"\nZADANIE 4\n";
    swapArray(array);

    cout<<"\n\nZADANIE 5\nSrednia dwoch liczb "<<*wskNumber1<<" i "<<*wskNumber2<<" = "<<average(wskNumber1, wskNumber2)<<endl;

    cout<<"\nZADANIE 6\n";
    moreThanZero(array2);

    cout<<"\n\nZADANIE 7";
    sort(&num1, &num2, &num3);

    cout<<"\nPosortowane liczby: "<<" "<<num1<<" "<<num2<<" "<<num3<<endl;

    insertNumber(x, w);

    cout<<"\nZADANIE 8\nLiczba x: "<<x<<" zostala umieszczona w zmiennej \"number\" "<<number<<endl;

    cout<<"\nZADANIE 9\n";
    try {
        cout << "Wynik dzielenia = " << division(a, b) << endl;
    }catch(const char* msg) {
        cout<<msg<<endl;
    }

    cout<<"ZADANIE 10"<<endl;
    try {
        cout << "Podaj ciag znakow: ";
        cin >> text;
        temp = stoi(text, nullptr, 10);
        cout << "\n" << temp << endl;
    }catch(invalid_argument& e) {
        cout<<"Nieprawidlowe znaki!"<<endl;
    }catch(out_of_range& e) {
        cout<<"Wprowadzana liczba jest za duza!"<<endl;
    }

    return 0;
}
