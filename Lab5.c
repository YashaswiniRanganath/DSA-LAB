/*
Josephus Problem is a famous theoretical problem in mathematics and computer science. It is a game in which n people stand in a circle, and they are numbered from 1 to n in clockwise order. Starting with a specified person, you count around the circle and eliminate every mth person until only one person remains. The goal of this problem is to find the position of the last person standing.

Write a program to solve the Josephus Problem for a given number of people (n) and a fixed counting interval (m).
Return the position (1-based index) of the last person standing.

Sample Input 0

7
3    
Sample Output 0

4
*/


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


