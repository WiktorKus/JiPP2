#include <iostream>

using namespace std;

int add(int argv[0], int argv[1]) {
    return a + b;
}

int subtract(int argv[0], int argv[1]) {
    return a - b;
}

int volume() {

}

void help() {
    cout<<"";
}

int main(int argc, char *argv[]) {
    for(int i = 0; i < argc ; ++i) {
        cout << argv[i] <<endl;
    }

    return 0;
}


