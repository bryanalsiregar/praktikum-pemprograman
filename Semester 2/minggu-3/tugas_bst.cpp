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

void printPreOrder(Node *node) {
    if (node == NULL) return;
    cout << node->value << " ";
    
    printPreOrder(node->left);
    printPreOrder(node->right);
}

class QueueArray {
    private:
        Node* *array;
        int front;
        int back;
        int count;
        int max_size;
    public:
        QueueArray (int size) {
            max_size = size;
            array = new Node*[max_size];
            front = count = 0;
            back = -1;
        }

        ~QueueArray() {
            delete[] array;
        }

        bool is_full() {return count == max_size;}
        bool is_empty() {return count == 0;}

        void enqueue(Node* value) {
            if (is_full()) {
                cout << "You cannot enqueue because queue is full!" << endl;
                return;
            }

            back++;
            back %= max_size;

            array[back] = value;
            count++;
        }

        void dequeue() {
            if (is_empty()) {
                cout << "You cannot remove value from queue because queue is empty!" << endl;
                return;
            }

            front = (front + 1) % max_size;
            count--;
        }

        Node* peek() {
            if (is_empty()) {
                cout << "No value in queue!" << endl;
                return NULL;
            }

            return array[front];
        }
};

void printLevelOrder(Node *node) {
    QueueArray queue = QueueArray(100);
    queue.enqueue(node);
    
    while (!queue.is_empty()) {
        Node* temp = queue.peek();
        
        if (temp->left != NULL) queue.enqueue(temp->left);
        if (temp->right != NULL) queue.enqueue(temp->right);
        
        cout << temp->value << " ";
        queue.dequeue();
    }
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
    cout << "PreOrder Transversal: ";
    printPreOrder(root);
    cout << endl;
    /*
                 100
                90 101
             77 98  556
            26
          -1 
    */
    cout << "Level Order Transversal: ";
    printLevelOrder(root);
    cout << endl;
    return 0;
}