#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    QUEUE Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q,2); 
    printInfo(Q);
    enqueue(Q,7);
    printInfo(Q);

    cout << "\n dequeue 1 Elemen" << endl;
    cout << "elemen keluar:" << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 1 elemen" << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\nDequeue 2 elemen" << endl;
    cout << "elemen keluar:" << dequeue(Q) << endl;
    cout << "elemen keluar:" <<dequeue <<endl;
    printInfo(Q);
    return 0;
}