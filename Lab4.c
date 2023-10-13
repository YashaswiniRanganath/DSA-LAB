// LAB4-> 07.09.2023 

/*(1)
Design and implement an algorithm to convert infix mathematical expressions to postfix notation using a stack data structure. The algorithm should be capable of handling expressions containing operators such as addition (+), subtraction (-), multiplication (*), division (/), and parentheses. The goal is to develop a program that can efficiently and accurately convert infix expressions to postfix notation while respecting operator precedence and parentheses.

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


