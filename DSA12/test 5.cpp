//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//class TreeNode {
//public:
//    int data;
//    TreeNode* left;
//    TreeNode* right;
//
//    TreeNode(int value) {
//        data = value;
//        left = nullptr;
//        right = nullptr;
//    }
//};
//
//class BinaryTree {
//private:
//    TreeNode* root;
//
//public:
//    BinaryTree() {
//        root = nullptr;
//    }
//
//    TreeNode* getRoot() {
//        return root;
//    }
//
//    void drawTree(TreeNode* node, int space) {
//        if (node == nullptr)
//            return;
//
//        space += 10;
//
//        drawTree(node->right, space);
//
//        cout << "\n";
//        for (int i = 10; i < space; i++)
//            cout << " ";
//        cout << node->data << "\n";
//
//        drawTree(node->left, space);
//    }
//
//    int maxDepth(TreeNode* node) {
//        if (node == nullptr)
//            return 0;
//
//        int leftDepth = maxDepth(node->left);
//        int rightDepth = maxDepth(node->right);
//
//        return max(leftDepth, rightDepth) + 1;
//    }
//
//    void insertNode(int value) {
//        TreeNode* newNode = new TreeNode(value);
//
//        if (root == nullptr) {
//            root = newNode;
//            return;
//        }
//
//        queue<TreeNode*> q;
//        q.push(root);
//
//        while (!q.empty()) {
//            TreeNode* current = q.front();
//            q.pop();
//
//            if (current->left == nullptr) {
//                current->left = newNode;
//                return;
//            }
//            else {
//                q.push(current->left);
//            }
//
//            if (current->right == nullptr) {
//                current->right = newNode;
//                return;
//            }
//            else {
//                q.push(current->right);
//            }
//        }
//    }
//
//    void deleteNode(int value) {
//        if (root == nullptr)
//            return;
//
//        if (root->left == nullptr && root->right == nullptr) {
//            if (root->data == value) {
//                delete root;
//                root = nullptr;
//                return;
//            }
//        }
//
//        queue<TreeNode*> q;
//        q.push(root);
//
//        TreeNode* targetNode = nullptr;
//        TreeNode* deepestNode = nullptr;
//
//        while (!q.empty()) {
//            deepestNode = q.front();
//            q.pop();
//
//            if (deepestNode->data == value)
//                targetNode = deepestNode;
//
//            if (deepestNode->left != nullptr)
//                q.push(deepestNode->left);
//
//            if (deepestNode->right != nullptr)
//                q.push(deepestNode->right);
//        }
//
//        if (targetNode != nullptr) {
//            int temp = deepestNode->data;
//            deleteDeepestNode(deepestNode);
//            targetNode->data = temp;
//        }
//    }
//
//    void deleteDeepestNode(TreeNode* node) {
//        queue<TreeNode*> q;
//        q.push(root);
//
//        while (!q.empty()) {
//            TreeNode* current = q.front();
//            q.pop();
//
//            if (current->right != nullptr) {
//                if (current->right == node) {
//                    delete node;
//                    current->right = nullptr;
//                    return;
//                }
//                else {
//                    q.push(current->right);
//                }
//            }
//
//            if (current->left != nullptr) {
//                if (current->left == node) {
//                    delete node;
//                    current->left = nullptr;
//                    return;
//                }
//                else {
//                    q.push(current->left);
//                }
//            }
//        }
//    }
//
//    void levelOrderTraversal() {
//        if (root == nullptr)
//            return;
//
//        queue<TreeNode*> q;
//        q.push(root);
//
//        while (!q.empty()) {
//            TreeNode* current = q.front();
//            q.pop();
//
//            cout << current->data << " ";
//
//            if (current->left != nullptr)
//                q.push(current->left);
//
//            if (current->right != nullptr)
//                q.push(current->right);
//        }
//    }
//};
//
//void printMenu() {
//    cout << "\nBinary Tree Menu:\n";
//    cout << "1. Insert element\n";
//    cout << "2. Delete element\n";
//    cout << "3. Draw tree\n";
//    cout << "4. Maximum Depth of Binary Tree\n";
//    cout << "5. Level Order Traversal\n";
//    cout << "6. Exit\n";
//    cout << "Enter your choice: ";
//}
//
//int main() {
//    BinaryTree tree;
//
//    cout << "Enter values for the binary tree (enter -1 to stop):\n";
//    int value;
//    while (true) {
//        cout << "Enter value: ";
//        cin >> value;
//        if (value == -1) {
//            break;
//        }
//        tree.insertNode(value);
//    }
//
//
//    while (true) {
//        printMenu();
//
//        int choice;
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            int value;
//            cout << "Enter value to insert: ";
//            cin >> value;
//            tree.insertNode(value);
//            break;
//        }
//        case 2: {
//            int value;
//            cout << "Enter value to delete: ";
//            cin >> value;
//            tree.deleteNode(value);
//            break;
//        }
//        case 3: {
//            cout << "\nBinary Tree:\n";
//            tree.drawTree(tree.getRoot(), 0);
//            break;
//        }
//        case 4: {
//            int depth = tree.maxDepth(tree.getRoot());
//            cout << "\nMaximum Depth of Binary Tree: " << depth << "\n";
//            break;
//        }
//        case 5: {
//            cout << "\nLevel Order Traversal: ";
//            tree.levelOrderTraversal();
//            cout << "\n";
//            break;
//        }
//        case 0: {
//            cout << "\nExiting program...\n";
//            exit(0);
//        }
//        default: {
//            cout << "\nInvalid choice! Please try again.\n";
//            break;
//        }
//        }
//    }
//
//    return 0;
//}