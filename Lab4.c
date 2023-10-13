// LAB4-> 07.09.2023 

/*(1)
Design and implement an algorithm to convert infix mathematical expressions to postfix notation using a stack data structure. The algorithm should be capable of handling expressions containing operators such as addition (+), subtraction (-), multiplication (*), division (/), and parentheses. The goal is to develop a program that can efficiently and accurately convert infix expressions to postfix notation while respecting operator precedence and parentheses.

Key Requirements:

Accept infix mathematical expressions as input from the user or a file.
Handle the following operators with correct precedence: + (addition), - (subtraction), * (multiplication), / (division).
Properly handle parentheses to ensure correct order of operations.
Output the corresponding postfix notation of the input expression.
Implement the algorithm using a stack data structure to track operators and operands.
Input Format

A string representing an infix mathematical expression containing digits, operators, and parentheses.

Constraints

The input expression will be a valid mathematical expression. The input expression length is between 3 and 10^4 characters. The input expression does not contain invalid characters or syntax errors.

Output Format

A string representing the corresponding postfix notation of the input expression.

Sample Input 0

(3+4)*2/(5-2)
Sample Output 0

34+2*52-/
*/


#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    char items[1000]; 
    int top;          
} Stack;

void push(Stack* stack, char item);
char pop(Stack* stack);
void initialize(Stack* stack);
bool open_brackets(char c);
bool close_brackets(char c);
bool valid_brackets(char* s);

int main() 
{
    char input[1000]; 
    printf("Enter a string with brackets: ");
    scanf("%s", input);
    if (valid_brackets(input)) 
    {
        printf("true\n");
    } else 
    {
        printf("false\n");
    }
    return 0;
}
void push(Stack* stack, char item) 
{
    stack->items[++stack->top] = item;
}
char pop(Stack* stack) 
{
    return stack->items[stack->top--];
}
void initialize(Stack* stack) 
{
    stack->top = -1;
}
bool o(char c) 
{
    return (c == '(' || c == '[' || c == '{');
}
bool close_brackets(char c) 
{
    return (c == ')' || c == ']' || c == '}');
}
bool valid_brackets(char* s) 
{
    Stack stack;
    initialize(&stack);
    
    while (*s != '\0') 
    {
        if (o(*s)) 
        {
            push(&stack, *s);
        } else if (close_brackets(*s)) 
        {
            if (stack.top == -1) 
            {
                return false; 
            } 
            else 
            {
                char top = pop(&stack);
                if ((top == '(' && *s != ')') ||
                    (top == '[' && *s != ']') ||
                    (top == '{' && *s != '}')) 
                    {
                    return false; 
                    }
            }
        }
        s++;
    }
    return (stack.top == -1); 
}



/*(2)
Design an algorithm and implement a program to validate the correctness of a given string containing brackets - parentheses '()', square brackets '[]', and curly braces '{}'. The goal is to determine whether the arrangement of brackets in the input string is valid or not. The validation should follow these rules: 1. Every opening bracket must have a corresponding closing bracket. 2. Brackets must be closed in the correct order, i.e., a closing bracket should match the most recently opened unmatched opening bracket. 3. The input string may contain other characters besides brackets, but they should be ignored during validation. 4. The input string is considered valid if and only if all brackets are properly nested and closed. Your program should return true if the input string is valid, and false otherwise. You should implement this validation using a stack data structure.

Input Format

A string containing brackets and other characters.

Constraints

The input string length is between 1 and 10^4 characters. The input string may contain alphanumeric characters and other symbols besides brackets, which should be ignored during validation.

Output Format

A boolean value: true if the input string has valid bracket arrangement, false otherwise.

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
