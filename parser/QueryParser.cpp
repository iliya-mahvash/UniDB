#include "QueryParser.h"
#include "string"
#include <vector>
#include <sstream>
using namespace std;


vector<string> tokenExtraction(string input) {
    stringstream ss(input);
    string token;
    vector<string> result;
    while (std::getline(ss, token, '.')) {
        result.push_back(token);
    }
    return result;
}

string documentExtraction(string input) {
    int begin = input.find('(');
    int end = input.find(')');
    string document = input.substr(begin + 1, end - begin - 1);
    return document;
}
Command commandCreator(string input) {
    vector<string> tokens = tokenExtraction(input);
    string collection = tokens[1];
    string operation = tokens[2];
    int pos = operation.find('(');
    operation.erase(pos);
    string document = documentExtraction(input);
    Command command;
    command.collection = collection;
    command.operation = operation;
    command.document = document;
    return command;
}