#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <sstream>

using namespace std;

const int MAX_SIZE = 100;

class Array {
private:
    int arr[MAX_SIZE];
    int size;

public:
    Array();
    void addElement(int element);
    void addElements();
    void insertElement(int element, int index);
    void deleteElement(int index);
    int findElement(int element);
    void display();
};

#endif
