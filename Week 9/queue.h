#ifndef QUEUE_H
#define QUEUE_H

#define max_QUEUE 5

struct QUEUE{
    int info[max_QUEUE];
    int head;
    int tail;
    
};

void createQueue(QUEUE &Q);

bool isEmpty(QUEUE Q);

bool isFull(QUEUE Q);

void enqueue(QUEUE&Q, int x);

int dequeue(QUEUE &Q);

void printInfo(QUEUE Q);

#endif