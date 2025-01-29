#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// created tree
Node* createTree() {
    cout << "Enter the value for Node: ";
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    // Step1: create Node
    Node* root = new Node(data);

    // Step2: Create left subtree
    root->left = createTree();

    // Step3: Create right subtree
    root->right = createTree();

    return root;
}

void preOrderTraversal(Node* root) {
    // Base case
    if (root == NULL) {
        return;
    }
    // N L R
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inorderTraversal(Node* root) {
    // Base case
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    // Base case
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << front->data << " ";
            if (front->left != NULL) {
                q.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
            }
        }
    }
}

// maximum depth (height) of the binary tree
int maxDepth(Node* root) {
    if (root == NULL)
        return 0;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int count = 1;

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front == NULL) {
            if (!q.empty()) {
                count++;
                q.push(NULL);
            }
        } else {
            if (front->left != NULL) {
                q.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
            }
        }
    }
    return count;
}

//height of the binary tree
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// diameter of the binary tree
int diameterOfBinaryTree(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int option1 = diameterOfBinaryTree(root->left);
    int option2 = diameterOfBinaryTree(root->right);
    int option3 = height(root->left) + height(root->right) + 1;
    return max(option1, max(option2, option3));
}

int main() {
    Node* root = createTree();

    cout << "Printing Preorder: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Printing Inorder: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Printing PostOrder: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Level Order: ";
    levelOrderTraversal(root);
    cout << endl;

    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Diameter of Tree: " << diameterOfBinaryTree(root) << endl;

    return 0;
}
