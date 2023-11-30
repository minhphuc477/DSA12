//#include <iostream>
//#include <vector>
//#include <cstdlib>
//
//using namespace std;
//
//// Direct chaining
//struct DCNode {
//    int key;
//    DCNode* next;
//};
//
//// Coalesced chaining
//struct CCNode {
//    int data;
//    int ccnext;
//};
//
//class HashTable {
//private:
//    vector<CCNode> table1;
//    vector<DCNode*> table;
//    int size;
//    int M;
//
//public:
//    // Constructor
//    HashTable(int size, bool isDC, int M) {
//        this->size = size;
//        this->M = M;
//        if (isDC) {
//            table.resize(size, nullptr);
//        }
//        else {
//            table1.resize(size);
//            for (int i = 0; i < size; i++) {
//                table1[i].data = -1;
//                table1[i].ccnext = -1;
//            }
//            table.resize(size, nullptr); // Add this line
//        }
//    }
//
//    // Direct Chaining (DC)
//    int hashDC(int key) {
//        return key % M;
//    }
//
//    void insertDC(int key) {
//        int pos = hashDC(key);
//        DCNode* newNode = new DCNode;
//        newNode->key = key;
//        newNode->next = nullptr;
//
//        if (table[pos] == nullptr) {
//            table[pos] = newNode;
//        }
//        else {
//            DCNode* curr = table[pos];
//            while (curr->next != nullptr) {
//                curr = curr->next;
//            }
//            curr->next = newNode;
//        }
//    }
//
//    void removeDC(int key) {
//        int pos = hashDC(key);
//
//        if (table[pos] == nullptr) {
//            cout << "Element not found!" << endl;
//            return;
//        }
//
//        DCNode* curr = table[pos];
//        DCNode* prev = nullptr;
//
//        while (curr != nullptr && curr->key != key) {
//            prev = curr;
//            curr = curr->next;
//        }
//
//        if (curr == nullptr) {
//            cout << "Element not found!" << endl;
//            return;
//        }
//
//        if (prev == nullptr) {
//            table[pos] = curr->next;
//        }
//        else {
//            prev->next = curr->next;
//        }
//
//        delete curr;
//        cout << "Element removed successfully!" << endl;
//    }
//
//    bool searchDC(int key) {
//        int pos = hashDC(key);
//        DCNode* curr = table[pos];
//       
//
//        while (curr != nullptr) {
//            if (curr->key == key) {
//                cout << "Element found! At position " << pos << endl;
//                return true;
//            }
//            curr = curr->next;
//        }
//
//        cout << "Element not found!" << endl;
//        return false;
//    }
//
//
//    void displayDC() {
//        cout << "Hash Table:" << endl;
//        for (int i = 0; i < size; i++) {
//            if (table[i] != nullptr) {
//                cout << i << ": ";
//                DCNode* curr = table[i];
//                while (curr != nullptr) {
//                    cout << curr->key << " -> ";
//                    curr = curr->next;
//                }
//                cout << "nullptr" << endl;
//            }
//        }
//    }
//
//    // Coalesced Chaining (CC)
//    int hashCC(int key) {
//        return key % M;
//    }
//
//    void insertCC(int key) {
//        int pos = hashCC(key);
//        int ccnextIndex = -1;
//
//        if (table1[pos].data == -1) {
//            table1[pos].data = key;
//            table1[pos].ccnext = -1;
//        }
//        else {
//            ccnextIndex = pos;
//            while (table1[ccnextIndex].ccnext != -1) {
//                ccnextIndex = table1[ccnextIndex].ccnext;
//            }
//            int availableSlot = -1;
//            for (int i = 0; i < size; i++) {
//                if (table1[i].data == -1 && table1[i].ccnext == -1) {
//                    availableSlot = i;
//                    break;
//                }
//            }
//            if (availableSlot != -1) {
//                table1[ccnextIndex].ccnext = availableSlot;
//                table1[availableSlot].data = key;
//                table1[availableSlot].ccnext = -1;
//            }
//            else {
//                cout << "Hash table is full!" << endl;
//            }
//        }
//    }
//
//    void removeCC(int key) {
//        int pos = hashCC(key);
//        int ccnextIndex = pos;
//        while (ccnextIndex != -1) {
//            if (table1[ccnextIndex].data == key) {
//                table1[ccnextIndex].data = -1;
//                table1[ccnextIndex].ccnext = -1;
//                cout << "Element removed successfully!" << endl;
//                return;
//            }
//            ccnextIndex = table1[ccnextIndex].ccnext;
//        }
//        cout << "Element not found!" << endl;
//    }
//
//    bool searchCC(int key) {
//        int pos = hashCC(key);
//        int ccnextIndex = pos;
//        while (ccnextIndex != -1) {
//            if (table1[ccnextIndex].data == key) {
//                cout << "Element found! At position " << pos << endl;
//                return true;
//            }
//            ccnextIndex = table1[ccnextIndex].ccnext;
//        }
//
//        cout << "Element not found!" << endl;
//        return false;
//    }
//
//    void displayCC() {
//        cout << "Hash value\tData\tNext" << endl;
//        cout << "-------------------------" << endl;
//
//        for (int i = 0; i < size; i++) {
//            if (table1[i].data != -1) {
//                cout << i << "\t\t";
//                cout << table1[i].data << "\t";
//                if (table1[i].ccnext != -1) {
//                    cout << table1[i].ccnext;
//                }
//                else {
//                    cout << "NULL";
//                }
//                cout << endl;
//            }
//        }
//    }
//};
//
//int main() {
//    int size, M;
//    int isDC;
//
//    cout << "Enter the size of the hash table: ";
//    cin >> size;
//    cout << "Enter the value of M for hashing: ";
//    cin >> M;
//    cout << "Choose chaining method (0 - Direct Chaining, 1 - Coalesced Chaining): ";
//    cin >> isDC;
//
//    HashTable hashTable(size, isDC == 0, M);
//
//    int choice, key;
//    bool running = true;
//
//    while (running) {
//        cout << "\n1. Insert elements";
//        cout << "\n2. Remove an element";
//        cout << "\n3. Search for an element";
//        cout << "\n4. Display the hash table";
//        cout << "\n0. Exit";
//        cout << "\nEnter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            cout << "Enter the elements to insert (enter -1 to end): ";
//            while (cin >> key && key != -1) {
//                if (isDC == 0) {
//                    hashTable.insertDC(key);
//                }
//                else {
//                    hashTable.insertCC(key);
//                }
//            }
//            break;
//        }
//        case 2: {
//            cout << "Enter the key to remove: ";
//            cin >> key;
//            if (isDC == 0) {
//                hashTable.removeDC(key);
//            }
//            else {
//                hashTable.removeCC(key);
//            }
//            break;
//        }
//        case 3: {
//            cout << "Enter the key to search: ";
//            cin >> key;
//            if (isDC == 0) {
//                hashTable.searchDC(key);
//            }
//            else {
//                hashTable.searchCC(key);
//            }
//            break;
//        }
//        case 4: {
//            if (isDC == 0) {
//                hashTable.displayDC();
//            }
//            else {
//                hashTable.displayCC();
//            }
//            break;
//        }
//        case 0:
//            running = false;
//            break;
//        default:
//            cout << "Invalid choice!" << endl;
//            break;
//        }
//    }
//}