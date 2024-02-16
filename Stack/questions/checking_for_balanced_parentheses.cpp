#include <iostream>
#include <string.h>
#include <string>
#include <stack>

// bool checkForBalanceParentheses(char phrase[])
// {
//     size_t string_length = strlen(phrase);
//     std::stack<char> stk;

//     for (size_t i = 0; i < string_length; i++)
//     {
//         char parentheses = phrase[i];

//         // If opening bracket
//         if (parentheses == '{' || parentheses == '[' || parentheses == '(')
//             stk.push(parentheses);
        
//         // If closing bracket
//         else if (parentheses == '}' || parentheses == ']' || parentheses == ')')
//         {
//             if (stk.empty())
//                 return false;
//             else if (parentheses - stk.top() <= 2) // Difference between the ASCII of the parenthesis is at most 2
//                 stk.pop();
//             else
//                 return false;
//         }
//     }

//     return (stk.empty()) ? true : false;
// }

// Another way of doing this function:

// Function to check if brackets are balanced
bool checkForBalanceParentheses(std::string expr)
{
    // Declare a stack to hold the previous brackets.
    std::stack<char> temp;

    for (int i = 0; i < expr.length(); i++) {
        if (temp.empty())
            // If the stack is empty just push the current bracket
            temp.push(expr[i]);
        
        else if ((temp.top() == '(' && expr[i] == ')')
                 || (temp.top() == '{' && expr[i] == '}')
                 || (temp.top() == '[' && expr[i] == ']'))
            // If we found any complete pair of bracket then pop
            temp.pop();
        
        else
            temp.push(expr[i]);
    }

    if (temp.empty())
        // If stack is empty return true
        return true;

    return false;
}


int main()
{
    char sample_0[] = "[({})]";
    char sample_1[] = ")";

    std::cout << checkForBalanceParentheses(sample_0) << std::endl;
    std::cout << checkForBalanceParentheses(sample_1);

    return 0;
}