//
//  main.c
//  Binary Search Tree
//
//  Created by Siddhant Jain on 2017-11-23.
//  Copyright © 2017 Siddhant Jain. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

int add(TreeNode **root,int v){
    if (*root == NULL) {
        *root  = ( TreeNode *) malloc(sizeof( TreeNode));
        (*root)->val = v;
        return 0;
    }
    if (v < ((*root)->val)) {
        add((&((*root)->left)), v);
    }
    else if(v > (*root)->val){
        add((&((*root)->right)), v);
    }
    return 0;
}
int print(TreeNode *root){
    if (root==NULL) {
        return 0;
    }
    print(root->left);
    printf("%d ", root->val);
    print(root->right);
    return 0;
}
int main(int argc, const char * argv[]) {
    TreeNode* r = NULL;
    add(&r, 8);
    add(&r, 6);
    add(&r, 9);
    add(&r, 2);
    add(&r, 18);
    add(&r, 1);
    print(r);
    return 0;
}
