#include <iostream>
#include <string>

using namespace std;

struct expression{
    string rawExpression;
    int evalExpression;
    expression* next;
};

class LL{
    private:
        expression* head;
        expression* tail;
    public:
        LL();
        void insertatend(string ex,int numb, expression* N);
        void merge(expression* headOfFirst, expression* headOfSecond);

        bool isempty();
        void printList(ofstream& outputFile, expression* N);
        void printPasscode(ofstream& outputFile, expression* N);
        void reverse(expression* N);
        bool del(int index, expression* h);
        int search(int numb, expression* h);
        expression* getHead();
        expression* getTail();
};