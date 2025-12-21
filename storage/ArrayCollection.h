#ifndef DATA_STRUCTURE_CLASS_H
#define DATA_STRUCTURE_CLASS_H
#include <vector>

#include "../models/Student.h"
#include "Collection.h"
using namespace std;


class ArrayCollection: public Collection {
private:
    vector<Student> students;
    public:
    ~ArrayCollection();
    void insertOne(const Student& student);
    void deleteOne(int id);
    Student* findByID(int id);
    vector<Student> findAll();
    vector<Student> filter(string field, string value);
    int count();
    double sumGPA();
    double averageGPA();
    //~Collection();
};


#endif //DATA_STRUCTURE_CLASS_H