#include <iostream>
using namespace std;

template<class T>
class queue {
private:
	static const int capacity = 10;
	T arr[capacity];
	int size;
	int first;
public:
	queue():first(7),size(0) {}

	int size() {
		return size;
	}

	void enqueue(T const& e) {
		if (size == 0) {
			arr[first] = e;
			size++;
		}
		else if (size == capacity) {
			cout << "full array" << endl;
		}
		else {
			if (size + first >= capacity) {
				arr[first + size - capacity] = e;
			}
			else {
				arr[first + size] = e;
			}
			size++;
		}
	}

	void dequeue() {
		if (first + 1 >= capacity) {
			first = 0;
			size--;
		}
		else {
			first++;
			size--;
		}
	}

	void print() {
		for (int i = 0; i < size; i++) {
			if (first + i >= capacity) {
				cout << arr[first + i - capacity] << endl;
			}
			else {
				cout << arr[first + i] << endl;
			}
		}
	}

	bool front(T& d) {
		if (size != 0) {
			d = arr[first];
			return true;
		}
		else {
			cout << "invalid size" << endl;
			return false;
		}
	}

	bool isEmpty() {
		if (size == 0) {
			return true;
		}
		return false;
	}
};

int main() {
	queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.dequeue();
	q.dequeue();
	q.enqueue(4);
	q.enqueue(5);
	q.print();
}