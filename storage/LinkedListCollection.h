
#ifndef DATA_STRUCTURE_LINKEDLIISTCOLLECTION_H
#define DATA_STRUCTURE_LINKEDLIISTCOLLECTION_H
#include "../models/Student.h"
#include "Collection.h"
#include "vector"

struct Node {
    Student data;
    Node* next;
    Node* prev;
};

class LinkedListCollection {
    void insertOne(const Student& student);
    void deleteOne(int id);
    Student* findByID(int id);
    vector<Student> findAll();
    ~Collection();
};


#endif //DATA_STRUCTURE_LINKEDLIISTCOLLECTION_H