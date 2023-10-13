// 14-09-2023 

/*
Josephus Problem is a famous theoretical problem in mathematics and computer science. It is a game in which n people stand in a circle, and they are numbered from 1 to n in clockwise order. Starting with a specified person, you count around the circle and eliminate every mth person until only one person remains. The goal of this problem is to find the position of the last person standing.

Write a program to solve the Josephus Problem for a given number of people (n) and a fixed counting interval (m).

Input Format

n: An integer representing the total number of people standing in a circle m: An integer representing the counting interval

Constraints

1 <= n <= 1000 1 <= m <= 1000

Output Format

Return the position (1-based index) of the last person standing.

Sample Input 0

7
3    
Sample Output 0

4
*/

/*
#include<stdio.h>
#include<stdlib.h>
int Tell(int n, int m);
int main()
{
    int n,m;
    scanf(" %d",&n);
    scanf(" %d",&m);
    printf("%d",Tell(n,m));    
}
int Tell(int n, int m)
{
    if(n == 0)
    {
        return 0;
    }
    int temp[n];
    for(int i = 0; i < n; i++)
    {
        temp[i] = 0;
    }
    int x = n;
    int p = -1;
    while(x>1)
    {
        int j = 0;
        while(j < m)
        {
            if(temp[(p+1)%n]!=-1)
            {
                p = (p+1)%n;
                j+=1;
            }
            else
            {
                p = (p+1)%n;
            }
        }
        temp[p] = -1;
        x-=1;
        for(int i = 0; i < n; i++)
        {
            //printf(" %d",temp[i]);
        }
       // printf("\n");
    }
    for(int i = 0; i < n; i++)
    {
        if(temp[i] != -1)
        {
            return i+1;
        }
    }
    return 0;
}
*/


/*
Design a queue data structure using two stacks, stack1 and stack2, that supports the following operations:

enqueue(x): Add an element x to the back of the queue. dequeue(): Remove and return the element at the front of the queue. isEmpty(): Return true if the queue is empty, false otherwise. You need to implement these operations efficiently, ensuring that the amortized time complexity for each operation is O(1).

Your task is to implement the queue using the provided stacks and ensure that the operations work as expected.

Input Format

The first line contains an integer, n, representing the number of operations to be performed. Each of the following n lines contains an operation in the following format: ‘1’ x to enqueue an element x. ‘2’ to dequeue an element. ‘3’ to check if the queue is empty.

Constraints

1 ≤ n ≤ 1000

Output Format

For each dequeue operation (operation 2), print the popped value. and for each isEmpty operation, print True if empty, else print False

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

/*
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

*/