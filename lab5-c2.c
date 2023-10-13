/*
Design a queue data structure using two stacks, stack1 and stack2, that supports the following operations:

enqueue(x): Add an element x to the back of the queue. dequeue(): Remove and return the element at the front of the queue. isEmpty(): Return true if the queue is empty, false otherwise. You need to implement these operations efficiently, ensuring that the amortized time complexity for each operation is O(1).

Your task is to implement the queue using the provided stacks and ensure that the operations work as expected.

Sample Input 0

6
1 2
1 3
2
1 4
2
3
Sample Output 0

2
3
False
*/


#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
typedef struct list
{
    int stack[MAX+1];
    int top;
}STACK;

int isEmpty(STACK* stack1);
STACK* enqueue(STACK* stack1, STACK* stack2, int num);
STACK* dequeue(STACK* stack1);

int main()
{
    int n,m;
    STACK* stack1 = malloc(sizeof(STACK));
    STACK* stack2 = malloc(sizeof(STACK));
    stack1->top = -1;
    stack2->top = -1;
    scanf(" %d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf(" %d",&m);
        if(m == 1)
        {
            int z;
            scanf(" %d",&z);
            stack1 = enqueue(stack1,stack2,z);
        }
        else if(m == 2)
        {
            stack1 = dequeue(stack1);
        }
        else if(m == 3)
        {
            int mt;
            mt = isEmpty(stack1);
            if(mt == 1)
            {
                printf("True\n");
            }
            else
            {
                printf("False\n");
            }
        }
    }   
}
int isEmpty(STACK* stack1)
{
    if(stack1->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
STACK* enqueue(STACK* stack1, STACK* stack2, int num)
{
    if(stack1->top == MAX)
    {
        return stack1;
    }
    if(isEmpty(stack1))
    {
        stack1->top = 0;
        stack1->stack[stack1->top] = num;
        return stack1;
    }
    else
    {
        stack2->top = 0;
        stack2->stack[0] = stack1->stack[stack1->top];
        stack1->top-=1;
        while(stack1->top>-1){
            stack2->stack[stack2->top + 1] = stack1->stack[stack1->top];
            stack1->top-=1;
            stack2->top+=1;
        }
        stack1->stack[0] = num;
        stack1->top = 0;
        while(stack2->top>-1){
            stack1->stack[stack1->top + 1] = stack2->stack[stack2->top];
            stack1->top+=1;
            stack2->top-=1;
        }
        return stack1;
    }
}
STACK* dequeue(STACK* stack1)
{
    if(isEmpty(stack1))
    {
        printf("0\n");
        return stack1;
    }
    int x = stack1->stack[stack1->top];
    stack1->top-=1;
    printf("%d\n",x);
    return stack1;
}
