#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 101


int top = -1;
char stack[MAX_ARRAY_SIZE];


void push(char input) {
    stack[++top] = input;
}

char pop() {
    return stack[top--];
}


int main() {
    char word[] = "Hello";
    
    for (size_t i = 0; word[i] != '\0'; i++)
        push(word[i]);

    for (size_t i = 0; top >= 0; i++)
        word[i]=pop();
    
    printf("%s", word);
}