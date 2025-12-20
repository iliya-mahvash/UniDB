#include "Collection.h"
#include "vector"
#include "ArrayCollection.h"
using namespace std;

class ArrayCollection {
    int count = 0;
    double average, sumGpa = 0;
    vector<Student> students;
    void insertOne(const Student& student) {
        students.push_back(student);
        count++;
        sumGpa += student.gpa;
        average = sumGpa / count;
    }

    void deleteOne(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                sumGpa -= students[i].gpa;
                students.erase(students.begin() + i);
                break;
            }
        }
        count--;
        average = sumGpa / count;
    }

    Student* findByID(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                return &students[i];
            }
        }
        return nullptr;
    }

    vector<Student> findAll() {
        return students;
    }
};