#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

// Data structure to store a max-heap node
template<class T>
class PriorityQueue
{
    vector<T> A;
    int PARENT(int i) {
        return (i - 1) / 2;
    }
    int LEFT(int i) {
        return (2 * i + 1);
    }
    int RIGHT(int i) {
        return (2 * i + 2);
    }
    void heapify_down(int i)
    {
        int left = LEFT(i);
        int right = RIGHT(i);

        int largest = i;

        if (left < size() && A[left] > A[i]) {
            largest = left;
        }

        if (right < size() && A[right] > A[largest]) {
            largest = right;
        }

        if (largest != i)
        {
            swap(A[i], A[largest]);
            heapify_down(largest);
        }
    }

    void heapify_up(int i)
    {
        if (i && A[PARENT(i)] < A[i])
        {
            swap(A[i], A[PARENT(i)]);

            heapify_up(PARENT(i));
        }
    }

public:

    PriorityQueue() {}//constructor
    int size() {
        return A.size();
    }
    bool empty() {
        return size() == 0;
    }
    void push(T key)
    {
        A.push_back(key);

        int index = size() - 1;
        heapify_up(index);
    }

    void pop()
    {
        A[0] = A.back();
        A.pop_back();

        heapify_down(0);
    }

    int top()
    {
        return A[0];
    }
};

int main()
{
    PriorityQueue<int> p;
    p.push(1);
    p.push(11);
    p.push(4);
    p.push(10);
    p.push(9);
    p.push(19);
    p.push(2);
    cout << p.top();
}