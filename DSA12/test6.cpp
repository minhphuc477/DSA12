//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct CCNode {
//    int data;
//    int ccnext;
//};
//
//class HashTable {
//private:
//    vector<CCNode> table;
//    int size;
//
//public:
//    HashTable(int tableSize) {
//        size = tableSize;
//        table.resize(size);
//        for (int i = 0; i < size; i++) {
//            table[i].data = -1;
//            table[i].ccnext = -1;
//        }
//    }
//
//    void insert(int data, int M) {
//        int hashValue = data % M;
//
//        if (table[hashValue].data == -1) {
//            table[hashValue].data = data;
//        }
//        else {
//            int currentIndex = hashValue;
//            int ccnextIndex = table[hashValue].ccnext;
//
//            while (ccnextIndex != -1) {
//                currentIndex = ccnextIndex;
//                ccnextIndex = table[ccnextIndex].ccnext;
//            }
//
//            for (int i = size - 1; i >= 0; i--) {
//                if (table[i].data == -1) {
//                    table[i].data = data;
//                    table[currentIndex].ccnext = i;
//                    return;
//                }
//            }
//
//            cout << "Hash table is full. Unable to insert data: " << data << endl;
//        }
//    }
//
//    void remove(int data) {
//        int hashValue = data % size;
//
//        if (table[hashValue].data == data) {
//            table[hashValue].data = -1;
//            table[hashValue].ccnext = -1;
//        }
//        else {
//            int currentIndex = hashValue;
//            int ccnextIndex = table[hashValue].ccnext;
//
//            while (ccnextIndex != -1) {
//                if (table[ccnextIndex].data == data) {
//                    table[currentIndex].ccnext = table[ccnextIndex].ccnext;
//                    table[ccnextIndex].data = -1;
//                    table[ccnextIndex].ccnext = -1;
//                    return;
//                }
//                currentIndex = ccnextIndex;
//                ccnextIndex = table[ccnextIndex].ccnext;
//            }
//
//            cout << "Element not found: " << data << endl;
//        }
//    }
//
//    int search(int data) {
//        int hashValue = data % size;
//
//        if (table[hashValue].data == data) {
//            return hashValue;
//        }
//        else {
//            int ccnextIndex = table[hashValue].ccnext;
//
//            while (ccnextIndex != -1) {
//                if (table[ccnextIndex].data == data) {
//                    return ccnextIndex;
//                }
//                ccnextIndex = table[ccnextIndex].ccnext;
//            }
//        }
//
//        return -1;
//    }
//
//    void print() {
//        cout << "Hash value\tData\tNext" << endl;
//        cout << "-------------------------" << endl;
//
//        for (int i = 0; i < size; i++) {
//            if (table[i].data != -1) {
//                cout << i << "\t\t";
//                cout << table[i].data << "\t";
//                if (table[i].ccnext != -1) {
//                    cout << table[i].ccnext;
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
//    int hashTableSize, M;
//
//    cout << "Enter the size of the hash table: ";
//    cin >> hashTableSize;
//
//    cout << "Enter the value of M: ";
//    cin >> M;
//
//    HashTable hashTable(hashTableSize);
//
//    int option;
//    int element;
//
//    do {
//        cout << "Menu:\n";
//        cout << "1. Insert an element\n";
//        cout << "2. Delete an element\n";
//        cout << "3. Search for an element\n";
//        cout << "4. Print the hash table\n";
//        cout << "5. Exit\n";
//        cout << "Enter your option: ";
//        cin >> option;
//
//        switch (option) {
//        case 1: {
//            cout << "Enter a value to insert (-1 to stop): ";
//            cin >> element;
//            while (element != -1) {
//                hashTable.insert(element, M);
//                cout << "Enter a value to insert (-1 to stop): ";
//                cin >> element;
//            }
//            break;
//        }
//        case 2: {
//            cout << "Enter a value to delete: ";
//            cin >> element;
//            hashTable.remove(element);
//            break;
//        }
//        case 3: {
//            cout << "Enter a value to search: ";
//            cin >> element;
//            int position = hashTable.search(element);
//            if (position != -1) {
//                cout << "Element found at position: " << position << endl;
//            }
//            else {
//                cout << "Element not found." << endl;
//            }
//            break;
//        }
//        case 4:
//            hashTable.print();
//            break;
//        case 5:
//            cout << "Exiting the program." << endl;
//            break;
//        default:
//            cout << "Invalid option. Please try again." << endl;
//            break;
//        }
//    } while (option != 5);
//
//    return 0;
//}