#include "ArrayCollection.h"

int size = 0;
double average, sumGpa = 0;
vector<Student> students;
void ArrayCollection::insertOne(const Student& student) {
    students.push_back(student);
    size++;
    sumGpa += student.gpa;
    average = sumGpa / size;
}

void ArrayCollection::deleteOne(int id) {
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

Student* ArrayCollection::findByID(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            return &students[i];
        }
    }
    return nullptr;
}

vector<Student> ArrayCollection::findAll() {
    return students;
}

vector<Student> ArrayCollection::filter(string field, string value) {
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

int ArrayCollection::count() {
    return size;
}
double ArrayCollection::sumGPA() {
    return sumGpa;
}
double ArrayCollection::averageGPA() {
    return average;
}

ArrayCollection::~ArrayCollection() {
    students.clear();
}
