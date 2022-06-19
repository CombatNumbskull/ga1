#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include "LL.h"
#include "ArgumentManager.h"

using namespace std;

void readInput(ifstream& inputFile);
bool balance(string line);
int evalExpression(string line);

int invalid = 0;

int main(int argc, char *argv[]){
    
    ArgumentManager am(argc, argv);
    string infilename = am.get("input");
    string outfilename = am.get("output");

    ifstream inputFile("input11.txt");
    ofstream outputFile("output11.txt");

    if (!inputFile.is_open()){
        outputFile << "Error opening input file.";
        outputFile.close();
        return 0;
    }

    string line, actualPasscode;
    char mode;
    LL Sarah, Alex;

    while(getline(inputFile, line)){
        if(line.empty())
            continue;
        else if(line[0] == 'S'){
            mode = line[0];
        }else if(line[0] == 'A'){
            mode = line[0];
        }else if(line[0] == 'P'){
            actualPasscode = line.substr(line.find(':') + 1);
        }else{
            if(mode == 'S' && balance(line)){
                Sarah.insertatend(line, Sarah.getHead());
            }else if(mode == 'A' && balance){
                Alex.insertatend(line, Alex.getHead());
            }
        }
    }
    
    outputFile << "Sarah:" << endl;
    Sarah.print(outputFile, Sarah.getHead());
    outputFile << "Alex:" << endl;
    Alex.print(outputFile,Alex.getHead());

/*
    while(!Sarah.isempty()){
        Sarah.pop(line);
        outputFile << line << endl;
    }
    Sarah.pop(line);
    outputFile << line << endl;
    while(!Alex.isempty()){
        Alex.pop(line);
        outputFile << line << endl;
    }
    Alex.pop(line);
    outputFile << line << endl;

    outputFile << actualPasscode << endl;
    */

}

bool balance(string line){
    stack<char> s;
    for(int i = 0; i < line.length(); i++){
        switch(line[i]){
            case '(':
                s.push(line[i]);
                break;
            case '[':
                s.push(line[i]);
                break;
            case '{':
                s.push(line[i]);
                break;
            case ')':
                if(s.top() != '('){
                    invalid++;
                    return false;
                }
                s.pop();
                break;
            case ']':
                if(s.top() != '['){
                    invalid++;
                    return false;
                }
                s.pop();
                break;
            case '}':
                if(s.top() != '{'){
                    invalid++;
                    return false;
                }
                s.pop();
                break;
            default:
                break;
        }
    }
    return true;
}

int evalExpression(string line){
    stack<int> operand;
    stack<char> operator;
    string symbols
    
    for(int i = 0; i < line.length();i++){
        switch(line[i]){
            if(line[i].)
        }
    }
}