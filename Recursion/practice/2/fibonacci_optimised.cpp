#include <iostream>
#include <unordered_map>


long int fibonacci(int n) {
    static std::unordered_map<int, int> fibonacci_numbers;

    // Let's check if we have already done this computation
    auto it = fibonacci_numbers.find(n);
    if (it != fibonacci_numbers.end())
        return it->second;
    
    // If the number has not been cached:
    long int result;
    if (n == 0 || n == 1)
        result = n;
    else
        result = fibonacci(n - 1) + fibonacci(n - 2);
    
    fibonacci_numbers[n] = result;
    return result;
}


int main() {
    std::cout << fibonacci(86) << std::endl;
}