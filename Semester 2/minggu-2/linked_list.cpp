#include<iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};

class LinkedList {
    private:
        Node* head;
    public:
        LinkedList() {
            head = NULL;
        }

        void insert_first(int value) {
            Node* new_node = new Node();
            new_node->value = value;
            new_node->next = head;
            head = new_node;
        }

        void insert_at(int value, int pos) {
            Node* new_node = new Node();
            new_node->value = value;

            Node* temp = head;
            for (int i = 1; i < pos-1; i++) temp = temp->next;

            new_node->next = temp->next;
            temp->next = new_node;
        }

        void insert_last(int value) {
            Node* new_node = new Node();
            
            new_node->value = value;
            new_node->next = NULL;

            Node* temp = head;
            while (temp->next) temp = temp->next;

            temp->next = new_node;
        }

        void delete_first() {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void delete_at(int pos) {
            Node* temp = head;
            for (int i = 1; i < pos-1; i++) temp = temp->next;

            Node* node_delete = temp->next;
            delete node_delete;
            temp->next = temp->next->next;
        }

        void delete_last() {
            Node* temp = head;
            while (temp->next->next) temp = temp->next;
            
            delete temp->next;
            temp->next = NULL;
        }

        void display() {
            if (!head) {
                cout << "Linked List is empty!" << endl;
                return;
            }

            Node* temp = head;

            while (temp) {
                cout << temp->value << " -> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
};

int main() {
    LinkedList new_ll;
    
    new_ll.insert_first(10);
    new_ll.insert_first(20);
    new_ll.insert_first(30);
    new_ll.insert_first(40);

    new_ll.display();

    new_ll.delete_first();

    new_ll.display();

    new_ll.insert_last(100);
    new_ll.insert_last(90);
    new_ll.insert_last(80);

    new_ll.display();
    
    new_ll.insert_first(0);
    
    new_ll.display();
    
    new_ll.delete_last();
    new_ll.delete_last();

    new_ll.display();

    new_ll.insert_at(1000, 4);
    new_ll.insert_at(2000, 3);

    new_ll.display();

    new_ll.delete_at(3);
    new_ll.delete_at(3);

    new_ll.display();
}