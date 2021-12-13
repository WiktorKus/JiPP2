//
// Created by wiktor on 30.11.2021.
//

#ifndef LAB8_NOTE_H
#define LAB8_NOTE_H

class Note {
private:
    char* title;
public:
    char* getTitle();
    void setTitle();
    virtual void getContent();
    virtual void setContent();
};

class TextNote {
private:
    char* content;
public:
    void getContent();
    void setContent();
};

class NoteDirector {
private:
    char* notesList;
public:
    void addNote();
    void deleteNote();
    void editNote();
    void clearNotesList();
};

#endif //LAB8_NOTE_H
