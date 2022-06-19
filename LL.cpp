#include <string>
#include <iostream>
#include <fstream>
#include "LL.h"

using namespace std;

LL::LL(){
    head = tail = nullptr;
}

void LL::insertatend(string ex, expression* N){
    expression* temp = new expression;
    temp->rawExpression = ex;
    temp->evalExpression = 0;
    temp->next = nullptr;
    if(isempty()){
        head = tail = temp;
    }else if(N->next == nullptr){
        N->next = temp;
        tail = temp;
        return;
    }else{
        insertatend(ex, N->next);
    }
}

/*bool LL::pop(string& ex){
    expression* temp = head;
    if(isempty()){
        ex = "";
        return false;
    }else{
        ex = temp->rawExpression;
        head = head->next;
        delete temp;
        return true;
    }
}
*/
bool LL::isempty(){
    return (head == nullptr);
}

void LL::print(ofstream& outputFile, expression* N){
    if(N == nullptr){
        return;
    }else{
        outputFile << N->rawExpression << endl;
        print(outputFile, N->next);
    }
}

expression* LL::getHead(){
    return head;
}