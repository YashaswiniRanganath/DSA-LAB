/*
Design an efficient algorithm to determine the height of a binary tree .Given the root node of a binary tree find the height of the tree
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct TREE{
    int data;
    struct TREE* left;
    struct TREE* right;
}tree;



tree* make(int a[],int n,tree* s){

    
    s = malloc(sizeof(tree));
    tree* am = s;
    s->data = a[0];
    s->left = NULL;
    s->right = NULL;
    tree* x[n];

    int end = 0;
    int start = 0;
    x[end++] = s;
    int m = 0;

    while(end != n){
        if(a[end] != -1){
            if(end == 2*start+1){
                x[start]->left = malloc(sizeof(tree));
                x[start]->left->data = a[end];
                x[start]->left->left = NULL;
                x[start]->left->right = NULL;
                x[end++] = x[start]->left;
                m++;
            }
            else if(end == 2*start+2){
                x[start]->right = malloc(sizeof(tree));
                x[start]->right->data = a[end];
                x[start]->right->left = NULL;
                x[start]->right->right = NULL;
                x[end++] = x[start]->right;
                m++;
            }
        }
        else{
            if(end == 2*start+1){
                x[start]->left = NULL;
                end++;
                m++;
            }
            else if(end == 2*start+2){
                x[start]->right = NULL;
                end++;
                m++;
            }
        }

        if(m == 2){
            
            start++;
            m = 0;
        }
    }
    return am;
}

int height(tree* root){
    if (root == NULL){
        return 0;
    }
    else {

        int lDepth = height(root->left);
        int rDepth = height(root->right);


        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}


int main(){

    int x;
    scanf(" %d",&x);
    int a[x];

    for(int i = 0; i < x; i++){
        int z;
        scanf(" %d", &z);
        a[i] = z;
    }

    tree *d = NULL;
    d=make(a,x,d);


    printf("%d", height(d));



}