#include<iostream>
#include<string>

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
                return -1;
            }

            return array[top];
        }
};

int main() {
    for (int _ = 0; _ < 4; _++) {
        string input;
        
        cout << "Input: ";
        cin >> input;
        
        int length = input.length();
        
        StackArray stack = StackArray(length);
        for (int i = 0; i < length; i++) {
            char inp = input[i];
            if (inp == '{' || inp == '(' || inp == '[') {
                stack.push(input[i]);
                continue;
            }
            if (inp == '}' && stack.peek() == '{') {
                stack.pop();
                continue;
            }
            if (inp == ']' && stack.peek() == '[') {
                stack.pop();
                continue;
            }
            if (inp == ')' && stack.peek() == '(') {
                stack.pop();
                continue;
            }
            if (inp == '}' || inp == ')' || inp == ']') {
                stack.push(input[i]);
                continue;
            }
        }

        if (stack.is_empty()) cout << "Output: true" << endl;
        else cout << "Output: false" << endl;
    }
    return 0;
}