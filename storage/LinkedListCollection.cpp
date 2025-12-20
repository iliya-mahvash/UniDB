#include "../models/Student.h"
#include "Collection.h"
#include "vector"
#include "LinkedListCollection.h"
using namespace std;

struct Node {
    Student data;
    Node* next;
    Node* prev;
};

class LinkedListCollection {
    Node* head = new Node();
    int count = 0;
    double sumGpa = 0, average;
    Node* last = new Node();
    void insertOne(const Student& student) {
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
        count++;
        sumGpa += student.gpa;
        average = sumGpa / count;
    }

    void deleteOne(int id) {
        Node* iter = head;
        for (int i = 0; i < size; i++) {
            if (iter->data.id == id) {
                iter->next->prev = iter->prev;
                iter->prev->next = iter->next;
                sumGpa -= iter->data.gpa;
                break;
            }
        }
        count--;
        average = sumGpa / count;
    }

    Student* findByID(int id) {
        Node* iter = head;
        for (int i = 0; i < size; i++) {
            if (iter->data.id == id) {
                return &iter->data;
            }
        }
        return nullptr;
    }
    
    vector<Student> findAll() {
        vector<Student> all;
        Node* iter = head;
        for (int i = 0; i < size; i++) {
            all.push_back(iter->data);
            iter = iter->next;
        }
    }

    

};