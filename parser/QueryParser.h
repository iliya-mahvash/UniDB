
#ifndef DATA_STRUCTURE_QUERYPARSER_H
#define DATA_STRUCTURE_QUERYPARSER_H
#include <vector>
#include <string>
#include <sstream>
#include "../models/Student.h"

using namespace std;

class QueryParser {
    public:
        static vector<string> tokenExtraction(string input);
        static string documentExtraction(string input);
        static void commandCreator(string input);
        vector<string> argExtractor(string input);
};

#endif //DATA_STRUCTURE_QUERYPARSER_H