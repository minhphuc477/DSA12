#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include<stack>

using namespace std;

const int MAX_SIZE = 100;
// Array class
class Array {
private:
    int arr[MAX_SIZE];
    int size;

public:
    Array() : arr{}, size(0) {}


    void addElement(int element) {
        if (size < MAX_SIZE) {
            arr[size++] = element;
        }
        else {
            cout << "Array is full!" << endl;
        }
    }

    void addElements() {
        string input;
        getline(cin, input);

        istringstream iss(input);
        int element;
        while (iss >> element) {
            if (size < MAX_SIZE) {
                arr[size++] = element;
            }
            else {
                cout << "Array is full!" << endl;
                break;
            }
        }
    }

    void insertElement(int element, int index) {
        if (index >= 0 && index <= size) {
            for (int i = size; i > index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index] = element;
            size++;
        }
        else {
            cout << "Invalid index!" << endl;
        }
    }

    void deleteElement(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        }
        else {
            cout << "Invalid index!" << endl;
        }
    }

    int findElement(int element) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

//Single Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

//Single Linked List class
class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addElements(const int* elements, int numElements) {
        for (int i = 0; i < numElements; i++) {
            Node* newNode = new Node(elements[i]);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    void insertElements(const int* elements, int numElements, int index) {
        if (index < 0 || index > size()) {
            cout << "Invalid index!" << endl;
            return;
        }

        if (index == 0) {
            // Insert elements at the beginning
            for (int i = numElements - 1; i >= 0; i--) {
                Node* newNode = new Node(elements[i]);
                newNode->next = head;
                head = newNode;
            }
        }
        else if (index == size()) {
            // Insert elements at the end
            addElements(elements, numElements);
        }
        else {
            // Insert elements at the specified index
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }

            for (int i = 0; i < numElements; i++) {
                Node* newNode = new Node(elements[i]);
                newNode->next = current->next;
                current->next = newNode;
                current = current->next;
            }
        }
    }

    void deleteElement(int index) {
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else if (index > 0 && index < size()) {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            if (temp == tail) {
                tail = current;
            }
            delete temp;
        }
        else {
            cout << "Invalid index!" << endl;
        }
    }

