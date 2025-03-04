#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
    private:
        Node *head;
    public:
        // Konstruktor akan menginisialisasi head = NULL ketika class digunakan
        LinkedList() : head(NULL) {}
        void insertFirst(int value) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = head;
            head = newNode;
        }

        void insertLast(int value) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            if (!head) {
                head = newNode;
                return;
            }
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            
            temp->next = newNode;
        }

        void insertAt(int value, int pos) {
            if (pos < 1) {
                cout << "Position should be >= 1.\n";
                return;
            }

            if (pos == 1) {
                insertFirst(value);
                return;
            }

            Node* newNode = new Node();
            newNode->data = value;
            Node* temp = head;
        
            for (int i = 1; i < pos - 1 && temp; i++)
                temp = temp->next;
        
            if (!temp) {
                cout << "Position out of range.\n";
                delete newNode;
                return;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        void deleteFirst() {
            if (!head) {
                cout << "List is empty.\n";
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void deleteLast() {
            if (!head) {
                cout << "List is empty.\n";
                return;
            }
            if (!head->next) {
                delete head;
                head = NULL;
                return;
            }
            Node* temp = head;
            while (temp->next->next)
                temp = temp->next;

            delete temp->next;
            temp->next = NULL;
        }

        void deleteAt(int pos) {
            if (pos < 1) {
                cout << "Position should be >= 1.\n";
                return;
            }

            if (pos == 1) {
                deleteFirst();
                return;
            }

            Node* temp = head;
            for (int i = 1; i < pos - 1 && temp; i++)
                temp = temp->next;
            
            if (!temp || !temp->next) {
                cout << "Position out of range.\n";
                return;
            }
            
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }

        void display() {
            if (!head) {
                cout << "List is empty.\n";
                return;
            }
            Node* temp = head;
            while (temp) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }

        void searchData(int data);
};

void LinkedList::searchData(int data) {
    Node* temp = head;
    while (temp->next) {
        if (temp->data == data || temp->next->data == data) {
            cout << data << " is present in the linked list" << endl;
            return;
        }
        
        temp = temp->next;
    }

    cout << "No node in the linked list has the value " << data << endl;
}

int main() {
    // Inisialisasi Linked List
    LinkedList list1;
    // Memasukkan elemen dari belakang
    list1.insertLast(10);
    list1.insertLast(20);
    // Memasukkan elemen dari depan
    list1.insertFirst(5);
    // Memasukkan elemen pada posisi tertentu
    list1.insertAt(15, 3);
    cout << "Linked list after insertions: ";
    list1.display();
    // Hapus elemen dari depan
    list1.deleteFirst();
    cout << "Linked list after deletion from beginning: ";
    list1.display();
    // Hapus elemen dari belakang
    list1.deleteLast();
    cout << "Linked list after deletion from end: ";
    list1.display();
    // Hapus elemen dari posisi tertentu
    list1.deleteAt(2);
    cout << "Linked list after deletion from position 2: ";
    list1.display();
    cout << "---------------------------------------------------------" << endl;
    // Penambahan elemen dalam LinkedList
    list1.insertFirst(24);
    list1.insertFirst(74);
    list1.insertFirst(31);
    list1.insertFirst(290);
    list1.insertFirst(34);
    list1.insertFirst(65);
    cout << "Current Linked list element: ";
    list1.display();
    cout << "Check 31 in LinkedList: " ;
    list1.searchData(31);
    cout << "Check 0 in LinkedList: " ;
    list1.searchData(0);
    cout << "Check 30 in LinkedList: " ;
    list1.searchData(30);
    cout << "Check 65 in LinkedList: " ;
    list1.searchData(65);
    cout << "Check 10 in LinkedList: " ;
    list1.searchData(10);
    return 0;
}