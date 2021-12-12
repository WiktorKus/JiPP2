//
// Created by wiktor on 12.12.2021.
//

#ifndef LAB9_PLAYER_PLAYER_H
#define LAB9_PLAYER_PLAYER_H

#include <iostream>
#include <vector>

using namespace std;

class Player {
private:
    vector <string> list;
public:
    void play(); //odtwarza utwory
    void showList(); //funkcja, która pokazuje liste piosenek
    void addSong(); //funkcja, która dodaje piosenke do playlist
    void removeSong(); //funkcja, która usuwa piosenke z playlist
};

#endif //LAB9_PLAYER_PLAYER_H
