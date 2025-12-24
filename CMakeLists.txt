cmake_minimum_required(VERSION 4.0)
project(UniDB)

set(CMAKE_CXX_STANDARD 14)

add_executable(main
        main.cpp
        parser/QueryParser.cpp
        parser/QueryParser.h
        storage/ArrayCollection.h
        storage/LinkedListCollection.h
        storage/ArrayCollection.cpp
        storage/LinkedListCollection.cpp
        storage/Collection.h
        engine/ExecutionEngine.cpp
        engine/ExecutionEngine.h
        engine/Command.cpp
        engine/Command.h
        engine/TransactionStack.cpp
        engine/TransactionStack.h
)