#include "QueryParser.h"

vector<string> QueryParser::tokenExtraction(string input) {
    stringstream ss(input);
    string token;
    vector<string> tokens;
    while (std::getline(ss, token, '.')) {
        tokens.push_back(token);
    }
    return tokens;
}

string QueryParser::documentExtraction(string input) {
    int begin = input.find('(');
    int end = input.find(')');
    string document = input.substr(begin + 1, end - begin - 1);
    return document;
}

vector<string> QueryParser::argExtractor(string input) {
    vector<string> args;
    stringstream ss(input);
    string arg;
    while (getline(ss, arg, ',')) {
        args.push_back(arg);
    }
    return args;
}

void QueryParser::commandCreator(string input) {
    vector<string> tokens = QueryParser::tokenExtraction(input);
    if (tokens.size() == 2) {
        engine.executeCommand (tokens[1], vector<string>());
    }
    else if (tokens.size() == 3) {
        string operation = tokens[2];
        int pos = operation.find('(');
        operation.erase(pos);
        string document = QueryParser::documentExtraction(input);
        if (operation == "findByID" || operation == "import" || operation == "deleteOne") {
            engine.executeCommand (operation, vector<string>{document});
        }
        else {
            engine.executeCommand (operation, QueryParser::argExtractor(document));
        }
    }
    
}