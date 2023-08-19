#pragma once
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

#define MAX_SIZE 100

using namespace std;

// Stack class
class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack();
    bool isEmpty();
    bool isFull();
    void push(const int elements[], int size);
    int pop();
    void display();
    int binaryToDecimal(string binary);
    string decimalToBinary(int decimal);
};

#endif