//#include <iostream>
//#include <queue>
//#include <stack>
//using namespace std;
//
//struct BSTNode {
//    int data;
//    BSTNode* left;
//    BSTNode* right;
//};
//
//class BinarySearchTree {
//private:
//    BSTNode* root;
//
//public:
//    BSTNode* getRoot() {
//        return root;
//    }
//
//    BinarySearchTree() {
//        root = nullptr;
//    }
//
//    BSTNode* createBSTNode(int value) {
//        BSTNode* newBSTNode = new BSTNode();
//        newBSTNode->data = value;
//        newBSTNode->left = nullptr;
//        newBSTNode->right = nullptr;
//        return newBSTNode;
//    }
//
//    BSTNode* insert(BSTNode* root, int value) {
//        if (root == nullptr) {
//            root = createBSTNode(value);
//        }
//        else if (value <= root->data) {
//            root->left = insert(root->left, value);
//        }
//        else {
//            root->right = insert(root->right, value);
//        }
//        return root;
//    }
//
//    void addElements() {
//        int numElements;
//        cout << "Enter the number of elements to add: ";
//        cin >> numElements;
//
//        cout << "Enter the elements: ";
//        for (int i = 0; i < numElements; i++) {
//            int element;
//            cin >> element;
//            root = insert(root, element);
//        }
//    }
//
//    void drawBST() {
//        drawBSTUtil(root, 0);
//    }
//
//    void drawBSTUtil(BSTNode* root, int space) {
//        if (root == nullptr) {
//            return;
//        }
//
//        int spacing = 6; // Adjust this value to increase/decrease spacing between BSTNodes
//
//        space += spacing;
//
//        drawBSTUtil(root->right, space);
//
//        cout << endl;
//        for (int i = spacing; i < space; i++) {
//            cout << " ";
//        }
//        cout << root->data << endl;
//
//        drawBSTUtil(root->left, space);
//    }
//
//    void printBSTNodeAtLevel(int level) {
//        cout << "BSTNodes at level " << level << ": ";
//        printBSTNodeAtLevelUtil(root, level);
//        cout << endl;
//    }
//
//    void printBSTNodeAtLevelUtil(BSTNode* root, int level) {
//        if (root == nullptr) {
//            return;
//        }
//        if (level == 0) {
//            cout << root->data << " ";
//        }
//        else {
//            printBSTNodeAtLevelUtil(root->left, level - 1);
//            printBSTNodeAtLevelUtil(root->right, level - 1);
//        }
//    }
//
//    void printLeafBSTNodes() {
//        cout << "Leaf BSTNodes: ";
//        printLeafBSTNodesUtil(root);
//        cout << endl;
//    }
//
//    void printLeafBSTNodesUtil(BSTNode* root) {
//        if (root == nullptr) {
//            return;
//        }
//        if (root->left == nullptr && root->right == nullptr) {
//            cout << root->data << " ";
//        }
//        else {
//            printLeafBSTNodesUtil(root->left);
//            printLeafBSTNodesUtil(root->right);
//        }
//    }
//
//    void printRightView() {
//        cout << "Right view of BST: ";
//        printRightViewUtil(root);
//        cout << endl;
//    }
//
//    void printRightViewUtil(BSTNode* root) {
//        if (root == nullptr) {
//            return;
//        }
//
//        queue<BSTNode*> q;
//        q.push(root);
//
//        while (!q.empty()) {
//            int size = q.size();
//            for (int i = 0; i < size; i++) {
//                BSTNode* current = q.front();
//                q.pop();
//
//                if (i == size - 1) {
//                    cout << current->data << " ";
//                }
//
//                if (current->left) {
//                    q.push(current->left);
//                }
//                if (current->right) {
//                    q.push(current->right);
//                }
//            }
//        }
//    }
//
//    void printLeftView() {
//        cout << "Left view of BST: ";
//        printLeftViewUtil(root);
//        cout << endl;
//    }
//
//    void printLeftViewUtil(BSTNode* root) {
//        if (root == nullptr) {
//            return;
//        }
//
//        queue<BSTNode*> q;
//        q.push(root);
//
//        while (!q.empty()) {
//            int size = q.size();
//            for (int i = 0; i < size; i++) {
//                BSTNode* current = q.front();
//                q.pop();
//
//                if (i == 0) {
//                    cout << current->data << " ";
//                }
//
//                if (current->left) {
//                    q.push(current->left);
//                }
//                if (current->right) {
//                    q.push(current->right);
//                }
//            }
//        }
//    }
//
//    bool findKey(int key) {
//        return findKeyUtil(root, key);
//    }
//
//    bool findKeyUtil(BSTNode* root, int key) {
//        if (root == nullptr) {
//            return false;
//        }
//        if (root->data == key) {
//            return true;
//        }
//        else if (key < root->data) {
//            return findKeyUtil(root->left, key);
//        }
//        else {
//            return findKeyUtil(root->right, key);
//        }
//    }
//
//    BSTNode* deleteBSTNode(BSTNode* root, int key) {
//        if (root == nullptr) {
//            return root;
//        }
//        else if (key < root->data) {
//            root->left = deleteBSTNode(root->left, key);
//        }
//        else if (key > root->data) {
//            root->right = deleteBSTNode(root->right, key);
//        }
//        else {
//            if (root->left == nullptr && root->right == nullptr) {
//                delete root;
//                root = nullptr;
//            }
//            else if (root->left == nullptr) {
//                BSTNode* temp = root;
//                root = root->right;
//                delete temp;
//            }
//            else if (root->right == nullptr) {
//                BSTNode* temp = root;
//                root = root->left;
//                delete temp;
//            }
//            else {
//                BSTNode* temp = findMin(root->right);
//                root->data = temp->data;
//                root->right = deleteBSTNode(root->right, temp->data);
//            }
//        }
//        return root;
//    }
//
//    BSTNode* findMin(BSTNode* root) {
//        while (root->left != nullptr) {
//            root = root->left;
//        }
//        return root;
//    }
//
//    void printInorderTraversal() {
//        cout << "Inorder traversal: ";
//        printInorderTraversalUtil(root);
//        cout << endl;
//    }
//
//    void printInorderTraversalUtil(BSTNode* root) {
//        if (root == nullptr) {
//            return;
//        }
//        printInorderTraversalUtil(root->left);
//        cout << root->data << " ";
//        printInorderTraversalUtil(root->right);
//    }
//
//    void printPreorderTraversal() {
//        cout << "Preorder traversal: ";
//        printPreorderTraversalUtil(root);
//        cout << endl;
//    }
//
//    void printPreorderTraversalUtil(BSTNode* root) {
//        if (root == nullptr) {
//            return;
//        }
//        cout << root->data << " ";
//        printPreorderTraversalUtil(root->left);
//        printPreorderTraversalUtil(root->right);
//    }
//
//    void printPostorderTraversal() {
//        cout << "Postorder traversal: ";
//        printPostorderTraversalUtil(root);
//        cout << endl;
//    }
//
//    void printPostorderTraversalUtil(BSTNode* root) {
//        if (root == nullptr) {
//            return;
//        }
//        printPostorderTraversalUtil(root->left);
//        printPostorderTraversalUtil(root->right);
//        cout << root->data << " ";
//    }
//
//    void printLevelOrderTraversal() {
//        cout << "Level order traversal: ";
//        printLevelOrderTraversalUtil(root);
//        cout << endl;
//    }
//
//    void printLevelOrderTraversalUtil(BSTNode* root) {
//        if (root == nullptr) {
//            return;
//        }
//
//        queue<BSTNode*> q;
//        q.push(root);
//
//        while (!q.empty()) {
//            BSTNode* current = q.front();
//            q.pop();
//
//            cout << current->data << " ";
//
//            if (current->left) {
//                q.push(current->left);
//            }
//            if (current->right) {
//                q.push(current->right);
//            }
//        }
//    }
//
//    // Function to perform Preorder traversal using stack
//    void preorderTraversal(BSTNode* root) {
//        if (root == nullptr)
//            return;
//
//        stack<BSTNode*> stack;
//        stack.push(root);
//
//        while (!stack.empty()) {
//            BSTNode* current = stack.top();
//            stack.pop();
//            cout << current->data << " ";
//
//            if (current->right)
//                stack.push(current->right);
//            if (current->left)
//                stack.push(current->left);
//        }
//    }
//
//    // Function to perform Postorder traversal using stack
//    stack<BSTNode*> resultStack;
//    void postorderTraversal(BSTNode* root) {
//        if (root == nullptr)
//            return;
//
//        stack<BSTNode*> stack;
//        stack.push(root);
//
//        while (!stack.empty()) {
//            BSTNode* current = stack.top();
//            stack.pop();
//            resultStack.push(current);
//
//            if (current->left)
//                stack.push(current->left);
//            if (current->right)
//                stack.push(current->right);
//        }
//
//        while (!resultStack.empty()) {
//            BSTNode* current = resultStack.top();
//            resultStack.pop();
//            cout << current->data << " ";
//        }
//    }
//
//    // Function to perform Level order traversal using stack
//    void levelorderTraversal(BSTNode* root) {
//        if (root == nullptr)
//            return;
//
//        stack<BSTNode*> stack;
//        stack.push(root);
//
//        while (!stack.empty()) {
//            BSTNode* current = stack.top();
//            stack.pop();
//            cout << current->data << " ";
//
//            if (current->right)
//                stack.push(current->right);
//            if (current->left)
//                stack.push(current->left);
//        }
//    }
//
//
//    int getHeight() {
//        return getHeightUtil(root);
//    }
//
//    int getHeightUtil(BSTNode* root) {
//        if (root == nullptr) {
//            return -1;
//        }
//        int leftHeight = getHeightUtil(root->left);
//        int rightHeight = getHeightUtil(root->right);
//        return max(leftHeight, rightHeight) + 1;
//    }
//
//    BSTNode* findSmallestBSTNode() {
//        return findSmallestBSTNodeUtil(root);
//    }
//
//    BSTNode* findSmallestBSTNodeUtil(BSTNode* root) {
//        if (root == nullptr || root->left == nullptr) {
//            return root;
//        }
//        return findSmallestBSTNodeUtil(root->left);
//    }
//
//    bool isBalanced() {
//        return isBalancedUtil(root);
//    }
//
//    bool isBalancedUtil(BSTNode* root) {
//        if (root == nullptr) {
//            return true;
//        }
//        int leftHeight = getHeightUtil(root->left);
//        int rightHeight = getHeightUtil(root->right);
//        if (abs(leftHeight - rightHeight) <= 1 && isBalancedUtil(root->left) && isBalancedUtil(root->right)) {
//            return true;
//        }
//        return false;
//    }
//
//    bool isBST() {
//        return isBSTUtil(root, INT_MIN, INT_MAX);
//    }
//   
//    bool isBSTUtil(BSTNode* root, int minValue, int maxValue) {
//        if (root == nullptr) {
//            return true;
//        }
//        if (root->data > minValue && root->data < maxValue &&
//            isBSTUtil(root->left, minValue, root->data) &&
//            isBSTUtil(root->right, root->data, maxValue)) {
//            return true;
//        }
//        return false;
//    }
//
//    BSTNode* convertToBalancedBST() {
//        int BSTNodeCount = countBSTNodes(root);
//        return convertToBalancedBSTUtil(root, BSTNodeCount);
//    }
//
//    BSTNode* convertToBalancedBSTUtil(BSTNode* root, int BSTNodeCount) {
//        if (root == nullptr) {
//            return nullptr;
//        }
//
//        BSTNode* sortedArr = new BSTNode[BSTNodeCount];
//        storeInOrder(root, sortedArr, 0);
//
//        return buildBalancedBST(sortedArr, 0, BSTNodeCount - 1);
//    }
//
//    void storeInOrder(BSTNode* root, BSTNode* arr, int index) {
//        if (root == nullptr) {
//            return;
//        }
//
//        storeInOrder(root->left, arr, index);
//        arr[index] = *root;
//        storeInOrder(root->right, arr, index + 1);
//    }
//
//    BSTNode* buildBalancedBST(BSTNode* arr, int start, int end) {
//        if (start > end) {
//            return nullptr;
//        }
//
//        int mid = (start + end) / 2;
//        BSTNode* root = createBSTNode(arr[mid].data);
//
//        root->left = buildBalancedBST(arr, start, mid - 1);
//        root->right = buildBalancedBST(arr, mid + 1, end);
//
//        return root;
//    }
//
//    int countBSTNodes(BSTNode* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//        return 1 + countBSTNodes(root->left) + countBSTNodes(root->right);
//    }
//
//    // Function to perform Inorder traversal using stack
//    void inorderTraversal(BSTNode* root) {
//        if (root == nullptr)
//            return;
//
//        stack<BSTNode*> stack;
//        BSTNode* current = root;
//
//        while (current != nullptr || !stack.empty()) {
//            while (current != nullptr) {
//                stack.push(current);
//                current = current->left;
//            }
//            current = stack.top();
//            stack.pop();
//            cout << current->data << " ";
//            current = current->right;
//        }
//    }
//
//
//};
//
//int main() {
//    BinarySearchTree bst;
//
//    int choice;
//    do {
//        cout << endl;
//        cout << "-------------------------------" << endl;
//        cout << " Binay Search Tree Operations " << endl;
//        cout << "-------------------------------" << endl;
//        cout << "1. Add elements to BST" << endl;
//        cout << "2. Draw BST" << endl;
//        cout << "3. Print BSTNode at a given level" << endl;
//        cout << "4. Print all leaf BSTNodes" << endl;
//        cout << "5. Print right view of BST" << endl;
//        cout << "6. Print left view of BST" << endl;
//        cout << "7. Find a key in BST" << endl;
//        cout << "8. Delete a BSTNode in BST" << endl;
//        cout << "9. Inorder traversal (LNR) using recursion" << endl;
//        cout << "10. Preorder traversal (NLR) using recursion" << endl;
//        cout << "11. Postorder traversal (LRN) using recursion" << endl;
//        cout << "12. Level order traversal using recursion" << endl;
//        cout << "13. Calculate height of BST" << endl;
//        cout << "14. Find smallest BSTNode in BST" << endl;
//        cout << "15. Check if BST is balanced" << endl;
//        cout << "16. Check if BST is a valid BST" << endl;
//        cout << "17. Convert BST to balanced BST" << endl;
//        cout << "18. Inoder Traversal using Stack" << endl;
//        cout << "19. Preoder Traversal using Stack" << endl;
//        cout << "20. Postoder Traversal using Stack" << endl;
//        cout << "21. Level oder Traversal using Stack" << endl;
//        cout << "0. Exit" << endl;
//        cout << "-------------------------------" << endl;
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            bst.addElements();
//            break;
//        case 2:
//            bst.drawBST();
//            break;
//        case 3:
//            int level;
//            cout << "Enter the level: ";
//            cin >> level;
//            bst.printBSTNodeAtLevel(level);
//            break;
//        case 4:
//            bst.printLeafBSTNodes();
//            break;
//        case 5:
//            bst.printRightView();
//            break;
//        case 6:
//            bst.printLeftView();
//            break;
//        case 7:
//            int key;
//            cout << "Enter the key to search: ";
//            cin >> key;
//            if (bst.findKey(key)) {
//                cout << "Key found in BST" << endl;
//            }
//            else {
//                cout << "Key not found in BST" << endl;
//            }
//            break;
//        case 8:
//            int deleteKey;
//            cout << "Enter the key to delete: ";
//            cin >> deleteKey;
//            bst.deleteBSTNode(bst.getRoot(), deleteKey);
//            break;
//        case 9:
//            bst.printInorderTraversal();
//            break;
//        case 10:
//            bst.printPreorderTraversal();
//            break;
//        case 11:
//            bst.printPostorderTraversal();
//            break;
//        case 12:
//            bst.printLevelOrderTraversal();
//            break;
//        case 13:
//                cout << "Height of the BST: " << bst.getHeight() << endl;
//            break;
//        case 14:
//            cout << "Smallest BSTNode in the BST: " << bst.findSmallestBSTNode() << endl;
//            break;
//        case 15:
//            if (bst.isBalanced()) {
//                cout << "The BST is balanced." << endl;
//            }
//            else {
//                cout << "The BST is not balanced." << endl;
//            }
//            break;
//        case 16:
//            if (bst.isBST()) {
//                cout << "The BST is a valid BST." << endl;
//            }
//            else {
//                cout << "The BST is not a valid BST." << endl;
//            }
//            break;
//        case 17:
//            bst.convertToBalancedBST();
//            cout << "BST converted to balanced BST." << endl;
//            break;
//        case 0:
//            cout << "Exiting..." << endl;
//            break;
//        default:
//            cout << "Invalid choice. Please try again." << endl;
//            break;
//        }
//    } while (choice != 0);
//
//    return 0;
//}