#include <iostream>
using namespace std;

class AVLTree {
    private:
        struct Node {
            int data;  // Nilai dari node
            Node *left;  // Pointer ke node kiri
            Node *right;  // Pointer ke node kanan
            int height;  // Tinggi dari node Konstruktor
            Node(int key) : data(key), left(NULL), right(NULL), height(1) {}
        };

    Node *root;
    
    private:
        // Fungsi untuk mendapatkan height dari node
        int height(Node *node) {
            if (node == NULL) return 0;
            return node->height;
        }

        // Fungsi untuk mendapatkan balance factor dari node
        int balanceFactor(Node *node) {
            if (node == NULL) return 0;
            return height(node->left) - height(node->right);
        }

        Node *rightRotate(Node *A) {
            Node *B = A->left;  // B adalah child kiri dari A
            Node *T2 = B->right;  // T2 adalah subtree kanan dari B
            
            B->right = A;  // Buat node A sebagai child kanan dari node B
            A->left = T2;  // Buat subtree kanan dari B sebagai child kiri node A
            
            //Update height
            A->height = 1 + max(height(A->left), height(A->right));
            B->height = 1 + max(height(B->left), height(B->right));
            
            return B;
        }

        Node *leftRotate(Node *A) {
            Node *B = A->right;  // B adalah child kanan dari A
            Node *T2 = B->left;  // T2 adalah subtree kiri dari B
            
            B->left = A;  // Buat node A sebagai child kiri dari node B
            A->right = T2;  // Buat subtree kiri dari B sebagai child kanan node A
            
            // Update height
            A->height = 1 + max(height(A->left), height(A->right));
            B->height = 1 + max(height(B->left), height(B->right));
            
            return B;
        }

        Node *insert(Node *node, int key) {
            // Lakukan insertion seperti BST
            if (node == NULL) return new Node(key);
            
            // Telusuri tree
            // Jika key < node data, telusuri subtree kiri
            // Jika key > node data, telusuri subtree kanan
            // Jika key  node data, kembalikan node, kita asumsikan tidak boleh ada 2 node dengan key yang sama
            if (key < node->data)
                node->left = insert(node->left, key);
            else if (key > node->data)
                node->right = insert(node->right, key);
            else
                return node;

            // Update height dari node saat ini
            node->height = 1 + max(height(node->left), height(node->right));
            
            // Hitung balance factor dari node saat ini
            int balance = balanceFactor(node);
            
            // Handle kasus unbalanced
            // Kasus 1: Left Left (Right Rotation / RR)
            if (balance > 1 && key < node->left->data)
                return rightRotate(node);
            
            // Kasus 2: Left Right (Left Rotation  Right Rotation / LR)
            if (balance > 1 && key > node->left->data) {
                node->left = leftRotate(node->left);  // LR pada child kiri
                return rightRotate(node);  // RR pada node saat ini
            }

            // Kasus 3: Right Right (Left Rotation / LL)
            if (balance < -1 && key > node->right->data)
                return leftRotate(node);
            
            // Kasus 4: Right Left (Right Rotation  Left Rotation / RL)
            if (balance < -1 && key < node->right->data){
                node->right = rightRotate(node->right);  // RL pada child kanan
                return leftRotate(node);  // LL pada node saat ini
            }

            return node;
        }

        // Fungsi untuk mendapatkan inorder successor dari node
        Node *minValueNode(Node *node) {
            Node *current = node;
            
            // Lakukan pencarian ke kiri sampai ditemukan node terkecil
            while (current->left != NULL) current = current->left;

            return current;
        }

        Node *deleteNode(Node *root, int key) {
        // Lakukan deletion seperti BST
        if (root == NULL) return root;
        
        // Telusuri tree
        // - Jika value yang akan dihapus lebih kecil dari data di root, maka value terletak di subtree kiri dari node root.
        // - Jika value yang akan dihapus lebih besar dari data di root, maka value terletak di subtree kanan dari node root.
        // - Jika value yang akan dihapus sama dengan data di root, maka ini adalah node yang akan dihapus.
        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        } else {
            // Kasus 1 & 2: Node dengan 1 child atau tanpa child
            if ((root->left == NULL) || (root->right == NULL)) {
                Node *temp = root->left ? root->left : root->right;
            
                if (temp == NULL) {
                    temp = root;
                    root = NULL;
                } else {
                    *root = *temp;
                }
            
                delete temp;
            
            // Kasus 3: Node dengan 2 child
            } else {
                Node *temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == NULL) return root;

        // Update height dari node saat ini
        root->height = 1 + max(height(root->left), height(root->right));
        
        // Hitung balance factor dari node saat ini
        int balance = balanceFactor(root);

        // Handle kasus unbalanced
        // Kasus 1: Left Left (Right Rotation / RR)
        if (balance > 1 && balanceFactor(root->left) >=  0)
            return rightRotate(root);
        
        // Kasus 2: Left Right (Left Rotation  Right Rotation / LR)
        if (balance > 1 && balanceFactor(root->left) < 0) {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }

        // Kasus 3: Right Right (Left Rotation / LL)
        if (balance < -1 && balanceFactor(root->right) <= 0)
            return leftRotate(root);
        
        // Kasus 4: Right Left (Right Rotation  Left Rotation / RL)
        if (balance < -1 && balanceFactor(root->right) > 0){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
       }
       
       void inOrder(Node *node) {
            if (node == NULL) return;
            
            inOrder(node->left);
            cout << node->data <<  " ";
            inOrder(node->right);
       }
       
       bool searchNode(Node *node, int key) {
        if (node == NULL) return false;
        
        if (node->data == key) return true;
        if (key < node->data) return searchNode(node->left, key);
        
        return searchNode(node->right, key);
       }
    
    public:
       AVLTree() : root(NULL) {}
       
       void insert(int key) { root = insert(root, key); }
       void remove(int key) { root = deleteNode(root, key); }
       void inOrder() { inOrder(root); }
       bool search(int key) { return searchNode(root, key); }
};

int main() {
    AVLTree avl;
    
    // Insert node ke tree
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);
    
    // Inorder traversal dari tree
    cout << "Inorder traversal of the constructed AVL tree is: ";
    avl.inOrder();
    cout << '\n';
    
    // Hapus node dari tree
    avl.remove(30);
    cout << "Inorder traversal of the AVL tree after deletion of 30 is: ";
    
    avl.inOrder();
    cout <<  '\n';
    
    // Cari node di tree
    cout << "Is 40 in the tree? " <<  (avl.search(40) ? "Yes" : "No") << '\n';
    cout << "Is 30 in the tree? " <<  (avl.search(30) ? "Yes" : "No")  << '\n';
    
    return 0;
}
        
           