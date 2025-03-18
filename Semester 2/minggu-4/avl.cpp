#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int key) : data(key), left(NULL), right(NULL), height(1) {}
};

class AVLTree {
private:
    Node *root;

    int height(Node* node) {
        if (node == NULL) return 0;
        return node->height;
    }

    int balance_factor(Node* node) {
        if (node == NULL) return 0;
        return height(node->left) - height(node->right);
    }

    Node* right_rotate(Node *A) {
        Node *B = A->left;
        Node *T2 = B->right;

        B->right = A;
        A->left = T2;

        A->height = 1 + max(height(A->left), height(A->right));
        B->height = 1 + max(height(B->left), height(B->right));

        return B;
    }

    Node* left_rotate(Node* A) {
        Node* B = A->right;
        Node* T2 = B->left;

        B->left = A;
        A->right = T2;

        A->height = 1 + max(height(A->left), height(A->right));
        B->height = 1 + max(height(B->left), height(B->right));

        return B;
    }

    Node* insert_node(Node* node, int key) {
        if (node == NULL) return new Node(key);

        if (key < node->data)
            node->left = insert_node(node->left, key);
        else if (key > node->data)
            node->right = insert_node(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balance_factor(node);

        // Left Heavy
        if (balance > 1) {
            if (key < node->left->data) { // Left-Left
                return right_rotate(node);
            } else { // Left-Right
                node->left = left_rotate(node->left);
                return right_rotate(node);
            }
        }

        // Right Heavy
        if (balance < -1) {
            if (key > node->right->data) { // Right-Right
                return left_rotate(node);
            } else { // Right-Left
                node->right = right_rotate(node->right);
                return left_rotate(node);
            }
        }

        return node;
    }

    Node* min_value_node(Node* node) {
        Node* current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    Node* delete_node(Node* root, int key) {
        if (root == NULL) return root;

        if (key < root->data)
            root->left = delete_node(root->left, key);
        else if (key > root->data)
            root->right = delete_node(root->right, key);
        else {
            if ((root->left == NULL) || (root->right == NULL)) {
                Node* temp = root->left ? root->left : root->right;

                if (temp == NULL) {
                    temp = root;
                    root = NULL;
                } else {
                    *root = *temp;
                }

                delete temp;
            } else {
                Node* temp = min_value_node(root->right);
                root->data = temp->data;
                root->right = delete_node(root->right, temp->data);
            }
        }

        if (root == NULL) return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = balance_factor(root);

        // Left Heavy
        if (balance > 1) {
            if (balance_factor(root->left) >= 0) { // Left-Left
                return right_rotate(root);
            } else { // Left-Right
                root->left = left_rotate(root->left);
                return right_rotate(root);
            }
        }

        // Right Heavy
        if (balance < -1) {
            if (balance_factor(root->right) <= 0) { // Right-Right
                return left_rotate(root);
            } else { // Right-Left
                root->right = right_rotate(root->right);
                return left_rotate(root);
            }
        }

        return root;
    }

    void in_order(Node* node) {
        if (node == NULL) return;
        in_order(node->left);
        cout << node->data << " ";
        in_order(node->right);
    }

    bool search_node(Node* node, int key) {
        if (node == NULL) return false;
        if (node->data == key) return true;
        if (key < node->data) return search_node(node->left, key);
        return search_node(node->right, key);
    }

public:
    AVLTree() : root(NULL) {}

    void insert(int key) { root = insert_node(root, key); }
    void remove(int key) { root = delete_node(root, key); }
    void in_order() { in_order(root); }
    bool search(int key) { return search_node(root, key); }
};

int main() {
    AVLTree avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    
    cout << "Inorder traversal of the AVL tree: ";
    avl.in_order();
    cout << '\n';
    
    avl.remove(30);
    cout << "Inorder traversal after removing 30: ";
    avl.in_order();
    cout << '\n';
     
    cout << "Is 25 in the tree? " << (avl.search(25) ? "Yes" : "No") << '\n';
    cout << "Is 30 in the tree? " << (avl.search(30) ? "Yes" : "No") << '\n';
    return 0;
}