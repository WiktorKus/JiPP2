#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

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
    srand(time(NULL));
    return rand() % b + a;
}

int maxInArray(int *array){
    int max = array[0];
    for(int i = 1; i < 10; i++) {
        if(max < array[i]) {
            max = array[i];
        }
    }
    return max;
}

void swapArray(int *array) {
    int tmp;
    for(int i = 9; i <= 0; i--) {
        tmp = array[i];
        array[i] = array[i - 1];
        array[i - 1] = tmp;
    }
}



int main() {

    int *array = new int[10];

    cout<<"Pole kwadratu z wartoscia int: = "<<square(5)<<"\nPole kwadratu z wartoscia double: = "<<square(6.15)<<endl;
    cout<<"Pole trojkata z jedna wartoscia: = "<<triangle(5)<<"\nPole trojkata z trzema wartosciami: ="<<triangle(3,4,5)<<endl;
    cout<<"Pole kola z wartoscia int: = "<<circle(5)<<"\nPole kola z wartoscia dobule: = "<<circle(5.75)<<endl;

    cout<<"Pseudolosowa liczba z przedzialu: <1, 100>: "<<randomNumber(1, 100)<<endl;

    for(int i = 0; i < 10; i++) {
        array[i] = rand() % 100 + 1;
        cout<<" "<<array[i]<<endl;
    }
    cout<<"Najwieszka liczba w tablicy to = "<<maxInArray(array);
    swapArray(array);

    for(int i = 0; i < 10; i++) {
        cout<<" "<<array[i]<<endl;
    }

    return 0;
}
