#include <iostream>
#include <vector>

using namespace std;


class MaxHeap {
private:
    vector<int> arr{-1};
    unsigned int size{};

    int p(int i) {return i >> 1;}
    int l(int i) {return i << 1;}
    int r(int i) {return (i << 1) + 1;}
    

public:
    MaxHeap() {
        arr.reserve(10);
    }
    int top();
    bool empty();

    void push(int val);
    void pop();

    void shiftUp(uint16_t pos);
    void shiftDown(uint16_t pos);
};


int MaxHeap::top() {
    if(!empty()) return arr[1];
    return -1;
}

bool MaxHeap::empty() {
    return size == 0;
}

void MaxHeap::push(int val) {
    if(size +1 == arr.size()) {arr.push_back(val); size++;}
    else arr[++size] = val;

    shiftUp(size);
}

void MaxHeap::pop() {
    if(empty()) {cout << "[WARNING]\tCannot Pop as Heap is empty" << endl; return;}
    
    arr.at(1) = arr.at(size--);

    shiftDown(1);
}

void MaxHeap::shiftUp(uint16_t pos) {
    while((pos > 1) && (arr.at(pos) > arr.at(p(pos)))) {
        swap(arr.at(pos), arr.at(p(pos)));
        pos = p(pos);
    }
}

void MaxHeap::shiftDown(uint16_t pos) {
    while (1) {
        unsigned int largest = pos;
        if ((l(pos) <= size) && (arr.at(l(pos)) > arr.at(largest)))
            largest = l(pos);
        if ((r(pos) <= size) && (arr.at(r(pos)) > arr.at(largest)))
            largest = r(pos);

        if(largest == pos) return;  

        swap(arr.at(pos), arr.at(largest));
        pos = largest;     
    }
}


int main() {
    MaxHeap priority_queue;

    // Test 1: Check if the priority queue is empty initially
    cout << "Is priority queue empty (initially): " << (priority_queue.empty() ? "YES" : "NO") << endl;

    // Test 2: Insert into an empty heap
    cout << "\nTest 2: Insert first element (10)" << endl;
    priority_queue.push(10);
    cout << "Max element after insertion: " << priority_queue.top() << endl;

    // Test 3: Insert multiple elements
    cout << "\nTest 3: Insert multiple elements (30, 20, 50, 40, 60)" << endl;
    priority_queue.push(30);
    priority_queue.push(20);
    priority_queue.push(50);
    priority_queue.push(40);
    priority_queue.push(60);

    cout << "Max element after multiple insertions: " << priority_queue.top() << endl;

    // Test 4: Check the max-heap property by popping elements
    cout << "\nTest 4: Popping elements:" << endl;
    while (!priority_queue.empty()) {
        cout << "Max element: " << priority_queue.top() << " popped." << endl;
        priority_queue.pop();
    }

    // Test 5: Pop from an empty heap
    cout << "\nTest 5: Attempting to pop from an empty heap." << endl;
    priority_queue.pop(); // Should handle underflow

    // Test 6: Insert duplicate values
    cout << "\nTest 6: Inserting duplicate values (25, 25, 25)" << endl;
    priority_queue.push(25);
    priority_queue.push(25);
    priority_queue.push(25);
    cout << "Max element after inserting duplicates: " << priority_queue.top() << endl;

    // Test 7: Pop until empty
    cout << "\nTest 7: Pop until empty:" << endl;
    while (!priority_queue.empty()) {
        cout << "Max element: " << priority_queue.top() << " popped." << endl;
        priority_queue.pop();
    }

    // Test 8: Check top method on empty heap
    cout << "\nTest 8: Top method on empty heap: " << priority_queue.top() << endl; // Should return -1
}