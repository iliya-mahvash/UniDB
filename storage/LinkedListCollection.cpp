#include "LinkedListCollection.h"

using namespace std;

Node* head = new Node();
int size = 0;
double sumGpa = 0, average;
Node* last = new Node();
void LinkedListCollection:: insertOne(const Student& student) {
    if (size == 0) {
        head->data = student;
        head->prev = nullptr;
        head->next = last;
        last->prev = head;
    }
    else {
        last->data = student;
        Node* next = new Node();
        last->next = next;
        next->prev = last;
        last = next;
    }
    size++;
    sumGpa += student.gpa;
    average = sumGpa / size;
}

void LinkedListCollection::deleteOne(int id) {
    Node* iter = head;
    for (int i = 0; i < size; i++) {
        if (iter->data.id == id) {
            iter->next->prev = iter->prev;
            iter->prev->next = iter->next;
            sumGpa -= iter->data.gpa;
            break;
        }
    }
    size--;
    average = sumGpa / size;
}

Student* LinkedListCollection::findByID(int id) {
    Node* iter = head;
    for (int i = 0; i < size; i++) {
        if (iter->data.id == id) {
            return &iter->data;
        }
    }
    return nullptr;
}

vector<Student> LinkedListCollection::findAll() {
    vector<Student> all;
    Node* iter = head;
    for (int i = 0; i < size; i++) {
        all.push_back(iter->data);
        iter = iter->next;
    }
    return all;
}

vector<Student> LinkedListCollection::filter(string field, string value) {
    vector<Student> filtered;
    Node* iter = head;
    if (field == "gpa") {
        double gpa = stod(value);
        for (int i = 0; i < size; i++) {
            if (iter->data.gpa == gpa) {
                filtered.push_back(iter->data);
            }
            iter = iter->next;
        }
    }
    else if (field == "name") {
        for (int i = 0; i < size; i++) {
            if (iter->data.name == value) {
                filtered.push_back(iter->data);
            }
            iter = iter->next;
        }
    }

    else {
        int id = stoi(value);
        for (int i = 0; i < size; i++) {
            if (iter->data.id == id) {
                filtered.push_back(iter->data);
            }
            iter = iter->next;
        }
    }

    return filtered;
}
int LinkedListCollection::count() {
    return size;
}
double LinkedListCollection::sumGPA() {
    return sumGpa;
}
double LinkedListCollection::averageGPA() {
    return average;
}

LinkedListCollection::~LinkedListCollection() {
    Node* cur = head;
    for (int i = 0; i < size; i++) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
}