    //Sequential Search tenchnique aka linear search
    int findElement(int element) {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == element) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
    //Binary Search
    int binarySearch(int element) {
        int left = 0;
        int right = size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = getNodeValue(mid);

            if (midValue == element) {
                return mid; // Return the index of the target element
            }
            else if (midValue < element) {
                left = mid + 1; // Search the right half
            }
            else {
                right = mid - 1; // Search the left half
            }
        }
        return -1; 
    }

    int getNodeValue(int index) {
        Node* current = head;
        int count = 0;
        while (current != nullptr && count < index) {
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            return -1;
        }

        return current->data;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int size() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

// Stack class
class Stack {
private:
    int arr[MAX_SIZE] = {};
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void push(const int elements[], int size) {
        for (int i = 0; i < size; i++) {
            if (!isFull()) {
                arr[++top] = elements[i];
            }
            else {
                cout << "Stack is full!" << endl;
                return;
            }
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int binaryToDecimal(string binary) {
        int decimal = 0;
        unsigned int base = 1;
        for (int i = static_cast<int>(binary.length()) - 1; i >= 0; i--) {
            if (binary[i] == '1') {
                decimal += base;
            }
            base *= 2;
        }
        return decimal;
    }

    string decimalToBinary(int decimal) {
        string binary = "";
        while (decimal != 0) {
            binary = to_string(decimal % 2) + binary;
            decimal /= 2;
        }
        return binary;
    }
};

// Queue class
class Queue {
private:
    static const int MAX_SIZE = 100; 
    int arr[MAX_SIZE] = {};
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int element) {
        if (!isFull()) {
            if (isEmpty()) {
                front = 0;
            }
            arr[++rear] = element;
        }
        else {
            cout << "Queue is full!" << endl;
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            int element = arr[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                front++;
            }
            return element;
        }
        else {
            cout << "Queue is empty!" << endl;
            return -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        }
        else {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void addMultipleElements(int elements[], int numElements) {
        if ((rear + 1) + numElements > MAX_SIZE) {
            cout << "Not enough space in the queue to add all elements!" << endl;
            return;
        }

        for (int i = 0; i < numElements; i++) {
            enqueue(elements[i]);
        }
    }
};

//Double Linked List
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

class DoubleLinkedList {
private:
    DNode* head;
    DNode* tail;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void displayList() {
        if (isEmpty()) {
            cout << "The list is empty." << endl;
            return;
        }

        DNode* current = head;
        cout << "Elements in the Double Linked List: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void addElement(int element) {
        DNode* newNode = new DNode();
        newNode->data = element;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void addElementAtBegin(int element) {
        DNode* newNode = new DNode();
        newNode->data = element;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addElementAtEnd(int element) {
        addElement(element);
    }

    void deleteFirstElement() {
        if (isEmpty()) {
            cout << "The list is empty. Nothing to delete." << endl;
            return;
        }

        DNode* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }

        delete temp;
        cout << "First element deleted from the Double Linked List." << endl;
    }

    void deleteLastElement() {
        if (isEmpty()) {
            cout << "The list is empty. Nothing to delete." << endl;
            return;
        }

        DNode* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }

        delete temp;
        cout << "Last element deleted from the Double Linked List." << endl;
    }

    void deleteElement(int element) {
        if (isEmpty()) {
            cout << "The list is empty. Nothing to delete." << endl;
            return;
        }

        DNode* current = head;
        while (current != nullptr) {
            if (current->data == element) {
                if (current == head) {
                    deleteFirstElement();
                }
                else if (current == tail) {
                    deleteLastElement();
                }
                else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    cout << "Element " << element << " deleted from the Double Linked List." << endl;
                }
                return;
            }
            current = current->next;
        }

        cout << "Element " << element << " not found in the Double Linked List." << endl;
    }

    void findAndInsertElement(int x) {
        if (isEmpty()) {
            cout << "The list is empty. Cannot perform the operation." << endl;
            return;
        }

        DNode* current = head;
        while (current != nullptr) {
            if (current->data == x || current->data > x) {
                int newElement;
                cout << "Enter the new element to be added: ";
                cin >> newElement;

                DNode* newNode = new DNode();
                newNode->data = newElement;
                newNode->prev = current->prev;
                newNode->next = current;

                if (current->prev != nullptr) {
                    current->prev->next = newNode;
                }
                else {
                    head = newNode;
                }
                current->prev = newNode;

                cout << "Element " << newElement << " added in front of the found element." << endl;
                return;
            }
            current = current->next;
        }

        cout << "No element found that is equal to or greater than " << x << " in the Double Linked List." << endl;
    }
};

//Circular Linked List

// Node structure for Circular Linked List
struct LinkedListNode {
    int data;
    LinkedListNode* next;
};

// Circular Linked List class
class CircularLinkedList {
private:
    LinkedListNode* head;
public:
    CircularLinkedList() {
        head = NULL;
    }

    // check if the list is empty
    bool isEmpty() {
        return (head == NULL);
    }

    //display the Circular Linked List
    void displayList() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }
        LinkedListNode* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    //add multiple elements into the list
    void addElements(int numElements) {
        int value;
        cout << "Enter the elements:\n";
        for (int i = 0; i < numElements; i++) {
            cin >> value;
            addElement(value);
        }
    }

    // add one element in the beginning of the list
    void addElement(int value) {
        LinkedListNode* newNode = new LinkedListNode();
        newNode->data = value;
        if (isEmpty()) {
            newNode->next = newNode;
            head = newNode;
        }
        else {
            LinkedListNode* last = head;
            while (last->next != head)
                last = last->next;
            newNode->next = head;
            last->next = newNode;
            head = newNode;
        }
        cout << value << " added to the list." << endl;
    }

    //delete one element from the beginning of the list
    void deleteElementFromBeginning() {
        if (isEmpty()) {
            cout << "List is empty. No element to delete." << endl;
            return;
        }
        LinkedListNode* last = head;
        while (last->next != head)
            last = last->next;
        LinkedListNode* temp = head;
        if (head == last) {
            head = NULL;
        }
        else {
            head = head->next;
            last->next = head;
        }
        cout << temp->data << " deleted from the beginning of the list." << endl;
        delete temp;
    }

    //add one element at the end of the list
    void addElementAtEnd(int value) {
        LinkedListNode* newNode = new LinkedListNode();
        newNode->data = value;
        if (isEmpty()) {
            newNode->next = newNode;
            head = newNode;
        }
        else {
            LinkedListNode* last = head;
            while (last->next != head)
                last = last->next;
            last->next = newNode;
            newNode->next = head;
        }
        cout << value << " added to the end of the list." << endl;
    }

    // Function to delete one element from the end of the list
    void deleteElementFromEnd() {
        if (isEmpty()) {
            cout << "List is empty. No element to delete." << endl;
            return;
        }
        LinkedListNode* last = head;
        LinkedListNode* prev = NULL;
        while (last->next != head) {
            prev = last;
            last = last->next;
        }
        if (last == head) {
            head = NULL;
        }
        else {
            prev->next = head;
        }
        cout << last->data << " deleted from the end of the list." << endl;
        delete last;
    }

    // Function to find and delete an element x
    void findAndDeleteElement(int value) {
        if (isEmpty()) {
            cout << "List is empty. No element to delete." << endl;
            return;
        }
        LinkedListNode* current = head;
        LinkedListNode* prev = NULL;
        do {
            if (current->data == value) {
                if (prev == NULL) {
                    deleteElementFromBeginning();
                }
                else if (current->next == head) {
                    deleteElementFromEnd();
                }
                else {
                    prev->next = current->next;
                    cout << current->data << " deleted from the list." << endl;
                    delete current;
                }
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);
        cout << "Element " << value << " not found in the list." << endl;
    }

    void findAndInsertElement(int findValue, int insertValue) {
        if (isEmpty()) {
            cout << "List is empty. Cannot perform operation." << endl;
            return;
        }
        LinkedListNode* current = head;
        do {
            if (current->data == findValue) {
                LinkedListNode* newNode = new LinkedListNode();
                newNode->data = insertValue;
                newNode->next = current->next;
                current->next = newNode;
                cout << insertValue << " inserted after " << findValue << "." << endl;
                return;
            }
            current = current->next;
        } while (current != head);
        cout << "Element " << findValue << " not found in the list." << endl;
    }
};

// Sorting and Searching class
class SortSearch {
public:
    // Selection Sort
    static void selectionSort(int arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIdx])
                    minIdx = j;
            }
            swap(arr[i], arr[minIdx]);
        }
    }

    // Insertion Sort
    static void insertionSort(int arr[], int size) {
        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // Interchange Sort
    static void interchangeSort(int arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[i])
                    swap(arr[i], arr[j]);
            }
        }
    }

    // Bubble Sort
    static void bubbleSort(int arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
    }

    // Merge Sort
    static void mergeSort(int arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    static void merge(int arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }

    // Quick Sort
    static void quickSort(int arr[], int left, int right) {
        if (left < right) {
            int pivotIdx = partition(arr, left, right);
            quickSort(arr, left, pivotIdx - 1);
            quickSort(arr, pivotIdx + 1, right);
        }
    }

    static int partition(int arr[], int left, int right) {
        int pivot = arr[right];
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[right]);
        return i + 1;
    }

    // Heap Sort
    static void heapSort(int arr[], int size) {
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(arr, size, i);

        for (int i = size - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    static void heapify(int arr[], int size, int root) {
        int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 1;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != root) {
            swap(arr[root], arr[largest]);
            heapify(arr, size, largest);
        }
    }

    // Linear Search
    static int linearSearch(int arr[], int size, int key) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == key)
                return i;
        }
        return -1;
    }

    // Binary Search
    static int binarySearch(int arr[], int left, int right, int key) {
        if (right >= left) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == key)
                return mid;

            if (arr[mid] > key)
                return binarySearch(arr, left, mid - 1, key);

            return binarySearch(arr, mid + 1, right, key);
        }

        return -1;
    }
};

