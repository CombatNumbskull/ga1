#include <string>
#include <iostream>
#include <fstream>
#include "LL.h"

using namespace std;

LL::LL(){
    head = tail = nullptr;
}

void LL::insertatend(string ex, int eval, expression* N){
    expression* temp = new expression;
    temp->rawExpression = ex;
    temp->evalExpression = eval;
    temp->next = nullptr;
    if(isempty()){
        head = tail = temp;
    }else if(N->next == nullptr){
        N->next = temp;
        tail = temp;
        return;
    }else{
        insertatend(ex, eval, N->next);
    }
}

void LL::merge(expression* headOfFirst, expression* headOfSecond){
    expression* temp = headOfFirst;
    while(temp != nullptr){
        insertatend(temp->rawExpression, temp->evalExpression, head);
        temp = temp->next;
    }
    temp=headOfSecond;
    while(temp != nullptr){
        insertatend(temp->rawExpression, temp->evalExpression, head);
        temp = temp->next;
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

void LL::printList(ofstream& outputFile, expression* N){
    if(N ->next == nullptr){
        outputFile << N->evalExpression << "]" << endl;
        return;
    }else if(N)
    {
//        outputFile << N->rawExpression << " " << N->evalExpression << endl;
        outputFile << N->evalExpression << ", ";
        printList(outputFile, N->next);
    }
}

void LL::printPasscode(ofstream& outputFile, expression* N){
    if(N ->next == nullptr){
        outputFile << N->evalExpression << " |" << endl;
        return;
    }else if(N)
    {
//        outputFile << N->rawExpression << " " << N->evalExpression << endl;
        outputFile << N->evalExpression << " | ";
        printPasscode(outputFile, N->next);
    }
}

void LL::reverse(expression* N){
    expression* temp = new expression;
    if(N->next == nullptr){
        head = tail = N;
        return;
    }else{
        reverse(N->next);
        tail->next = N;
        tail = N;
        tail->next = nullptr;
        return;
    }
}

int LL::search(int numb, expression* h){
    if(h == nullptr){
        return -999;
    }else if(h->evalExpression == numb){
        return 0;
    }else{
        return 1 + search(numb, h->next);
    }
}

bool LL::del(int index, expression* h){
    if(isempty()){
        return false;
    }else if(index < 0){
        return false;
    }else if(index == 0 && h == head){
        head = h->next;
        delete h;
        return true;
    }else if(index == 1 && h->next == tail){
        tail = h;
        tail->next = nullptr;
        h = h->next;
        delete h ;
        return true;
    }else if(index == 1){
        expression* temp = h->next;
        h->next = h->next->next;
        delete temp;
        return true;
    }else if(index > 1){
        del(index - 1, h->next);
    }
}

expression* LL::getHead(){
    return head;
}
expression* LL::getTail(){
    return tail;
}
