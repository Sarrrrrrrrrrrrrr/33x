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
    return ((Q.tail + 1) % max_QUEUE) == Q.head;
}

void enqueue(QUEUE &Q, int x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % max_QUEUE;
        }
        Q.info[Q.tail] = x;
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
            Q.head = (Q.head + 1) % max_QUEUE;
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
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % max_QUEUE;
        }
        cout << endl;
    }
}