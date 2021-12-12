//
// Created by wiktor on 12.12.2021.
//

#include "../include/Player.h"
#include <iostream>
#include <vector>
#include <limits>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

void Player::play() {

    cout<<"Obecny utwor\n"<<endl;
    int i=1;
    for(auto& song : list)
    {
        cout<< i <<song<<"\n";
        sleep_for(seconds (25));
        i++;
    }
}

//Pokazywanie listy utworów
void Player::showList() {

    cout<<"Twoja playlist\n"<<endl;
    int i=1;
    for(auto& song : list)
    {
        cout<< i <<song<<"\n";
        i++;
    }
}

//Dodawanie piosenek
void Player::addSong() {

    string newSong;

    cout<<"Dodawanie piosenki\nWpisz artyste i tytuł\n";

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,newSong);

    vector<string>::iterator i;

    for(i = list.begin(); i != list.end(); i++) {
        list.push_back(newSong);
    }

    cout<<"Pomyslnie dodano utwor: "<<newSong<<endl;
}

//Usuwanie piosenek
void Player::removeSong() {

    int songToRemove = 0;

    cout<<"Usuwanie utworu\nWpisz numer utworu do usuniecia\n";
    cin>>songToRemove;

    list.erase(list.begin() + songToRemove);

    cout<<"Pomyślnie usunieto utwor"<<endl;


}
