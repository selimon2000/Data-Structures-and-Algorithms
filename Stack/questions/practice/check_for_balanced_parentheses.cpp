#include <iostream>
#include <string.h>
#include <stack>

bool checkForBalanceParentheses(char s[]) {
    size_t size = strlen(s);
    std::stack<char> parenthesis_stack;

    for (size_t i = 0; i < size; i++) {

        // If Opening Bracket
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
            parenthesis_stack.push(s[i]);
        
        // If Closing Bracket
        else if (s[i] == ']' || s[i] == '}' || s[i] == ')') {

            if (parenthesis_stack.empty())
                return false;
            
            // Checking if opening and closing brackets match
            char top = parenthesis_stack.top();
            if (top == '(' && s[i] == ')' ||
                top == '[' && s[i] == ']' ||
                top == '{' && s[i] == '}')
                    parenthesis_stack.pop();
            
            else
                parenthesis_stack.push(s[i]);
        }
    }

    if (parenthesis_stack.empty())
        return true;

    return false;
}


int main() {
    char sample_0[] = "[({})]";
    char sample_1[] = ")";

    std::cout << checkForBalanceParentheses(sample_0) << std::endl;
    std::cout << checkForBalanceParentheses(sample_1);
}