//Binary Tree
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    TreeNode* getRoot() {
        return root;
    }

    void drawTree(TreeNode* node, int space) {
        if (node == nullptr)
            return;

        space += 10;

        drawTree(node->right, space);

        cout << "\n";
        for (int i = 10; i < space; i++)
            cout << " ";
        cout << node->data << "\n";

        drawTree(node->left, space);
    }

    int maxDepth(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        return max(leftDepth, rightDepth) + 1;
    }

    void insertNode(int value) {
        TreeNode* newNode = new TreeNode(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = newNode;
                return;
            }
            else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = newNode;
                return;
            }
            else {
                q.push(current->right);
            }
        }
    }

    void deleteNode(int value) {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr) {
            if (root->data == value) {
                delete root;
                root = nullptr;
                return;
            }
        }

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* targetNode = nullptr;
        TreeNode* deepestNode = nullptr;

        while (!q.empty()) {
            deepestNode = q.front();
            q.pop();

            if (deepestNode->data == value)
                targetNode = deepestNode;

            if (deepestNode->left != nullptr)
                q.push(deepestNode->left);

            if (deepestNode->right != nullptr)
                q.push(deepestNode->right);
        }

        if (targetNode != nullptr) {
            int temp = deepestNode->data;
            deleteDeepestNode(deepestNode);
            targetNode->data = temp;
        }
    }

    void deleteDeepestNode(TreeNode* node) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current->right != nullptr) {
                if (current->right == node) {
                    delete node;
                    current->right = nullptr;
                    return;
                }
                else {
                    q.push(current->right);
                }
            }

            if (current->left != nullptr) {
                if (current->left == node) {
                    delete node;
                    current->left = nullptr;
                    return;
                }
                else {
                    q.push(current->left);
                }
            }
        }
    }

    void levelOrderTraversal() {
        if (root == nullptr)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }
    }
};

//Binary Search Tree

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};


class BinarySearchTree {
private:
    BSTNode* root;

public:
    BSTNode* getRoot() {
        return root;
    }

    BinarySearchTree() {
        root = nullptr;
    }

    BSTNode* createBSTNode(int value) {
        BSTNode* newBSTNode = new BSTNode();
        newBSTNode->data = value;
        newBSTNode->left = nullptr;
        newBSTNode->right = nullptr;
        return newBSTNode;
    }

    BSTNode* insert(BSTNode* root, int value) {
        if (root == nullptr) {
            root = createBSTNode(value);
        }
        else if (value <= root->data) {
            root->left = insert(root->left, value);
        }
        else {
            root->right = insert(root->right, value);
        }
        return root;
    }

    void addElements() {
        int numElements;
        cout << "Enter the number of elements to add: ";
        cin >> numElements;

        cout << "Enter the root element and other leaf elements after: ";
        for (int i = 0; i < numElements; i++) {
            int element;
            cin >> element;
            root = insert(root, element);
        }
    }

    void drawBST() {
        drawBSTUtil(root, 0);
    }

    void drawBSTUtil(BSTNode* root, int space) {
        if (root == nullptr) {
            return;
        }

        int spacing = 6; // Adjust this value to increase/decrease spacing between BSTNodes

        space += spacing;

        drawBSTUtil(root->right, space);

        cout << endl;
        for (int i = spacing; i < space; i++) {
            cout << " ";
        }
        cout << root->data << endl;

        drawBSTUtil(root->left, space);
    }

    void printBSTNodeAtLevel(int level) {
        cout << "BSTNodes at level " << level << ": ";
        printBSTNodeAtLevelUtil(root, level);
        cout << endl;
    }

    void printBSTNodeAtLevelUtil(BSTNode* root, int level) {
        if (root == nullptr) {
            return;
        }
        if (level == 0) {
            cout << root->data << " ";
        }
        else {
            printBSTNodeAtLevelUtil(root->left, level - 1);
            printBSTNodeAtLevelUtil(root->right, level - 1);
        }
    }

    void printLeafBSTNodes() {
        cout << "Leaf BSTNodes: ";
        printLeafBSTNodesUtil(root);
        cout << endl;
    }

