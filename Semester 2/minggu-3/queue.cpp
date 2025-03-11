#include<iostream>

using namespace std;

class QueueArray {
    private:
        int *array;
        int front;
        int back;
        int count;
        int max_size;
    public:
        QueueArray (int size) {
            max_size = size;
            array = new int[max_size];
            front = count = 0;
            back = -1;
        }

        ~QueueArray() {
            delete[] array;
        }

        bool is_full() {return count == max_size;}
        bool is_empty() {return count == 0;}

        void enqueue(int value) {
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

        int peek() {
            if (is_empty()) {
                cout << "No value in queue!" << endl;
                return -1;
            }

            return array[front];
        }
};

int main() {
    QueueArray queue = QueueArray(10);
    queue.enqueue(29);
    queue.enqueue(435);
    queue.enqueue(546);
    queue.enqueue(54);
    queue.enqueue(875);
    cout << "Front of the queue " << queue.peek() << endl;
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    cout << "Front of the queue " << queue.peek() << endl;
    return 0;
}