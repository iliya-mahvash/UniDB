
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

class LinkedListCollection: public Collection {
public:
    void insertOne(const Student& student);
    void deleteOne(int id);
    Student* findByID(int id);
    vector<Student> findAll();
    vector<Student> filter(string field, string value);
    int count();
    double sumGPA();
    double averageGPA();
    ~Collection();
};


#endif //DATA_STRUCTURE_LINKEDLIISTCOLLECTION_H