    void printLeafBSTNodesUtil(BSTNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            cout << root->data << " ";
        }
        else {
            printLeafBSTNodesUtil(root->left);
            printLeafBSTNodesUtil(root->right);
        }
    }

    void printRightView() {
        cout << "Right view of BST: ";
        printRightViewUtil(root);
        cout << endl;
    }

    void printRightViewUtil(BSTNode* root) {
        if (root == nullptr) {
            return;
        }

        queue<BSTNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                BSTNode* current = q.front();
                q.pop();

                if (i == size - 1) {
                    cout << current->data << " ";
                }

                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
        }
    }

    void printLeftView() {
        cout << "Left view of BST: ";
        printLeftViewUtil(root);
        cout << endl;
    }

    void printLeftViewUtil(BSTNode* root) {
        if (root == nullptr) {
            return;
        }

        queue<BSTNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                BSTNode* current = q.front();
                q.pop();

                if (i == 0) {
                    cout << current->data << " ";
                }

                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
        }
    }

    bool findKey(int key) {
        return findKeyUtil(root, key);
    }

    bool findKeyUtil(BSTNode* root, int key) {
        if (root == nullptr) {
            return false;
        }
        if (root->data == key) {
            return true;
        }
        else if (key < root->data) {
            return findKeyUtil(root->left, key);
        }
        else {
            return findKeyUtil(root->right, key);
        }
    }

    BSTNode* deleteBSTNode(BSTNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        else if (key < root->data) {
            root->left = deleteBSTNode(root->left, key);
        }
        else if (key > root->data) {
            root->right = deleteBSTNode(root->right, key);
        }
        else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
            }
            else if (root->left == nullptr) {
                BSTNode* temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == nullptr) {
                BSTNode* temp = root;
                root = root->left;
                delete temp;
            }
            else {
                BSTNode* temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteBSTNode(root->right, temp->data);
            }
        }
        return root;
    }

    BSTNode* findMin(BSTNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    void printInorderTraversal() {
        cout << "Inorder traversal: ";
        printInorderTraversalUtil(root);
        cout << endl;
    }

    void printInorderTraversalUtil(BSTNode* root) {
        if (root == nullptr) {
            return;
        }
        printInorderTraversalUtil(root->left);
        cout << root->data << " ";
        printInorderTraversalUtil(root->right);
    }

    void printPreorderTraversal() {
        cout << "Preorder traversal: ";
        printPreorderTraversalUtil(root);
        cout << endl;
    }

    void printPreorderTraversalUtil(BSTNode* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->data << " ";
        printPreorderTraversalUtil(root->left);
        printPreorderTraversalUtil(root->right);
    }

    void printPostorderTraversal() {
        cout << "Postorder traversal: ";
        printPostorderTraversalUtil(root);
        cout << endl;
    }

    void printPostorderTraversalUtil(BSTNode* root) {
        if (root == nullptr) {
            return;
        }
        printPostorderTraversalUtil(root->left);
        printPostorderTraversalUtil(root->right);
        cout << root->data << " ";
    }

    void printLevelOrderTraversal() {
        cout << "Level order traversal: ";
        printLevelOrderTraversalUtil(root);
        cout << endl;
    }

    void printLevelOrderTraversalUtil(BSTNode* root) {
        if (root == nullptr) {
            return;
        }

        queue<BSTNode*> q;
        q.push(root);

        while (!q.empty()) {
            BSTNode* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
    }

    // Function to perform Preorder traversal using stack
    void preorderTraversal(BSTNode* root) {
        if (root == nullptr)
            return;

        stack<BSTNode*> stack;
        stack.push(root);

        while (!stack.empty()) {
            BSTNode* current = stack.top();
            stack.pop();
            cout << current->data << " ";

            if (current->right)
                stack.push(current->right);
            if (current->left)
                stack.push(current->left);
        }
    }

    // Function to perform Postorder traversal using stack
    stack<BSTNode*> resultStack;
    void postorderTraversal(BSTNode* root) {
        if (root == nullptr)
            return;

        stack<BSTNode*> stack;
        stack.push(root);

        while (!stack.empty()) {
            BSTNode* current = stack.top();
            stack.pop();
            resultStack.push(current);

            if (current->left)
                stack.push(current->left);
            if (current->right)
                stack.push(current->right);
        }

        while (!resultStack.empty()) {
            BSTNode* current = resultStack.top();
            resultStack.pop();
            cout << current->data << " ";
        }
    }

    // Function to perform Level order traversal using stack
    void levelorderTraversal(BSTNode* root) {
        if (root == nullptr)
            return;

        stack<BSTNode*> stack;
        stack.push(root);

        while (!stack.empty()) {
            BSTNode* current = stack.top();
            stack.pop();
            cout << current->data << " ";

            if (current->right)
                stack.push(current->right);
            if (current->left)
                stack.push(current->left);
        }
    }


    int getHeight() {
        return getHeightUtil(root);
    }

    int getHeightUtil(BSTNode* root) {
        if (root == nullptr) {
            return -1;
        }
        int leftHeight = getHeightUtil(root->left);
        int rightHeight = getHeightUtil(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    BSTNode* findSmallestBSTNode() {
        return findSmallestBSTNodeUtil(root);
    }

    BSTNode* findSmallestBSTNodeUtil(BSTNode* root) {
        if (root == nullptr || root->left == nullptr) {
            return root;
        }
        return findSmallestBSTNodeUtil(root->left);
    }

    bool isBalanced() {
        return isBalancedUtil(root);
    }

    bool isBalancedUtil(BSTNode* root) {
        if (root == nullptr) {
            return true;
        }
        int leftHeight = getHeightUtil(root->left);
        int rightHeight = getHeightUtil(root->right);
        if (abs(leftHeight - rightHeight) <= 1 && isBalancedUtil(root->left) && isBalancedUtil(root->right)) {
            return true;
        }
        return false;
    }

    bool isBST() {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }

    bool isBSTUtil(BSTNode* root, int minValue, int maxValue) {
        if (root == nullptr) {
            return true;
        }
        if (root->data > minValue && root->data < maxValue &&
            isBSTUtil(root->left, minValue, root->data) &&
            isBSTUtil(root->right, root->data, maxValue)) {
            return true;
        }
        return false;
    }

    BSTNode* convertToBalancedBST() {
        int BSTNodeCount = countBSTNodes(root);
        return convertToBalancedBSTUtil(root, BSTNodeCount);
    }

    BSTNode* convertToBalancedBSTUtil(BSTNode* root, int BSTNodeCount) {
        if (root == nullptr) {
            return nullptr;
        }

        BSTNode* sortedArr = new BSTNode[BSTNodeCount];
        storeInOrder(root, sortedArr, 0);

        return buildBalancedBST(sortedArr, 0, BSTNodeCount - 1);
    }

    void storeInOrder(BSTNode* root, BSTNode* arr, int index) {
        if (root == nullptr) {
            return;
        }

        storeInOrder(root->left, arr, index);
        arr[index] = *root;
        storeInOrder(root->right, arr, index + 1);
    }

    BSTNode* buildBalancedBST(BSTNode* arr, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = (start + end) / 2;
        BSTNode* root = createBSTNode(arr[mid].data);

        root->left = buildBalancedBST(arr, start, mid - 1);
        root->right = buildBalancedBST(arr, mid + 1, end);

        return root;
    }

    int countBSTNodes(BSTNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + countBSTNodes(root->left) + countBSTNodes(root->right);
    }

    // Function to perform Inorder traversal using stack
    void inorderTraversal(BSTNode* root) {
        if (root == nullptr)
            return;

        stack<BSTNode*> stack;
        BSTNode* current = root;

        while (current != nullptr || !stack.empty()) {
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }
            current = stack.top();
            stack.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }


};

//Hash Table

//B-tree

//Bonus part


int main() {
    int choice;
    Array arr;
    LinkedList linkedList;
    Stack stack;
    Queue queue;

    do {
        cout << "-------------------------" << endl;
        cout << "Data Structure and Algorithms" << endl;
        cout << "-------------------------" << endl;
        cout << "1. Array" << endl;
        cout << "2. Single Linked List" << endl;
        cout << "3. Stack" << endl;
        cout << "4. Queue" << endl;
        cout << "5. Double Linked List" << endl;
        cout << "6. Circular Linked List" << endl;
        cout << "7. Sort and Search" << endl;
        cout << "8. Binary Tree" << endl;
        cout << "9. Binary Search Tree" << endl;
        cout << "10. HashTable" << endl;//not done yet
        cout << "11. B-tree" << endl;//not done yet
        cout << "12. Bonus part" << endl;
        cout << "0. Exit" << endl;
        cout << "-------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int arrChoice;
            do {
                cout << "-------------------------" << endl;
                cout << "Array Operations" << endl;
                cout << "-------------------------" << endl;
                cout << "1. Add element" << endl;
                cout << "2. Insert element" << endl;
                cout << "3. Delete element" << endl;
                cout << "4. Find element" << endl;
                cout << "5. Display" << endl;
                cout << "0. Back" << endl;
                cout << "-------------------------" << endl;
                cout << "Enter your choice: ";
                cin >> arrChoice;

                switch (arrChoice) {
                case 1: {
                    cout << "Enter elements to add separated by spaces: ";
                    cin.ignore();
                    arr.addElements();
                    break;
                }
                case 2: {
                    int element, index;
                    cout << "Enter element to insert: ";
                    cin >> element;
                    cout << "Enter index position to insert: ";
                    cin >> index;
                    arr.insertElement(element, index);
                    break;
                }
                case 3: {
                    int index;
                    cout << "Enter index position in array to delete: ";
                    cin >> index;
                    arr.deleteElement(index);
                    break;
                }
                case 4: {
                    int element;
                    cout << "Enter element to find: ";
                    cin >> element;
                    int index = arr.findElement(element);
                    if (index != -1) {
                        cout << "Element found at index position " << index << endl;
                    }
                    else {
                        cout << "Element not found" << endl;
                    }
                    break;
                }
                case 5:
                    arr.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
                }

            } while (arrChoice != 0);
            break;
        case 2:
            int linkedListChoice;
            do {
                cout << "-----------------------------" << endl;
                cout << "Single Linked List Operations" << endl;
                cout << "-----------------------------" << endl;
                cout << "1. Add element" << endl;
                cout << "2. Insert element" << endl;
                cout << "3. Delete element" << endl;
                cout << "4. Find element (Sequential Search)" << endl;
                cout << "5. Find element (Binary Search)" << endl;
                cout << "6. Display" << endl;
                cout << "0. Back" << endl;
                cout << "----------------------------" << endl;
                cout << "Enter your choice: ";
                cin >> linkedListChoice;

                switch (linkedListChoice) {
                case 1: {
                    int numElements;
                    cout << "Enter the number of elements to add: ";
                    cin >> numElements;

                    int* elements = new int[numElements];
                    for (int i = 0; i < numElements; i++) {
                        cout << "Enter element " << i + 1 << ": ";
                        cin >> elements[i];
                    }

                    linkedList.addElements(elements, numElements);

                    delete[] elements;
                    break;
                }
                case 2: {
                    int element, index;
                    cout << "Enter element to insert: ";
                    cin >> element;
                    cout << "Enter index position to insert: ";
                    cin >> index;
                    linkedList.insertElements(&element, 1, index);
                    break;
                }
                case 3: {
                    int index;
                    cout << "Enter index position to delete: ";
                    cin >> index;
                    linkedList.deleteElement(index);
                    break;
                }
                case 4: {
                    int element;
                    cout << "Enter element to find: ";
                    cin >> element;
                    int index = linkedList.findElement(element);
                    if (index != -1) {
                        cout << "Element found at index position " << index << endl;
                    }
                    else {
                        cout << "Element not found" << endl;
                    }
                    break;
                }
                case 5: {
                    int element;
                    cout << "Enter element to search: ";
                    cin >> element;
                    int index = linkedList.binarySearch(element);
                    if (index != -1) {
                        cout << "Element found at index position " << index << endl;
                    }
                    else {
                        cout << "Element not found" << endl;
                    }
                    break;
                }
                case 6:
                    linkedList.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
                }

            } while (linkedListChoice != 0);

            break;
        case 3:
            int stackChoice;
            do {
                cout << "-------------------------" << endl;
                cout << "Stack Operations" << endl;
                cout << "-------------------------" << endl;
                cout << "1. Push element" << endl;
                cout << "2. Pop element" << endl;
                cout << "3. Display" << endl;
                cout << "4. Binary to Decimal conversion" << endl;
                cout << "5. Decimal to Binary conversion" << endl;
                cout << "6. Check if stack is empty or not" << endl;
                cout << "0. Back" << endl;
                cout << "-------------------------" << endl;
                cout << "Enter your choice: ";
                cin >> stackChoice;

                switch (stackChoice) {
                case 1: {
                    int numElements;
                    cout << "Enter the number of elements to push: ";
                    cin >> numElements;

                    int* elements = new int[numElements];
                    cout << "Enter the elements to push: ";
                    for (int i = 0; i < numElements; i++) {
                        cin >> elements[i];
                    }

                    stack.push(elements, numElements);

                    delete[] elements;
                    break;
                }
                case 2: {
                    int poppedElement = stack.pop();
                    if (poppedElement != -1) {
                        cout << "Popped element: " << poppedElement << endl;
                    }
                    break;
                }
                case 3:
                    stack.display();
                    break;
                case 4: {
                    string binary;
                    cout << "Enter binary number: ";
                    cin >> binary;
                    int decimal = stack.binaryToDecimal(binary);
                    cout << "Decimal number: " << decimal << endl;
                    break;
                }
                case 5: {
                    int decimal;
                    cout << "Enter decimal number: ";
                    cin >> decimal;
                    string binary = stack.decimalToBinary(decimal);
                    cout << "Binary number: " << binary << endl;
                    break;
                }
                case 6: {
                    bool empty = stack.isEmpty();
                    if (empty) {
                        cout << "Stack is empty" << endl;
                    }
                    else {
                        cout << "Stack is not empty" << endl;
                    }
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
                }
            } while (stackChoice != 0);

            break;
        case 4:{
            int queueChoice;
            do {
                cout << "-------------------------" << endl;
                cout << "Queue Operations" << endl;
                cout << "-------------------------" << endl;
                cout << "1. Add multiple elements to the queue" << endl;
                cout << "2. Check if the queue is empty" << endl;
                cout << "3. Enqueue element (adding an element to the end of a queue)" << endl;
                cout << "4. Dequeue element (removing an element from the front of a queue)" << endl;
                cout << "5. Display" << endl;
                cout << "0. Back" << endl;
                cout << "-------------------------" << endl;
                cout << "Enter your choice: ";
                cin >> queueChoice;

                switch (queueChoice) {
                case 1: {
                    int numElements;
                    cout << "Enter the number of elements to add: ";
                    cin >> numElements;

                    for (int i = 0; i < numElements; i++) {
                        int element;
                        cout << "Enter element " << i + 1 << ": ";
                        cin >> element;
                        queue.enqueue(element);
                    }
                    break;
                }
                case 2: {
                    if (queue.isEmpty()) {
                        cout << "Queue is empty!" << endl;
                    }
                    else {
                        cout << "Queue is not empty." << endl;
                    }
                    cout << endl << "Press any key to continue...\n";
                    break;
                }
                case 3: {
                    int element;
                    cout << "Enter element to enqueue: ";
                    cin >> element;
                    queue.enqueue(element);
                    break;
                }
                case 4: {
                    int dequeuedElement = queue.dequeue();
                    if (dequeuedElement != -1) {
                        cout << "Dequeued element: " << dequeuedElement << endl;
                    }
                    break;
                }
                case 5:
                    queue.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
                }
            } while (queueChoice != 0);

            break;
        }
        case 5: {
            DoubleLinkedList dlList;
            int choice;
            int element, x;

            do {
                cout << "------------------------------" << endl;
                cout << "Double Linked List Operations" << endl;
                cout << "------------------------------" << endl;
                cout << "1. Check if the list is empty" << endl;
                cout << "2. Display " << endl;
                cout << "3. Insert multiple elements " << endl;
                cout << "4. Add an element at the beginning of the List" << endl;
                cout << "5. Add an element at the end of the List" << endl;
                cout << "6. Delete the first element from the List" << endl;
                cout << "7. Delete the last element from the List" << endl;
                cout << "8. Delete a specific element from the List" << endl;
                cout << "9. Find an element and insert a new element in front of it" << endl;
                cout << "0. Exit" << endl;
                cout << "------------------------------" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    if (dlList.isEmpty()) {
                        cout << "The list is empty." << endl;
                    }
                    else {
                        cout << "The list is not empty." << endl;
                    }
                    break;

                case 2:
                    dlList.displayList();
                    break;

                case 3:
                    int numElements;
                    cout << "Enter the number of elements to insert: ";
                    cin >> numElements;

                    for (int i = 0; i < numElements; i++) {
                        cout << "Enter element " << i + 1 << ": ";
                        cin >> element;
                        dlList.addElement(element);
                    }
                    break;

                case 4:
                    cout << "Enter the element to add at the beginning: ";
                    cin >> element;
                    dlList.addElementAtBegin(element);
                    break;

                case 5:
                    cout << "Enter the element to add at the end: ";
                    cin >> element;
                    dlList.addElementAtEnd(element);
                    break;

                case 6:
                    dlList.deleteFirstElement();
                    break;

                case 7:
                    dlList.deleteLastElement();
                    break;

                case 8:
                    cout << "Enter the element to delete: ";
                    cin >> element;
                    dlList.deleteElement(element);
                    break;

                case 9:
                    cout << "Enter the element to find and insert after: ";
                    cin >> x;
                    dlList.findAndInsertElement(x);
                    break;

                case 0:
                    cout << "Exiting the program." << endl;
                    break;

                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            } while (choice != 0);

            break;
        }
        case 6: {
            CircularLinkedList list;
            int value, findValue, insertValue;
            int numElements;

            do {
                cout << "-------------------------------" << endl;
                cout << "Circular Linked List Operations" << endl;
                cout << "-------------------------------" << endl;
                cout << "1. Add element at the beginning" << endl;
                cout << "2. Add element at the end" << endl;
                cout << "3. Delete element from the beginning" << endl;
                cout << "4. Delete element from the end" << endl;
                cout << "5. Find and delete element" << endl;
                cout << "6. Display the list" << endl;
                cout << "7. Insert multiple elements" << endl;
                cout << "8. Find and add a element after it" << endl;
                cout << "0. Exit" << endl;
                cout << "-------------------------------" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    cout << "Enter the element to add: ";
                    cin >> value;
                    list.addElement(value);
                    break;
                case 2:
                    cout << "Enter the element to add: ";
                    cin >> value;
                    list.addElementAtEnd(value);
                    break;
                case 3:
                    list.deleteElementFromBeginning();
                    break;
                case 4:
                    list.deleteElementFromEnd();
                    break;
                case 5:
                    cout << "Enter the element to find and delete: ";
                    cin >> value;
                    list.findAndDeleteElement(value);
                    break;
                case 6:
                    list.displayList();
                    break;
                case 7:
                    cout << "Enter the number of elements to insert: ";
                    cin >> numElements;

                    for (int i = 0; i < numElements; i++) {
                        cout << "Enter element " << i + 1 << ": ";
                        cin >> value;
                        list.addElement(value);
                    }
                    break;
                case 8:
                    cout << "Enter the element to find: ";
                    cin >> findValue;
                    cout << "Enter the element to insert after " << findValue
                         << ": ";
                    cin >> insertValue;
                    list.findAndInsertElement(findValue, insertValue);
                    break;
                case 0:
                    cout << "Exiting the program." << endl;
                    break;

                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            } while (choice != 0);

            break;
        }
        case 7:
        {
            int size;
            cout << "Enter the size of the array: ";
            cin >> size;

            int* arr = new int[size];

            cout << "Enter " << size << " elements: ";
            for (int i = 0; i < size; i++)
                cin >> arr[i];

            int choice;
            int key;
            bool exit = false;
            do {
                cout << "---------------------------------------" << endl;
                cout << " Sort and Search Algorithms Operations " << endl;
                cout << "---------------------------------------" << endl;
                cout << "1. Selection Sort" << endl;
                cout << "2. Insertion Sort" << endl;
                cout << "3. Interchange Sort" << endl;
                cout << "4. Bubble Sort" << endl;
                cout << "5. Merge Sort" << endl;
                cout << "6. Quick Sort" << endl;
                cout << "7. Heap Sort" << endl;
                cout << "8. Linear Search" << endl;
                cout << "9. Binary Search" << endl;
                cout << "0. Exit" << endl;
                cout << "--------------------------------------" << endl;
                cout << "Enter your choice: " << endl;
                cin >> choice;
                switch (choice) {
                case 1:
                    SortSearch::selectionSort(arr, size);
                    break;
                case 2:
                    SortSearch::insertionSort(arr, size);
                    break;
                case 3:
                    SortSearch::interchangeSort(arr, size);
                    break;
                case 4:
                    SortSearch::bubbleSort(arr, size);
                    break;
                case 5:
                    SortSearch::mergeSort(arr, 0, size - 1);
                    break;
                case 6:
                    SortSearch::quickSort(arr, 0, size - 1);
                    break;
                case 7:
                    SortSearch::heapSort(arr, size);
                    break;
                case 8:
                    cout << "Enter the key to search: ";
                    cin >> key;
                    if (SortSearch::linearSearch(arr, size, key) != -1)
                        cout << "Element found at index " << SortSearch::linearSearch(arr, size, key) << endl;
                    else
                        cout << "Element not found" << endl;
                    break;
                case 9:
                    cout << "Enter the key to search: ";
                    cin >> key;
                    if (SortSearch::binarySearch(arr, 0, size - 1, key) != -1)
                        cout << "Element found at index " << SortSearch::binarySearch(arr, 0, size - 1, key) << endl;
                    else
                        cout << "Element not found" << endl;
                    break;
                case 0:
                    exit = true;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                }
                cout << "Array after operation: ";
                for (int i = 0; i < size; i++)
                    cout << arr[i] << " ";
                cout << endl;
            } while (choice != 0);

            delete[] arr;

            break;
        }

        case 8:
        {
             int choice;
             BinaryTree tree;
            
            do {
                cout << "-------------------------------" << endl;
                cout << " Binary Tree Operations" << endl;
                cout << "-------------------------------" << endl;
                cout << "1. Add multiple elements" << endl;
                cout << "2. Insert element" << endl;
                cout << "3. Delete element" << endl;
                cout << "4. Draw tree" << endl;
                cout << "5. Maxium Depth of the Binary Tree" << endl;
                cout << "6. Level Oder Traversal" << endl;
                cout << "0. Exit" << endl;
                cout << "-------------------------------" << endl;
                cout << "Enter your choice: " << endl;
                cin >> choice;
                switch (choice) {

                case 1: {
                    cout << "Enter values for the binary tree, the fist element will be the root (enter -1 to stop):\n";
                    int value;
                    while (true) {
                        cout << "Enter value: ";
                        cin >> value;
                        if (value == -1) {
                            break;
                        }
                        tree.insertNode(value);
                    }
                    break;
                }
                case 2: {
                    int value;
                    cout << "Enter value to insert: ";
                    cin >> value;
                    tree.insertNode(value);
                    break;
                }
                case 3: {
                    int value;
                    cout << "Enter value to delete: ";
                    cin >> value;
                    tree.deleteNode(value);
                    break;
                }
                case 4: {
                    cout << "\nBinary Tree:\n";
                    tree.drawTree(tree.getRoot(), 0);
                    break;
                }
                case 5: {
                    int depth = tree.maxDepth(tree.getRoot());
                    cout << "\nMaximum Depth of Binary Tree: " << depth << "\n";
                    break;
                }
                case 6: {
                    cout << "\nLevel Order Traversal: ";
                    tree.levelOrderTraversal();
                    cout << "\n";
                    break;
                }
                case 0: {
                    cout << "\nExiting program...\n";
                    break;
                }
                default: {
                    cout << "\nInvalid choice! Please try again.\n";
                    break;
                }

                }
            } while (choice != 0);
            break;
        }
         
        case 9:
        {
            BinarySearchTree bst;

            int choice;
            do {
                cout << endl;
                cout << "-------------------------------" << endl;
                cout << " Binay Search Tree Operations " << endl;
                cout << "-------------------------------" << endl;
                cout << "1. Add elements to BST" << endl;
                cout << "2. Draw BST" << endl;
                cout << "3. Print BSTNode at a given level" << endl;
                cout << "4. Print all leaf BSTNodes" << endl;
                cout << "5. Print right view of BST" << endl;
                cout << "6. Print left view of BST" << endl;
                cout << "7. Find a key in BST" << endl;
                cout << "8. Delete a BSTNode in BST" << endl;
                cout << "9. Inorder traversal (LNR) using recursion" << endl;
                cout << "10. Preorder traversal (NLR) using recursion" << endl;
                cout << "11. Postorder traversal (LRN) using recursion" << endl;
                cout << "12. Level order traversal using recursion" << endl;
                cout << "13. Calculate height of BST" << endl;
                cout << "14. Find smallest BSTNode in BST" << endl;
                cout << "15. Check if BST is balanced" << endl;
                cout << "16. Check if BST is a valid BST" << endl;
                cout << "17. Convert BST to balanced BST" << endl;
                cout << "18. Inoder Traversal using Stack" << endl;
                cout << "19. Preoder Traversal using Stack" << endl;
                cout << "20. Postoder Traversal using Stack" << endl;
                cout << "21. Level oder Traversal using Stack" << endl;
                cout << "0. Exit" << endl;
                cout << "-------------------------------" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    bst.addElements();
                    break;
                case 2:
                    bst.drawBST();
                    break;
                case 3:
                    int level;
                    cout << "Enter the level: ";
                    cin >> level;
                    bst.printBSTNodeAtLevel(level);
                    break;
                case 4:
                    bst.printLeafBSTNodes();
                    break;
                case 5:
                    bst.printRightView();
                    break;
                case 6:
                    bst.printLeftView();
                    break;
                case 7:
                    int key;
                    cout << "Enter the key to search: ";
                    cin >> key;
                    if (bst.findKey(key)) {
                        cout << "Key found in BST" << endl;
                    }
                    else {
                        cout << "Key not found in BST" << endl;
                    }
                    break;
                case 8:
                    int deleteKey;
                    cout << "Enter the key to delete: ";
                    cin >> deleteKey;
                    bst.deleteBSTNode(bst.getRoot(), deleteKey);
                    break;
                case 9:
                    bst.printInorderTraversal();
                    break;
                case 10:
                    bst.printPreorderTraversal();
                    break;
                case 11:
                    bst.printPostorderTraversal();
                    break;
                case 12:
                    bst.printLevelOrderTraversal();
                    break;
                case 13:
                    cout << "Height of the BST: " << bst.getHeight() << endl;
                    break;
                case 14:
                    cout << "Smallest BSTNode in the BST: " << bst.findSmallestBSTNode() << endl;
                    break;
                case 15:
                    if (bst.isBalanced()) {
                        cout << "The BST is balanced." << endl;
                    }
                    else {
                        cout << "The BST is not balanced." << endl;
                    }
                    break;
                case 16:
                    if (bst.isBST()) {
                        cout << "The BST is a valid BST." << endl;
                    }
                    else {
                        cout << "The BST is not a valid BST." << endl;
                    }
                    break;
                case 17:
                    bst.convertToBalancedBST();
                    cout << "BST converted to balanced BST." << endl;
                    break;
                case 0:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                } 
            } while (choice != 0);
            break;
        }
        
        }
        
    } while (choice != 0);

        return 0;
}