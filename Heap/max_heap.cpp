#include <iostream>
#include <vector>

using namespace std;


class MaxHeap {
    unsigned int size{};
    vector<int> vect = {-1};

    // Given an index i return parent (pretty much halving it)
    int p(int i) {return i >> 1;}
    int l(int i) {return i << 1;}
    int r(int i) {return (i << 1) + 1;}


    public:
        bool isEmpty() const { return (size == 0) ? true : false; }
        int getMax() const { return (isEmpty()) ? (-1) : (vect.at(1)); }

        void insertItem(int val);
        void shiftUp(int i);
        void shiftDown(int i);
        // Returns max and performs deletion operation, replacing max element with lastly added element,
        // and shifting it until it arrives to correct pos
        int extractMax();

        void print_vect();
};

void MaxHeap::insertItem(int val) {
    if (size + 1 == vect.size())    {vect.push_back(val); size++;}
    else                            vect.at(++size) = val;

    shiftUp(size);
}

void MaxHeap::shiftUp(int i) {
// Recursive Method ////////////////////////////////
/*     if (i > size)                       return;

    if (i == 1)                         return;
    if (vect.at(i) <= vect.at(p(i)))    return;

    swap(vect.at(i), vect.at(p(i)));
    shiftUp(p(i)); */
////////////////////////////////////////////////////

// While Loop Method ///////////////////////////////
if (i > size) return;

int parent = p(i);
while (i > 1 && vect.at(i) > vect.at(parent)) {
    swap(vect.at(i), vect.at(parent));
    i = parent;
    parent = p(i);
}
////////////////////////////////////////////////////
}

void MaxHeap::shiftDown(int i) {
// Recursive Method ///////////////////////////////
    if (i > size) return;

    int to_swap_loc = i; // to swap location
    if (l(i) <= size && vect.at(l(i)) > vect.at(to_swap_loc)) to_swap_loc = l(i);
    if (r(i) <= size && vect.at(r(i)) > vect.at(to_swap_loc)) to_swap_loc = r(i);
    if (to_swap_loc == i) return;

    swap(vect.at(i), vect.at(to_swap_loc));
    shiftDown(to_swap_loc);
///////////////////////////////////////////////////

// While Loop ////////////////////////////////////
  /*   while (i < size) {
        int next_swap = i;

        if (l(i) < size && vect.at(l(i)) > vect.at(next_swap)) next_swap = l(i);
        if (r(i) < size && vect.at(r(i)) > vect.at(next_swap)) next_swap = r(i);
        if (next_swap == i) return;
        swap(vect.at(i), vect.at(next_swap));
        i = next_swap;
    } */
//////////////////////////////////////////////////
}


int MaxHeap::extractMax() {
    if (isEmpty()) {cout << "[WARNING]\tArray is Empty so returning \"-1\"" << endl; return -1;}
    
    int max = getMax();

    vect.at(1) = vect.at(size--);

    shiftDown(1);

    return max;
}

void MaxHeap::print_vect() {
    for (int i = 1; i <= size; i++) // No point printing '-1'
        cout << vect.at(i) << ", ";
    cout << endl;
}


int main() {
    MaxHeap priority_queue;

    cout << "Is priority queue empty: " << (priority_queue.isEmpty() ? "YES" : "NO") << endl;

    // Inserting elements into the priority queue
    priority_queue.insertItem(12);
    priority_queue.insertItem(95);
    priority_queue.insertItem(12);
    priority_queue.insertItem(3);
    priority_queue.insertItem(313);
    priority_queue.insertItem(45);
    priority_queue.insertItem(37);
    priority_queue.insertItem(87);

    cout << "Is priority queue empty: " << (priority_queue.isEmpty() ? "YES" : "NO") << endl;
    
    // Print the heap vector
    cout << "Heap elements: ";
    priority_queue.print_vect();

    // Extract the maximum element
    cout << "Extracted max element: " << priority_queue.extractMax() << endl;

    // Print the heap vector after extraction
    cout << "Heap elements after extraction: ";
    priority_queue.print_vect();

    // Further extraction of elements
    cout << "Extracted max element: " << priority_queue.extractMax() << endl;
    cout << "Extracted max element: " << priority_queue.extractMax() << endl;
    cout << "Extracted max element: " << priority_queue.extractMax() << endl;
    cout << "Extracted max element: " << priority_queue.extractMax() << endl;
    cout << "Extracted max element: " << priority_queue.extractMax() << endl;
    cout << "Extracted max element: " << priority_queue.extractMax() << endl;
    cout << "Extracted max element: " << priority_queue.extractMax() << endl;

    // Print the heap vector after further extractions
    cout << "Heap elements after further extractions: ";
    priority_queue.print_vect();
}