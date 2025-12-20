#ifndef DATA_STRUCTURE_CLASS_H
#define DATA_STRUCTURE_CLASS_H
#include "../models/Student.h"
#include "Collection.h"


class ArrayCollection {
    void insertOne(const Student& student);
    void deleteOne(int id);
    Student* findByID(int id);
    vector<Student> findAll();
    ~Collection();
};


#endif //DATA_STRUCTURE_CLASS_H