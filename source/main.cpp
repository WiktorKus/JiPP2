#include"../include/Player.h"
#include <iostream>
#include<string>

using namespace std;

int main() {

    Player userPlayList;
    string selection = "null";

    cout<<"\n";
    while(selection != "wyjdz") {

        cout<<"Akcje do wykonania: \n";
        cout<<"Pusc muzyke -- <pusc>\nPokaz liste utworow -- <pokaz>\nDodaj utwor -- <dodaj>\nUsun utwor -- <usun>\nWyjscie -- <wyjdz>\n";
        cout<<"Podaj wybor: ";
        cin>>selection;

        if (selection == "pusc") {
            userPlayList.play();
        } else if (selection == "pokaz") {
            userPlayList.showList();
        } else if (selection == "dodaj") {
            userPlayList.addSong();
        } else if (selection == "usun") {
            userPlayList.removeSong();
        } else {
            cout << "Niepoprawna operacja\n" << endl;
        }
    }
    return 0;
}