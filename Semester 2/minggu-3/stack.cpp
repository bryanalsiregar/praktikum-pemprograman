#include<iostream>

using namespace std;

class StackArray {
    private:
        int *array;
        unsigned int max_size;
        int top;
    public:
        StackArray (int size) {
            max_size = size;
            array = new int[size];
            top = -1;
        }

        ~StackArray() {
            delete[] array;
        }

        bool is_full() {return ((int)max_size-1==top);}
        bool is_empty() {return top==-1;}

        void push(int value) {
            if (is_full()) {
                cout << "You cannot add value because the stack is full!" << endl;
                return;
            }
            array[++top] = value;
        }

        void pop() {
            if (is_empty()) {
                cout << "You cannot remove value because the stack is empty!" << endl;
                return;
            }
            top--;
        }

        int peek() {
            if (is_empty()) {
                cout << "You cannot peek because the stack is empty!" << endl;
                return -1;
            }

            return array[top];
        }
};

int main() {
    StackArray stack = StackArray(10);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    cout << "Peeking stack " << stack.peek() << endl;
    stack.push(100);
    stack.push(27);
    stack.push(30);
    stack.pop();
    cout << "Peeking stack " << stack.peek() << endl;
    return 0;
}