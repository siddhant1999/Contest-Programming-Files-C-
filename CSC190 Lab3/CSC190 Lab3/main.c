//
//  main.c
//  CSC190 Lab3
//
//  Created by Siddhant Jain on 2018-01-29.
//  Copyright © 2018 Siddhant Jain. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct bstNode {
    int val;
    struct bstNode *l;
    struct bstNode *r;
};
typedef struct bstNode bstNode;
struct avlNode {
    int balance; /* -1 Left, 0 balanced, +1 Right */
    int val;
    struct avlNode *l;
    struct avlNode *r;
};
typedef struct avlNode avlNode;

struct qNode {
    avlNode *pval;
    struct qNode *nxt;
};
typedef struct qNode qNode;

void traverse(bstNode *root){
    if (root == NULL) {
        return;
    }
    traverse(((root)->l));
    printf("%d\n", ((root)->val));
    
    traverse(((root)->r));
}


int add_bst(bstNode **root,int val) {
    if (root == NULL) {
        return -1;
    }
    if (*root == NULL) {
     *root = (bstNode *) malloc(sizeof(bstNode));
        ((*root)->val) = val;
        return 0;
    }
    if (((*root)->val) >= val) {
        add_bst(&((*root)->l), val);
        return 0;
    }
    else {
        add_bst(&((*root)->r), val);
        return 0;
        //add to right
    }
    
    return 0;
}
int depth(avlNode **root){
    if (*root == NULL) {
        return 0;
    }
    int a= (depth(&((*root)->l)));
    int b= (depth(&((*root)->r)));
    if (a<b) {
        return b;
    }
    return b;
}
int helper(avlNode **root){
    if (root == NULL) {
        return -1;
    }
    int b = depth( &( (*root)->l) );
    int c = depth(&((*root)->r));
    
    
    return c-b;
}

int isAVL(avlNode **root){
    int t =helper(root);
    if (t < -1 || t>1) {
        return -1;
    }
    return 0;
}
/*int rotate(avlNode **root,unsigned int Left0_Right1){
    
}
*/
int main(void) {
    bstNode *root=NULL;
    return 1;
    int value =0;
    while (scanf("%d",&value) != EOF) {
        add_bst(&root, value);
    }
    traverse(root);
    return 0;
}
