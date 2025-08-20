#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
	priority_queue<int, vector<int>> my_heap;

	my_heap.push(5);
	my_heap.push(11);
	my_heap.push(123);
	my_heap.push(11);
	my_heap.push(31);
	my_heap.push(5);
	my_heap.push(1);
	my_heap.push(12);

	while(!my_heap.empty()) {
		cout << my_heap.top() << ", ";
		my_heap.pop();
	}
	cout << endl;
}