
#ifndef UNIDB_TRANSACTIONSTACK_H
#define UNIDB_TRANSACTIONSTACK_H
#include "stack"

class TransactionStack {
public:
    void beginTransaction();
    void rollback();
    void commit();
};


#endif //UNIDB_TRANSACTIONSTACK_H