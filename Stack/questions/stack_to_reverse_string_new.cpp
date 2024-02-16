#include <iostream>
#include <string.h>
#include <stack>

void reverse(char string_[]) {
    int size = strlen(string_);
    std::stack<char> S;

    for (size_t i = 0; i < size; i++)
        S.push(string_[i]);

    for (size_t i = 0; i < size; i++) {
        string_[i] = S.top();
        S.pop();
    }
}

int main()
{
    char word[51];

    std::cout << "Enter a string: ";
    std::cin.getline(word, 51);

    reverse(word);
    std::cout<<word;
}