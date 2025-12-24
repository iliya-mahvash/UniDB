#ifndef UNIDB_EXECUTIONENGINE_H
#define UNIDB_EXECUTIONENGINE_H
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include "../models/Student.h"
#include "../storage/Collection.h"

// Structure to store a snapshot of the collection for rollbacks [3]
struct TransactionState {
    std::vector<Student> snapshot;
};

// Structure to encapsulate a command for batch processing [1]
struct Command {
    std::string type;
    std::vector<std::string> args;
};

class ExecutionEngine {
private:
    // Pointer to the current Storage Engine (Layer 3) [4]
    Collection* currentCollection;

    // Stack to manage transaction states for rollbacks [1, 3]
    std::stack<TransactionState> transactionStack;

    // Queue to manage sequential execution of batch commands [1, 3]
    std::queue<Command> batchQueue;

    // Flag to track if the system is currently in batch mode [3]
    bool isBatchMode;

    // Helper method to display results to the console
    void displayResult(Student* student);

public:
    /**
     * Constructor: Initializes the engine with a default storage collection [4].
     */
    ExecutionEngine();

    /**
     * Main entry point for Layer 1 (Query Parser) to send commands [5].
     * @param commandType The operation to perform (e.g., "insertOne", "filter") [5].
     * @param args The parameters extracted from the query [5].
     */
    void executeCommand(std::string commandType, std::vector<std::string> args);

    // --- Transaction Management (Stack-based) [3, 6] ---
    
    /** Starts a transaction by pushing the current state onto the stack [3]. */
    void beginTransaction();

    /** Reverts the database to the last state stored in the stack [3, 6]. */
    void rollback();

    /** Finalizes changes and clears the transaction stack [3, 6]. */
    void commit();

    // --- Batch Processing (Queue-based) [3, 6] ---

    /** Enables batch mode, causing commands to be queued instead of executed [3]. */
    void startBatch();

    /** Executes all commands currently held in the batch queue sequentially [3, 6]. */
    void executeBatch();

    /** Destructor to clean up the storage engine [7]. */
    ~ExecutionEngine();
};

#endif //UNIDB_EXECUTIONENGINE_H