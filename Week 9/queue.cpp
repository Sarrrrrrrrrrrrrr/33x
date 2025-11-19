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
    return Q.tail == max_QUEUE - 1;
}

void enqueue(QUEUE &Q, int x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else {
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    } else {
        cout << "Antrian Penuh!" << endl;
    }
}

int dequeue(QUEUE &Q) {
    if (!isEmptyQueue(Q)) {
        int dataKeluar = Q.info[Q.head];

        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            for (int i = 0; i < Q.tail; i++) {
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail--;
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