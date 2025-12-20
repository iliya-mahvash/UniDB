#include "Collection.h"
#include "../models/Student.h"

class Collection {
public:
    virtual void insertOne(const Student& student) = 0;
    virtual void deleteOne(int id) = 0;
    virtual Student* findByID(int id) = 0;
    virtual vector<Student> findAll() = 0;
    virtual ~Collection() {};
    //virtual filter ??????
};
