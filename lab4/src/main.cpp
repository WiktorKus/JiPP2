#include <iostream>
#include <string>

using namespace std;

struct car {
    string mark;
    string model;
    int yearProduction;
    string color;
    int horsepower;
};

int sameCars(car cars[], int elementsInStruct) {
    int count = 0;
    for(int i = 0; i < elementsInStruct; i++) {
        for(int j = 0; j < elementsInStruct; j++) {
            if(cars[i].mark == cars[j].mark && i != j) {
                count++;
            }
        }
    }
    return count;
}

int main() {

        car cars[] = {{"Opel", "Astra", 1999, "red", 60},
                          {"Fiat", "Punto", 2001, "blue", 55},
                          {"Kia", "Ceed", 2006, "white", 101},
                          {"VW", "Passat", 2002, "grey", 150}};

        cout<<"Marka\tModel\tRok Produkcji\tKolor\tKonie mechaniczne"<<endl;

        for(int i = 0; i < 4; i++) {
            cout<<cars[i].mark<<"\t"<<cars[i].model<<"\t"<<cars[i].yearProduction<<"    \t"<<cars[i].color<<"\t"<<cars[i].horsepower<<endl;

        }
}
