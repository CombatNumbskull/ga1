#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include "LL.cpp"
#include "ArgumentManager.h"

using namespace std;

//void readInput(ifstream& inputFile);
bool balance(string line);
int evalExpression(string line);
int operation(char op, int n1, int n2);


int invalid = 0;

int main(int argc, char *argv[]){
    
    ArgumentManager am(argc, argv);
    string infilename = am.get("input");
    string outfilename = am.get("output");

//    ifstream inputFile("input12.txt");
//    ofstream outputFile("output12.txt");

    ifstream inputFile(infilename);
   ofstream outputFile(outfilename);

    if (!inputFile.is_open()){
        outputFile << "Error opening input file.";
        outputFile.close();
        return 0;
    }

    string line, actualPasscode;
    char mode;
    LL Sarah, Alex;
    stack<int> negativeNumb;
    int numb;

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
                numb = evalExpression(line);
                if(evalExpression(line) < 0){
//                    outputFile << "Negative Number: " << numb << endl;
                    negativeNumb.push(numb);
                }else{
//                    outputFile << "Postive Number: " << numb << endl;
                    Sarah.insertatend(line, numb, Sarah.getHead());
                }
            }else if(mode == 'A' && balance(line)){
                numb = evalExpression(line);
                if(evalExpression(line) < 0){
//                    outputFile << "Negative Number: " << numb;
                    negativeNumb.push(numb);
                }else{
//                    outputFile << "Postive Number: " << numb;
                    Alex.insertatend(line, numb, Alex.getHead());
                }
            }
        }
    }
    
    outputFile << "Sarah: [";
    Sarah.printList(outputFile, Sarah.getHead());
    outputFile << "Alex: [";
    Alex.printList(outputFile,Alex.getHead());

    LL mergeList;
    mergeList.merge(Sarah.getHead(), Alex.getHead());
    mergeList.reverse(mergeList.getHead());

    outputFile << "Decoded passcode: | ";
    mergeList.printPasscode(outputFile, mergeList.getHead());
    outputFile << "Actual passcode:";
    for(int i = 0; i < actualPasscode.length(); i++){
        outputFile << " | " << actualPasscode[i];
    }
    outputFile << " |" << endl;
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
    if(!s.empty())
        return false;
    return true;
}

int evalExpression(string line){
    stack<int> numbers;
    stack<char> op;
    string listOfNumb = "0123456789";
    string symbols = "+-";
    int sum = 0;
    char top;
    int n1, n2;
    
    for(int i = 0; i < line.length();i++){
        if(listOfNumb.find(line[i]) != std::string::npos){
            numbers.push(line[i] - '0');
        }else if(line[i] == '('|| line[i] == '[' || line[i] == '{'){
            op.push(line[i]);
        }else if(symbols.find(line[i]) != std::string::npos){
            if(op.empty() || op.top() == '(' || op.top() == '[' || op.top() == '{'){
                op.push(line[i]);
            }else{
                top = op.top();
                op.pop();
                n2 = numbers.top();
                numbers.pop();
                n1 = numbers.top();
                numbers.pop();
                
                numbers.push(operation(top, n1, n2));
                op.push(line[i]);
            }
        }else if(line[i] == ')'){
            while(op.top() != '('){
                top = op.top();
                op.pop();
                n2 = numbers.top();
                numbers.pop();
                n1 = numbers.top();
                numbers.pop();
                
                numbers.push(operation(top, n1, n2));
            }
            op.pop();
        }else if(line[i] == ']'){
            while(op.top() != '['){
                top = op.top();
                op.pop();
                n2 = numbers.top();
                numbers.pop();
                n1 = numbers.top();
                numbers.pop();
                
                numbers.push(operation(top, n1, n2));
            }
            op.pop();
        }else if(line[i] == '}'){
            while(op.top() != '{'){
                top = op.top();
                op.pop();
                n2 = numbers.top();
                numbers.pop();
                n1 = numbers.top();
                numbers.pop();
                
                numbers.push(operation(top, n1, n2));
            }
            op.pop();
        }
    }

    while(!op.empty()){
        top = op.top();
        op.pop();
        n2 = numbers.top();
        numbers.pop();
        n1 = numbers.top();
        numbers.pop();
                
        numbers.push(operation(top, n1, n2));
    }

    return numbers.top();
}

int operation(char op, int n1, int n2){
    if(op == '+')
        return n1 + n2;
    else
        return n1 - n2;
}