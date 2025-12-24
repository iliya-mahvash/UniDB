#include "ExecutionEngine.h"
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include "../models/Student.h"
#include "../storage/ArrayCollection.h"
#include "../storage/LinkedListCollection.h"

using namespace std;

// Represents a stored state for the Transaction Stack
struct CollectionState {
    vector<Student> data;
};

private:
    Collection* currentCollection;
    stack<CollectionState> transactionStack; // [1], [3]
    queue<pair<string, vector<string>>> batchQueue; // [1], [3]
    bool isBatchMode = false;

    // Helper to print student info for find/filter commands
    void displayStudent(Student* s) {
        if (s) {
            cout << "{ id: " << s->id << ", name: \"" << s->name << "\", gpa: " << s->gpa << " }" << endl;
        } else {
            cout << "Student not found." << endl;
        }
    }

public:
    ExecutionEngine() {
        // Default to ArrayCollection as the initial storage engine [4, 5]
        currentCollection = new ArrayCollection();
    }

    // Main entry point for commands from the Query Parser [5-7]
    void executeCommand(string commandType, vector<string> args) {
        // If in batch mode, queue the command instead of executing immediately [3]
        if (isBatchMode && commandType != "batch.execute") {
            batchQueue.push({commandType, args});
            cout << "Command queued in batch: " << commandType << endl;
            return;
        }

        // Execution Logic based on Command Type [5, 8, 9]
        if (commandType == "insertOne") {
            // Args expected: {id, name, gpa}
            Student s = {stoi(args), args[10], stod(args[11])};
            currentCollection->insertOne(s);
            cout << "Successfully inserted student." << endl;

        } else if (commandType == "deleteOne") {
            currentCollection->deleteOne(stoi(args));
            cout << "Deleted student with ID: " << args << endl;

        } else if (commandType == "findByID") {
            Student* s = currentCollection->findByID(stoi(args));
            displayStudent(s);

        } else if (commandType == "findAll") {
            vector<Student> all = currentCollection->findAll();
            for (auto& s : all) displayStudent(&s);

        } else if (commandType == "filter") {
            // Args: {field, value}
            vector<Student> filtered = currentCollection->filter(args, args[10]);
            for (auto& s : filtered) displayStudent(&s);

        } else if (commandType == "count") {
            cout << "Total count: " << currentCollection->count() << endl;

        } else if (commandType == "sum") {
            cout << "GPA Sum: " << currentCollection->sumGPA() << endl;

        } else if (commandType == "average") {
            cout << "GPA Average: " << currentCollection->averageGPA() << endl;

        } else if (commandType == "beginTransaction") {
            beginTransaction();

        } else if (commandType == "rollback") {
            rollback();

        } else if (commandType == "commit") {
            commit();

        } else if (commandType == "batch.start") {
            isBatchMode = true;
            cout << "Batch mode started." << endl;

        } else if (commandType == "batch.execute") {
            executeBatch();
        }
    }

    // --- Transaction Management [3] ---

    void beginTransaction() {
        // Capture a snapshot of the current data and push it onto the stack [3]
        CollectionState state;
        state.data = currentCollection->findAll();
        transactionStack.push(state);
        cout << "Transaction started. State saved." << endl;
    }

    void rollback() {
        if (!transactionStack.empty()) {
            // Revert by popping from the stack [3]
            CollectionState lastState = transactionStack.top();
            transactionStack.pop();
            
            // Clear current and re-insert old state
            // Note: In a real implementation, a 'clear' method would be used in the Collection interface
            vector<Student> currentStudents = currentCollection->findAll();
            for (auto& s : currentStudents) {
                currentCollection->deleteOne(s.id);
            }
            for (auto& s : lastState.data) {
                currentCollection->insertOne(s);
            }
            cout << "Rollback successful. State restored." << endl;
        } else {
            cout << "No transaction to rollback." << endl;
        }
    }

    void commit() {
        // Finalize changes; in Phase 1, this clears the stack [3]
        // In later levels, this would trigger File Persistence [12]
        while (!transactionStack.empty()) transactionStack.pop();
        cout << "Transaction committed." << endl;
    }

    // --- Batch Processing [3] ---

    void executeBatch() {
        isBatchMode = false;
        cout << "Executing batch queue..." << endl;
        while (!batchQueue.empty()) {
            auto cmd = batchQueue.front();
            batchQueue.pop();
            executeCommand(cmd.first, cmd.second);
        }
        cout << "Batch execution complete." << endl;
    }

    ~ExecutionEngine() {
        delete currentCollection;
    }
};