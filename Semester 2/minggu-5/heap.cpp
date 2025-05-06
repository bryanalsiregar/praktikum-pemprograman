#include<iostream>

using namespace std;

class Heap {
	private:
		int size;
		int capacity;
		int *arr;

		void heapify(int i);
	
	public:
		Heap(int capacity);
		void insertKey(int key);
		int top();
		int pop();
		void deleteKey(int key);
		void printHeap();
		void increaseKey(int oldValue, int newValue);
		void decreaseKey(int oldValue, int newValue);
};

Heap::Heap(int capacity) {
	this->capacity = capacity;
	this->size = 0;
	arr = new int[capacity];
}

void Heap::heapify(int i) {
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	if (left < size && arr[left] < arr[largest])
		largest = left;
	
	if (right < size && arr[right] < arr[largest])
		largest = right;
	
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(largest);
	}
}

void Heap::insertKey(int key) {
	if (size == capacity) {
		cout << "Overflow\n";
		return;
	}

	size++;
	int i = size - 1;
	arr[i] = key;

	while (i != 0 && arr[(i-1)/2] > arr[i]) {
		swap(arr[i], arr[(i-1)/2]);
		i = (i-1)/2;
	}
}

int Heap::top() {
	if (size == 0) {
		cout << "Heap is empty\n";
		return -1;
	}
	return arr[0];
}

int Heap::pop() {
	if (size <= 0) {
		cout << "Heap is empty\n";
		return -1;
	}

	if (size == 1) {
		size--;
		return arr[0];
	}

	int root = arr[0];
	arr[0] = arr[size-1];
	size--;
	heapify(0);

	return root;
}

void Heap::deleteKey(int key) {
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "Key not found\n";
		return;
	}

	if (index == size-1) {
		size--;
		return;
	}

	arr[index] = arr[size-1];
	size--;

	heapify(index);
}

void Heap::printHeap() {
	cout << "Heap: ";
	for (int i = 0; i < size; i++) 
		cout << arr[i] << " ";
	cout << "\n";
}

void Heap::increaseKey(int oldValue, int newValue) {
	if (oldValue >= newValue) {
		cout << "newValue harus lebih besar dari oldValue!" << endl;
		return;
	}

	int index = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] == oldValue) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "Key not found.\n";
		return;
	}

	arr[index] = newValue;

	heapify(index);
}

void Heap::decreaseKey(int oldValue, int newValue) {
	if (oldValue <= newValue) {
		cout << "newValue harus lebih kecil dari oldValue!" << endl;
		return;
	}

	int index = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] == oldValue) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "Key not found.\n";
		return;
	}

	arr[index] = newValue;

	int i = index;
	
	while (i != 0 && arr[(i-1)/2] > arr[i]) {
		swap(arr[i], arr[(i-1)/2]);
		i = (i-1)/2;
	}
}

int main() {
	Heap heap(10);
	heap.insertKey(3);
	heap.insertKey(2);
	heap.insertKey(15);
	heap.insertKey(5);
	heap.insertKey(4);
	heap.insertKey(45);

	cout << "Heap after insertions:\n";
	heap.printHeap();
	cout << "Top element: " << heap.top() << "\n";

	cout << "Popped element: " << heap.pop() << "\n";
	cout << "Heap after pop: \n";
	heap.printHeap();
	cout << "Top element after pop: " << heap.top() << "\n";

	heap.deleteKey(15);
	cout << "Heap after deleting 15:\n";
	heap.printHeap();
	cout << "Top element after deletion: " << heap.top() << "\n";
	cout << "---------------------" << endl;
	heap.insertKey(9);
	heap.insertKey(18);
	heap.insertKey(27);
	heap.insertKey(78);
	cout << "Heap after insertions again:\n";
	heap.printHeap();
	cout << "Increase key 3 menjadi 15: \n";
	heap.increaseKey(3, 15);
	heap.printHeap();
	
	cout << "Decrease key 78 menjadi 0: \n";
	heap.decreaseKey(78, 0);
	heap.printHeap();
	

	return 0;
}
