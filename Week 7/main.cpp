#include "stack.h"
#include <iostream>
using namespace std;

int main() {
  cout <<"Hello World" << endl;
    Stack S; 
    CreateStack(S);
    push(S, 3); 
    push(S, 4); 
    push(S, 8); 
    pop(S); 
    push(S, 2); 
    push(S, 3); 
    pop(S); 
    push(S, 9); 
    printInfo(S);

    cout << "Balik stack:" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
