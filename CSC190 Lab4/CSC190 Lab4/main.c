//
//  main.c
//  CSC190 Lab4
//
//  Created by Siddhant Jain on 2018-02-05.
//  Copyright © 2018 Siddhant Jain. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int *store;
    unsigned int size;
    unsigned int end;
} HeapType;

int initHeap (HeapType *pHeap,int size){
    int t =(int)pow(2,size)-1;
    int binary_tree[t];
    //memset(binary_tree, 0, t);
    for (int i = 0; i < t; i++) {
        binary_tree[i] = i;
    }
    (*pHeap).end = t;
    (*pHeap).size = t;
    (*pHeap).store = binary_tree;
    for (int i = 0; i < t; i++) {
        printf("%d ", (pHeap)->store[i]);
    }
    printf("\n\n\n");
    
    return 0;
}

void trav(HeapType *pHeap, int index, int **p){
    
    //left (index+1) * 2 -1
    //right (index+1) * 2
    
    
    if ((pHeap)->size > (index+1) * 2) {
        int a= ((index+1) * 2) -1;
        
        trav(pHeap, a, p);
        
    }
    int t =(pHeap)->store[index];
    (*p)[index] = t;
    
    if ((pHeap)->size > (index+1) * 2) {
        int a =(index+1) * 2;
        trav(pHeap, a, p);
    }

}

int inorder  (HeapType *pHeap, int **output, int *o_size){
    
    *output = (int*) malloc(sizeof(int)*((*pHeap).size));
    *o_size = (*pHeap).size;
    
    trav(pHeap, 0, output);
    return 0;
}

void trav1(HeapType *pHeap, int index, int **p){
    
    //left (index+1) * 2 -1
    //right (index+1) * 2
    int t =(pHeap)->store[index];
    (*p)[index] = t;
    
    if ((pHeap)->size > (index+1) * 2) {
        int a= ((index+1) * 2) -1;
        
        trav(pHeap, a, p);
        
    }
    
    
    if ((pHeap)->size > (index+1) * 2) {
        int a =(index+1) * 2;
        trav(pHeap, a, p);
    }
    
}

int preorder (HeapType *pHeap, int **output, int *o_size){
    *output = (int*) malloc(sizeof(int)*((*pHeap).size));
    *o_size = (*pHeap).size;
    
    trav1(pHeap, 0, output);
    return 0;
}
void trav2(HeapType *pHeap, int index, int **p){
    
    //left (index+1) * 2 -1
    //right (index+1) * 2
    
    
    if ((pHeap)->size > (index+1) * 2) {
        int a= ((index+1) * 2) -1;
        
        trav(pHeap, a, p);
        
    }
    
    
    if ((pHeap)->size > (index+1) * 2) {
        int a =(index+1) * 2;
        trav(pHeap, a, p);
    }
    int t =(pHeap)->store[index];
    (*p)[index] = t;
}
int postorder(HeapType *pHeap, int **output, int *o_size){
    *output = (int*) malloc(sizeof(int)*((*pHeap).size));
    *o_size = (*pHeap).size;
    
    trav2(pHeap, 0, output);
    return 0;
}
int main(void) {
    int *y;
    //*y = 1;
    //*(y+1) = 2;
    int *output;
    HeapType pHeap;
    initHeap(&pHeap, 4);
    for (int i = 0; i < (pHeap).size; i++) {
        printf("%d ", (pHeap).store[i]);
    }
    printf("\n\n");
    //printf("%d %d", y[0], y[1]);
    inorder(&pHeap, &output, y);
    return 0;
}
