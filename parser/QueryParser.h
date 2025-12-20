
#ifndef DATA_STRUCTURE_QUERYPARSER_H
#define DATA_STRUCTURE_QUERYPARSER_H
#include <vector>
#include <sstream>
#include <string>
using namespace std;

struct Command {
    string collection;
    string operation;
    string document;
};


class QueryParser {
    public:
        vector<string> tokenExtraction(string input);
        string documentExtraction(string input);
        Command commandCreator(string input);
};


#endif //DATA_STRUCTURE_QUERYPARSER_H