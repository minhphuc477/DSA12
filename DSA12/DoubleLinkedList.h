#pragma once
#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>

using namespace std;

// Node struct
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// DoubleLinkedList class
class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList();
    bool isEmpty();
    void displayList();
    void addElement(int element);
    void addElementAtBegin(int element);
    void addElementAtEnd(int element);
    void deleteFirstElement();
    void deleteLastElement();
    void deleteElement(int element);
    void findAndInsertElement(int x);
};

#endif