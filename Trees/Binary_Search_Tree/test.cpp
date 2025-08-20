#include <bits/stdc++.h>

using namespace std;


void printTwoOdd(int arr[], int size) {
    
	int xor2 = 0;
	
	for(int i = 0; i < size; i++) xor2 = xor2 ^ arr[i]; 
	
	int set_bit_no = xor2 & -xor2; 
	
    int x = 0,
        y = 0;
	for(int i = 0; i < size; i++) {
		if(arr[i] & set_bit_no) x = x ^ arr[i]; 
		else                    y = y ^ arr[i]; 
	} 

	cout << "The two ODD elements are " << x << " & " << y; 
}


int main() { 
	int arr[] = {4, 2, 4, 5, 2, 3, 3, 1}; 
	int arr_size = sizeof(arr)/sizeof(arr[0]); 
	
    printTwoOdd(arr, arr_size); 
} 