//#include <iostream>
//#include <vector>
//#include <limits>
//
//using namespace std;
//
//struct Node {
//    int key;
//    Node* next;
//};
//
//class HashTable {
//private:
//    vector<Node*> table;
//    int size;
//
//public:
//    HashTable(int size) {
//        this->size = size;
//        table.resize(size, nullptr);
//    }
//
//    int hash(int key, int M) {
//        return key % M;
//    }
//
//    void insertDirectChaining(int key, int M) {
//        int pos = hash(key, M);
//        Node* newNode = new Node;
//        newNode->key = key;
//        newNode->next = nullptr;
//
//        if (table[pos] == nullptr) {
//            table[pos] = newNode;
//        }
//        else {
//            Node* curr = table[pos];
//            while (curr->next != nullptr) {
//                curr = curr->next;
//            }
//            curr->next = newNode;
//        }
//    }
//
//    int searchDirectChaining(int key, int M) {
//        int pos = hash(key, M);
//
//        if (table[pos] != nullptr) {
//            Node* curr = table[pos];
//            while (curr != nullptr) {
//                if (curr->key == key) {
//                    return pos;
//                }
//                curr = curr->next;
//            }
//        }
//        return -1;
//    }
//
//    void deleteDirectChaining(int key, int M) {
//        int pos = hash(key, M);
//
//        if (table[pos] != nullptr) {
//            Node* curr = table[pos];
//            Node* prev = nullptr;
//            while (curr != nullptr) {
//                if (curr->key == key) {
//                    if (prev == nullptr) {
//                        table[pos] = curr->next;
//                    }
//                    else {
//                        prev->next = curr->next;
//                    }
//                    delete curr;
//                    return;
//                }
//                prev = curr;
//                curr = curr->next;
//            }
//        }
//    }
//
//    void display() {
//        cout << "Hash Table:" << endl;
//        for (int i = 0; i < size; i++) {
//            if (table[i] != nullptr) {
//                cout << i << ": ";
//                Node* curr = table[i];
//                while (curr != nullptr) {
//                    cout << curr->key << " -> ";
//                    curr = curr->next;
//                }
//                cout << "nullptr" << endl;
//            }
//        }
//    }
//};
//
//int getIntegerInput() {
//    int value;
//    while (true) {
//        if (cin >> value) {
//            break;
//        }
//        cin.clear();
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        cout << "Invalid input! Please enter an integer: ";
//    }
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    return value;
//}
//
//int main() {
//    int size;
//    cout << "Enter the size of the hash table: ";
//    size = getIntegerInput();
//
//    int M;
//    cout << "Enter the value of M: ";
//    M = getIntegerInput();
//
//    HashTable hashTable(size);
//
//    int choice;
//    do {
//        cout << endl;
//        cout << "Menu:" << endl;
//        cout << "1. Direct Chaining" << endl;
//        cout << "2. Coalesced Chaining" << endl;
//        cout << "0. Exit" << endl;
//        cout << "Enter your choice: ";
//        choice = getIntegerInput();
//
//        switch (choice) {
//        case 1: {
//            int element;
//            cout << "Enter the elements to insert (enter -1 to end): ";
//            while ((element = getIntegerInput()) != -1) {
//                hashTable.insertDirectChaining(element, M);
//            }
//
//            int submenuChoice;
//            do {
//                cout << endl;
//                cout << "Direct Chaining Submenu:" << endl;
//                cout << "1. Search for an element" << endl;
//                cout << "2. Delete an element" << endl;
//                cout << "3. Display the hash table" << endl;
//                cout << "4. Insert more elements" << endl;
//                cout << "0. Back to Main Menu" << endl;
//                cout << "Enter your choice: ";
//                submenuChoice = getIntegerInput();
//
//                switch (submenuChoice) {
//                case 1: {
//                    cout << "Enter the element to search: ";
//                    int searchElement = getIntegerInput();
//                    int position = hashTable.searchDirectChaining(searchElement, M);
//                    if (position != -1) {
//                        cout << "Element found at position " << position << " in the hash table!" << endl;
//                    }
//                    else {
//                        cout << "Element not found!" << endl;
//                    }
//                    break;
//                }
//                case 2: {
//                    cout << "Enter the element to delete: ";
//                    int deleteElement = getIntegerInput();
//                    hashTable.deleteDirectChaining(deleteElement, M);
//                    break;
//                }
//                case 3:
//                    hashTable.display();
//                    break;
//                case 4: {
//                    cout << "Enter the elements to insert (enter -1 to end): ";
//                    while ((element = getIntegerInput()) != -1) {
//                        hashTable.insertDirectChaining(element, M);
//                    }
//                    break;
//                }
//                case 0:
//                    break;
//                default:
//                    cout << "Invalid choice!" << endl;
//                    break;
//                }
//            } while (submenuChoice != 0);
//
//            break;
//        }
//        case 2:
//            // Coalesced Chaining implementation
//            cout << "Coalesced Chaining is not implemented yet." << endl;
//            break;
//        case 0:
//            cout << "Exiting..." << endl;
//            break;
//        default:
//            cout << "Invalid choice!" << endl;
//            break;
//        }
//    } while (choice != 0);
//
//    return 0;
//}