#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int data);
};

// LinkedList class
class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList();
    void addElements(const int* elements, int numElements);
    void insertElements(const int* elements, int numElements, int index);
    void deleteElement(int index);
    int findElement(int element);
    int binarySearch(int element);
    int getNodeValue(int index);
    void display();
    int size();
};

#endif
