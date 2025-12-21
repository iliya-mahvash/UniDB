
#ifndef DATA_STRUCTURE_COLLECTION_H
#define DATA_STRUCTURE_COLLECTION_H
#include "../models/Student.h"

class Collection {
public:
    virtual void insertOne(const Student& student) = 0;
    virtual void deleteOne(int id) = 0;
    virtual Student* findByID(int id) = 0;
    virtual vector<Student> findAll() = 0;
    virtual ~Collection() {};
};


#endif //DATA_STRUCTURE_COLLECTION_H