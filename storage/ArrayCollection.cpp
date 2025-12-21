#include "vector"
#include "ArrayCollection.h"
using namespace std;

int size = 0;
double average, sumGpa = 0;
vector<Student> students;
void insertOne(const Student& student) {
    students.push_back(student);
    size++;
    sumGpa += student.gpa;
    average = sumGpa / size;
}

void deleteOne(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            sumGpa -= students[i].gpa;
            students.erase(students.begin() + i);
            break;
        }
    }
    size--;
    average = sumGpa / size;
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

vector<Student> filter(string field, string value) {
    vector<Student> filtered;
    if (field == "gpa") {
        double gpa = stod(value);
        for (int i = 0; i < students.size(); i++) {
            if (students[i].gpa == gpa) {
                filtered.push_back(students[i]);
            }
        }
    }
    else if (field == "id") {
        int id = stoi(value);
        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                filtered.push_back(students[i]);
            }
        }
    }
    else {
        for (int i = 0; i < students.size(); i++) {
            if (value == students[i].name) {
                filtered.push_back(students[i]);
            }
        }
    }
    return filtered;
}

int count() {
    return size;
}
double sumGPA() {
    return sumGpa;
}
double averageGPA() {
    return average;
}