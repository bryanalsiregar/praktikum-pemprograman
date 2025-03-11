#include<iostream>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node (int data) {
        value = data;
        left = right = NULL;
    }
};

Node* insert_node(Node* node, int value) {
    if (node == NULL) return new Node(value);
    
    if (value < node->value) {
        node->left = insert_node(node->left, value);
    } else {
        node->right = insert_node(node->right, value);
    }

    return node;
}

Node* search_node(Node* node, int value) {
    if (node == NULL) return new Node(-999);
    if (node->value == value) return node;
    
    if (value > node->value) return search_node(node->right, value);

    return search_node(node->left, value);
}

Node* min_node(Node* node) {
    Node* current = node;

    while (current && current->left != NULL) current = current->left;

    return current;
}

Node* delete_node(Node* node, int value) {
    if (node == NULL) return node;

    if (value > node->value) return node->right = delete_node(node->right, value);
    if (value < node->value) return node->left = delete_node(node->left, value);

    if (node->left == NULL) {
        Node* temp = node;
        delete node;
        return temp;
    }

    if (node->right == NULL) {
        Node* temp = node;
        delete node;
        return temp;
    }

    Node* temp = min_node(node->right);
    node->value = temp->value;
    node->right = delete_node(node->right, temp->value);

    return node;
}

int main() {
    Node* root = new Node(100);
    
    insert_node(root, 90);
    insert_node(root, 101);
    insert_node(root, 77);
    insert_node(root, 98);
    insert_node(root, 26);
    insert_node(root, -1);
    insert_node(root, 556);
    cout << "Search 900: " << search_node(root, 900)->value << endl; 
    cout << "Search 77: " << search_node(root, 77)->value << endl; 
    cout << "Search 98: " << search_node(root, 98)->value << endl;
    cout << "Find min node: " << min_node(root)->value << endl;
    delete_node(root, 77);
    delete_node(root, 98);
    cout << "Search 26: " << search_node(root, 26)->value << endl; 
    cout << "Search -1: " << search_node(root, -1)->value << endl; 
    return 0;
}