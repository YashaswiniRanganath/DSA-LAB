/*(2)
Design an algorithm and implement a program to validate the correctness of a given string containing brackets - parentheses '()', square brackets '[]', and curly braces '{}'. The goal is to determine whether the arrangement of brackets in the input string is valid or not. The validation should follow these rules: 1. Every opening bracket must have a corresponding closing bracket. 2. Brackets must be closed in the correct order, i.e., a closing bracket should match the most recently opened unmatched opening bracket. 3. The input string may contain other characters besides brackets, but they should be ignored during validation. 4. The input string is considered valid if and only if all brackets are properly nested and closed. Your program should return true if the input string is valid, and false otherwise. You should implement this validation using a stack data structure.

Sample Input 0

({[()]})
Sample Output 0

true
Sample Input 1

{[()]}(
Sample Output 1

false
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

struct Stack* create_stack(unsigned capacity);
int is_operator(char ch);
int precedence(char ch);
void push(struct Stack* stack, char item);
char pop(struct Stack* stack);
void infix_to_postfix(char* infix);

struct Stack 
{
    int top;
    unsigned capacity;
    char* array;
};
int main() 
{
    char infix[1000];
    scanf("%s", infix);
    infix_to_postfix(infix);
    return 0;
}
struct Stack* create_stack(unsigned capacity) 
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}
int is_operator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int precedence(char ch) 
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}
void push(struct Stack* stack, char item) 
{
    stack->array[++stack->top] = item;
}
char pop(struct Stack* stack) 
{
    if (stack->top == -1)
        return '\0';
    return stack->array[stack->top--];
}
void infix_to_postfix(char* infix) 
{
    struct Stack* stack = create_stack(strlen(infix));
    int i;
    for (i = 0; infix[i]; i++) 
    {
        char c = infix[i];
        if(isalnum(c)) 
        {
            printf("%c", c);
        } 
        else if (c == '(') 
        {
            push(stack, c);
        } 
        else if (c == ')') 
        {
            while (stack->top != -1 && stack->array[stack->top] != '(') 
            {
                printf("%c", pop(stack));
            }
            if (stack->top != -1 && stack->array[stack->top] == '(')
                pop(stack);
        } 
        else 
        {
            while (stack->top != -1 && precedence(c) <= precedence(stack->array[stack->top])) 
            {
                printf("%c", pop(stack));
            }
            push(stack, c);
        }
    }
    while (stack->top != -1) 
    {
        printf("%c", pop(stack));
    }
    free(stack->array);
    free(stack);
}