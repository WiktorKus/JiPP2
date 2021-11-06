#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define PI 3.14

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

int yearProductionLowest(car cars[], int elementsInStruct) {
    int index = 0;
    int tmp = cars[0].yearProduction;
    for(int i = 1; i < elementsInStruct; i++) {
        if(tmp > cars[i].yearProduction) {
            tmp = cars[i].yearProduction;
            index++;
        }
    }
    return index;
}

class Cuboid {
private:
    int baseField;
    int sideField1;
    int sideField2;
public:
    Cuboid(int baseField, int sideField1, int sideField2) {
        this->baseField = baseField;
        this->sideField1 = sideField1;
        this->sideField2 = sideField2;
    };
    int cuboidField() {
        return (2 * baseField) + (2 * sideField1) + (2 * sideField2);
    }
};

class Sphere {
private:
    double r;
public:
    Sphere(int r) {
        this->r = r;
    }
    double sphereVolume() {
        return PI * r * r;
    }
};

class QuadraticFunction {
private:
    int a;
    int b;
    int c;
public:
    QuadraticFunction(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void showQuadraticFunction() {
        cout<<"Funkcja kwadratowa: "<<a<<"x^2 + "<<b<<"x + "<<c<<endl;
    }
};

class Student{
private:
    string firstName;
    string surname;
    int numAlbum;
    int numberQuestions;
    int correctAnswers;
public:
    Student(string firstName, string surname, int numAlbum, int numberQuestions, int correctAnswers) {
        this->firstName = firstName;
        this->surname = surname;
        this->numAlbum = numAlbum;
        this->numberQuestions = numberQuestions;
        this->correctAnswers = correctAnswers;
    }
    void printStudentData() {
        cout<<"Imie studenta: "<<firstName<<" Nazwisko studenta: "<<surname<<" Numer albumu: "<<numAlbum<<" Liczba pytan: "<<numberQuestions<<" Liczba poprawnych odpowiedzi: "<<correctAnswers<<endl;
    }
    double percentCorrectAnswers() {
        return correctAnswers/(double)numberQuestions * 100;
    };
};

class Point{
public:
    int x1;
    int y1;
    int x2;
    int y2;
    Point(int x1, int y1, int x2, int y2){
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
    double distance(){
        return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    }

};

class Figure{
public:
    int numberVertices;
    int* verticesArray;
    Figure(int numberVertices, int* verticesArray);
};

Figure::Figure(int numberVertices, int* verticesArray) : numberVertices(numberVertices), verticesArray(verticesArray){
    cout<<"\n\nWierzcholki figury: "<<endl;
    for(int i = 0; i < numberVertices; i++) {
        cout<<verticesArray[i]<<" ";
    }
}

class Destructor {
public:
    int* array;
    Destructor();
    ~Destructor();
    void pauseFunction();
};

Destructor::Destructor() {
    cout<<"\n\nWywolany"<<endl;
    array = new int[1024];
}

void Destructor::pauseFunction() {
    system("pause");
}

Destructor::~Destructor() {
    cout<<"Dowolny tekst"<<endl;
    delete[] array;

}

int main() {

        car cars[] = {{"Opel", "Astra", 2012, "red", 60},
                          {"Fiat", "Punto", 2007, "blue", 55},
                          {"Kia", "Ceed", 2006, "white", 101},
                          {"VW", "Passat", 2002, "grey", 150}};

        cout<<"Marka\tModel\tRok Produkcji\tKolor\tKonie mechaniczne"<<endl;

        for(int i = 0; i < 4; i++) {
            cout<<cars[i].mark<<"\t"<<cars[i].model<<"\t"<<cars[i].yearProduction<<"    \t"<<cars[i].color<<"\t"<<cars[i].horsepower<<endl;

        }

        cout<<"\nLiczba samochodow, ktore sa tej same marki = "<<sameCars(cars, 4)<<endl;

        cout<<"\nNajnizszy rok produkcji ma samochod o indeksie = "<<yearProductionLowest(cars, 4)<<endl;

        Cuboid myCuboid(4, 4, 4);
        cout<<"\nPole prostopadloscianu = "<<myCuboid.cuboidField()<<endl;

        Sphere mySphere(4.3);
        cout<<"\nObjetosc kuli = "<<mySphere.sphereVolume()<<endl;

        cout<<"\n";
        QuadraticFunction myQuadraticFunction(10,5,2);
        myQuadraticFunction.showQuadraticFunction();
        cout<<"\n";

        Student myStudent("Wiktor", "Kus", 13812, 20, 18);
        myStudent.printStudentData();
        cout<<"Procent poprawnych odpowiedzi: "<<myStudent.percentCorrectAnswers()<<"%"<<endl;

        Point myPoint(4, 3, 2, 9);
        cout<<"\nDystans miedzy punktami = "<<myPoint.distance();

        int verticesArray[6] = {1, 2, 4, 8, 2, 7};
        Figure myFigure(6, verticesArray);

        Destructor *destructor;
        destructor = new Destructor;
        destructor->pauseFunction();
        delete destructor;

        return 0;
}
