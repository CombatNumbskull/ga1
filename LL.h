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
        void insertatend(string ex, expression* N);

        bool isempty();
        void print(ofstream& outputFile, expression* N);
        expression* getHead();
};