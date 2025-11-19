#include "queue.h"
#include <iostream>

using namespace std;

void createQueue(QUEUE &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(QUEUE Q) {
    return Q.head == -1;
}

bool isFullQueue(QUEUE Q) {
    return (Q.tail == max_QUEUE - 1) && (Q.head == 0);
}

void enqueue(QUEUE &Q, int x) {
    if (isFullQueue(Q)) {
        cout << "Antrian Penuh!" << endl;
    } 
    else {
        if (Q.tail == max_QUEUE - 1 && Q.head > 0) {
            cout << ">> Penuh Semu! Menggeser elemen ke depan... <<" << endl;
            int tempHead = Q.head;
            int count = 0;
            for (int i = tempHead; i <= Q.tail; i++) {
                Q.info[i - tempHead] = Q.info[i];
                count++;
            }
            
            Q.head = 0;
            Q.tail = count - 1;
        }

        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

int dequeue(QUEUE &Q) {
    if (!isEmptyQueue(Q)) {
        int dataKeluar = Q.info[Q.head];

        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head++; 
        }
        return dataKeluar;
    } else {
        cout << "Antrian Kosong!" << endl;
        return -1;
    }
}

void printInfo(QUEUE Q) {
    cout << Q.head << " - " << Q.tail << " \t| "; 
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}