//#include <iostream>
//#include "Single Linked List.h"
//#include "Array.h"
//#include "Stack.h"
//#include "Queue.h"
//#include "DoubleLinkedList.h"
//
//using namespace std;
//
//Array::Array() {
//    size = 0;
//}
//
//void Array::addElement(int element) {
//    if (size < MAX_SIZE) {
//        arr[size++] = element;
//    }
//    else {
//        cout << "Array is full!" << endl;
//    }
//}
//
//void Array::addElements() {
//    string input;
//    getline(cin, input);
//
//    istringstream iss(input);
//    int element;
//    while (iss >> element) {
//        if (size < MAX_SIZE) {
//            arr[size++] = element;
//        }
//        else {
//            cout << "Array is full!" << endl;
//            break;
//        }
//    }
//}
//
//void Array::insertElement(int element, int index) {
//    if (index >= 0 && index <= size) {
//        for (int i = size; i > index; i--) {
//            arr[i] = arr[i - 1];
//        }
//        arr[index] = element;
//        size++;
//    }
//    else {
//        cout << "Invalid index!" << endl;
//    }
//}
//
//void Array::deleteElement(int index) {
//    if (index >= 0 && index < size) {
//        for (int i = index; i < size - 1; i++) {
//            arr[i] = arr[i + 1];
//        }
//        size--;
//    }
//    else {
//        cout << "Invalid index!" << endl;
//    }
//}
//
//int Array::findElement(int element) {
//    for (int i = 0; i < size; i++) {
//        if (arr[i] == element) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//void Array::display() {
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//// Node class
//Node::Node(int data) {
//    this->data = data;
//    next = nullptr;
//}
//
//// LinkedList class
//LinkedList::LinkedList() {
//    head = nullptr;
//    tail = nullptr;
//}
//
//void LinkedList::addElements(const int* elements, int numElements) {
//    for (int i = 0; i < numElements; i++) {
//        Node* newNode = new Node(elements[i]);
//        if (head == nullptr) {
//            head = newNode;
//            tail = newNode;
//        }
//        else {
//            tail->next = newNode;
//            tail = newNode;
//        }
//    }
//}
//
//void LinkedList::insertElements(const int* elements, int numElements, int index) {
//    if (index < 0 || index > size()) {
//        cout << "Invalid index!" << endl;
//        return;
//    }
//
//    if (index == 0) {
//        // Insert elements at the beginning
//        for (int i = numElements - 1; i >= 0; i--) {
//            Node* newNode = new Node(elements[i]);
//            newNode->next = head;
//            head = newNode;
//        }
//    }
//    else if (index == size()) {
//        // Insert elements at the end
//        addElements(elements, numElements);
//    }
//    else {
//        // Insert elements at the specified index
//        Node* current = head;
//        for (int i = 0; i < index - 1; i++) {
//            current = current->next;
//        }
//
//        for (int i = 0; i < numElements; i++) {
//            Node* newNode = new Node(elements[i]);
//            newNode->next = current->next;
//            current->next = newNode;
//            current = newNode;
//        }
//    }
//}
//
//void LinkedList::deleteElement(int index) {
//    if (index == 0) {
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//    }
//    else if (index > 0 && index < size()) {
//        Node* current = head;
//        for (int i = 0; i < index - 1; i++) {
//            current = current->next;
//        }
//        Node* temp = current->next;
//        current->next = temp->next;
//        if (temp == tail) {
//            tail = current;
//        }
//        delete temp;
//    }
//    else {
//        cout << "Invalid index!" << endl;
//    }
//}
//
////Sequential Search technique aka linear search
//int LinkedList::findElement(int element) {
//    Node* current = head;
//    int index = 0;
//    while (current != nullptr) {
//        if (current->data == element) {
//            return index;
//        }
//        current = current->next;
//        index++;
//    }
//    return -1;
//}
//
////Binary Search
//int LinkedList::binarySearch(int element) {
//    int left = 0;
//    int right = size() - 1;
//
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        int midValue = getNodeValue(mid);
//
//        if (midValue == element) {
//            return mid; // Return the index of the target element
//        }
//        else if (midValue < element) {
//            left = mid + 1; // Search the right half
//        }
//        else {
//            right = mid - 1; // Search the left half
//        }
//    }
//    return -1; // Return -1 if the target element is not found
//}
//
//int LinkedList::getNodeValue(int index) {
//    Node* current = head;
//    int count = 0;
//    while (current != nullptr && count < index )
//    {
//        current = current->next;
//        count++;
//    }
//    return current->data;
//}
//
//void LinkedList::display() {
//    Node* current = head;
//    while (current != nullptr) {
//        cout << current->data << " ";
//        current = current->next;
//    }
//    cout << endl;
//}
//
//int LinkedList::size() {
//    int count = 0;
//    Node* current = head;
//    while (current != nullptr) {
//        count++;
//        current = current->next;
//    }
//    return count;
//}
//
//// Stack class
//Stack::Stack() {
//    top = -1;
//}
//
//bool Stack::isEmpty() {
//    return (top == -1);
//}
//
//bool Stack::isFull() {
//    return (top == MAX_SIZE - 1);
//}
//
//void Stack::push(const int elements[], int size) {
//    for (int i = 0; i < size; i++) {
//        if (!isFull()) {
//            arr[++top] = elements[i];
//        }
//        else {
//            cout << "Stack is full!" << endl;
//            return;
//        }
//    }
//}
//
//int Stack::pop() {
//    if (!isEmpty()) {
//        return arr[top--];
//    }
//    else {
//        cout << "Stack is empty!" << endl;
//        return -1;
//    }
//}
//
//void Stack::display() {
//    for (int i = top; i >= 0; i--) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//int Stack::binaryToDecimal(string binary) {
//    int decimal = 0;
//    int base = 1;
//    for (int i = binary.length() - 1; i >= 0; i--) {
//        if (binary[i] == '1') {
//            decimal += base;
//        }
//        base *= 2;
//    }
//    return decimal;
//}
//
//string Stack::decimalToBinary(int decimal) {
//    string binary = "";
//    while (decimal != 0) {
//        binary = to_string(decimal % 2) + binary;
//        decimal /= 2;
//    }
//    return binary;
//}
//
//
//// Queue class
//Queue::Queue() {
//    front = -1;
//    rear = -1;
//}
//
//bool Queue::isEmpty() {
//    return (front == -1 && rear == -1);
//}
//
//bool Queue::isFull() {
//    return (rear == MAX_SIZE - 1);
//}
//
//void Queue::enqueue(int element) {
//    if (!isFull()) {
//        if (isEmpty()) {
//            front = 0;
//        }
//        arr[++rear] = element;
//    }
//    else {
//        cout << "Queue is full!" << endl;
//    }
//}
//
//int Queue::dequeue() {
//    if (!isEmpty()) {
//        int element = arr[front];
//        if (front == rear) {
//            front = -1;
//            rear = -1;
//        }
//        else {
//            front++;
//        }
//        return element;
//    }
//    else {
//        cout << "Queue is empty!" << endl;
//        return -1;
//    }
//}
//
//void Queue::display() {
//    if (isEmpty()) {
//        cout << "Queue is empty!" << endl;
//    }
//    else {
//        for (int i = front; i <= rear; i++) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//}
//
//void Queue::addMultipleElements(int elements[], int numElements) {
//    if ((rear + 1) + numElements > MAX_SIZE) {
//        cout << "Not enough space in the queue to add all elements!" << endl;
//        return;
//    }
//
//    for (int i = 0; i < numElements; i++) {
//        enqueue(elements[i]);
//    }
//}
//
//// DoubleLinkedList class
//DoubleLinkedList::DoubleLinkedList() {
//    head = nullptr;
//    tail = nullptr;
//}
//
//bool DoubleLinkedList::isEmpty() {
//    return head == nullptr;
//}
//
//void DoubleLinkedList::displayList() {
//    if (isEmpty()) {
//        cout << "The list is empty." << endl;
//        return;
//    }
//
//    Node* current = head;
//    cout << "Elements in the Double Linked List: ";
//    while (current != nullptr) {
//        cout << current->data << " ";
//        current = current->next;
//    }
//    cout << endl;
//}
//
//void DoubleLinkedList::addElement(int element) {
//    Node* newNode = new Node();
//    newNode->data = element;
//    newNode->prev = nullptr;
//    newNode->next = nullptr;
//
//    if (isEmpty()) {
//        head = newNode;
//        tail = newNode;
//    }
//    else {
//        tail->next = newNode;
//        newNode->prev = tail;
//        tail = newNode;
//    }
//}
//
//void DoubleLinkedList::addElementAtBegin(int element) {
//    Node* newNode = new Node();
//    newNode->data = element;
//    newNode->prev = nullptr;
//    newNode->next = nullptr;
//
//    if (isEmpty()) {
//        head = newNode;
//        tail = newNode;
//    }
//    else {
//        newNode->next = head;
//        head->prev = newNode;
//        head = newNode;
//    }
//}
//
//void DoubleLinkedList::addElementAtEnd(int element) {
//    addElement(element);
//}
//
//void DoubleLinkedList::deleteFirstElement() {
//    if (isEmpty()) {
//        cout << "The list is empty. Nothing to delete." << endl;
//        return;
//    }
//
//    Node* temp = head;
//    head = head->next;
//    if (head != nullptr) {
//        head->prev = nullptr;
//    }
//    else {
//        tail = nullptr;
//    }
//
//    delete temp;
//    cout << "First element deleted from the Double Linked List." << endl;
//}
//
//void DoubleLinkedList::deleteLastElement() {
//    if (isEmpty()) {
//        cout << "The list is empty. Nothing to delete." << endl;
//        return;
//    }
//
//    Node* temp = tail;
//    tail = tail->prev;
//    if (tail != nullptr) {
//        tail->next = nullptr;
//    }
//    else {
//        head = nullptr;
//    }
//
//    delete temp;
//    cout << "Last element deleted from the Double Linked List." << endl;
//}
//
//void DoubleLinkedList::deleteElement(int element) {
//    if (isEmpty()) {
//        cout << "The list is empty. Nothing to delete." << endl;
//        return;
//    }
//
//    Node* current = head;
//    while (current != nullptr) {
//        if (current->data == element) {
//            if (current == head) {
//                deleteFirstElement();
//            }
//            else if (current == tail) {
//                deleteLastElement();
//            }
//            else {
//                current->prev->next = current->next;
//                current->next->prev = current->prev;
//                delete current;
//                cout << "Element " << element << " deleted from the Double Linked List." << endl;
//            }
//            return;
//        }
//        current = current->next;
//    }
//
//    cout << "Element " << element << " not found in the Double Linked List." << endl;
//}
//
//void DoubleLinkedList::findAndInsertElement(int x) {
//    if (isEmpty()) {
//        cout << "The list is empty. Cannot perform the operation." << endl;
//        return;
//    }
//
//    Node* current = head;
//    while (current != nullptr) {
//        if (current->data == x || current->data > x) {
//            int newElement;
//            cout << "Enter the new element to be added: ";
//            cin >> newElement;
//
//            Node* newNode = new Node();
//            newNode->data = newElement;
//            newNode->prev = current->prev;
//            newNode->next = current;
//
//            if (current->prev != nullptr) {
//                current->prev->next = newNode;
//            }
//             else {
//                   head = newNode;
//             }
//            current->prev = newNode;
//     
//             cout << "Element " << newElement << " added in front of the found element." << endl;
//                   return;
//        }
//            current = current->next;
//    }
//
//        cout << "No element found that is equal to or greater than " << x << " in the Double Linked List." << endl;
//}
//
//int main()
//{
//    int choice;
//    Array arr;
//    LinkedList linkedList;
//    Stack stack;
//    Queue queue;
//
//    do {
//        cout << "-------------------------" << endl;
//        cout << "Data Structure and Algorithms" << endl;
//        cout << "-------------------------" << endl;
//        cout << "1. Array" << endl;
//        cout << "2. Single Linked List" << endl;
//        cout << "3. Stack" << endl;
//        cout << "4. Queue" << endl;
//        cout << "5. Double Linked List" << endl;
//        cout << "0. Exit" << endl;
//        cout << "-------------------------" << endl;
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//
//
//
//            break;
//        }
//
//        case 2: {
//
//
//
//        }
//              cout << endl;
//        }
//    } while (choice != 0);
//
//        return 0;
//   
//}