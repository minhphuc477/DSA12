#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

#define MAX_SIZE 100

using namespace std;

// Queue class
class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int element);
    int dequeue();
    void display();
    void addMultipleElements(int elements[], int numElements);
};

#endif
