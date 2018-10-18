#include <stdio.h>
#include <stdlib.h>
#include "ll.h"


int ll_add_to_tail( llnode **head, int val) {
    if (head == NULL) {
        return -1;
    }
    if (*head == NULL) {
        *head = ( llnode *) malloc(sizeof( llnode));
        (*head) -> val = val;
        (*head) -> next = NULL;
        (*head) -> prev = NULL;
        return 0;
    }
    if ((*head) -> next == NULL) {
        
        llnode * h = ( llnode *) malloc(sizeof( llnode));
        (*head) -> next = h;
        ((*head) -> next) -> val = val;
        ((*head) -> next) -> next = NULL;
        ((*head) -> next) -> prev = *head;
        return 0;
    }
    
    
    
    return ll_add_to_tail(&((*head)->next), val);
    
}

int ll_add_to_head( llnode **head, int val) {
    llnode *old_head;
    if (head == NULL) {
        return -1;
    }
    old_head = *head;
    
    
    *head = ( llnode *) malloc(sizeof( llnode));
    (*head) -> val = val;
    (*head) -> next = old_head;
    (*head) -> prev = NULL;
    old_head -> prev = *head;
    
    //printf("curr: %d prev: %d\n", val, (((old_head)) -> prev)->val);
    return 0;
}
int ll_print( llnode *p) {
    if (p==NULL) {
        return 0;
    }
    
    printf("val = %d\n",p->val);
    return ll_print(p->next);
    
}

int ll_free( llnode *p) {
    llnode *f;
    if (p==NULL) {
        return -1;
    } else {
        f=p->next;
        free(p);
        return ll_free(f);
    }
}

int ll_find_by_value( llnode *pList,int val){
    if (pList==NULL){
        return -1;
    }
    if (pList -> val == val){
            return 0;
    }
    else {
        return ll_find_by_value(pList->next,val);
        
    }
    
}


int ll_del_from_tail(llnode **ppList){
    if (ppList == NULL){
        return -1;
    }
    if ((*ppList)->next == NULL) {
        *ppList = NULL;
        return 0;
    }
    if ((((*ppList)->next)->next) == NULL){
        free(((*ppList)->next)->next);
        ((*ppList)->next)= NULL;
        return 0;
    }
    return ll_del_from_tail(&((*ppList)->next));
    
}

int ll_del_from_head(llnode **ppList){
    llnode *second;
    if (ppList == NULL){
        return -1;
        
    }
    
    second = ((*ppList)->next);
    free((*ppList));
    *ppList = second;
    (*ppList)->prev = NULL;
    return 0;
    
    
}

int ll_del_by_value(llnode **ppList, int val){
    llnode *t,*p;
    if (ppList == NULL){
        return -1;
        
    }
    
    if ((*ppList) -> val == val){
        t = (*ppList)->next;
        p = (*ppList)->prev;
        free((*ppList));
        *ppList = t;
        (*ppList)->prev = p;
        return 0;
    }
    return ll_del_by_value(&((*ppList)->next),val);
}


int ll_concat(llnode **pSrcA, llnode **pSrcB){
    if (pSrcA == NULL ||pSrcB == NULL){
        return -1;
    }
    if ((*pSrcA)->next->next == NULL){
        (*pSrcA)->next->next = *pSrcB;
        return 0;
        
    }
    
    return ll_concat(&((*pSrcA)->next),pSrcB);
    
}
int ll_insert_in_order(llnode **ppList, int val){
    llnode *prev = NULL;
    llnode *curr = NULL;
    if (ppList == NULL){
        return -1;
    }
    
    
    if (*ppList == NULL){
        return ll_add_to_head(ppList,val);
    }
    if ((*ppList) -> val > val){
        return ll_add_to_head(ppList, val);
        
    }
    
    prev = *ppList;
    curr = (*ppList)->next;
    while(curr !=NULL){
        if (curr->val > val){
            break;
            
        }
        prev = curr;
        curr = prev->next;
    }
    
    prev->next = (llnode *) malloc(sizeof(llnode));
    prev ->next->val = val;
    prev->next->next = curr;
    return 0;
    
}


int ll_sort(llnode **ppList){
    int sw=1;
    llnode *prev = *ppList;
    
    if (ppList == NULL){
        return -1;
        
    }
    while (sw == 1){
        sw =0;
        *ppList = prev;
        while((*ppList)->next != NULL) {
            if ((*ppList)->val>(*ppList)->next->val){
                int y =(*ppList)->val;
                (*ppList)->val = (*ppList)->next->val;
                (*ppList)->next->val = y;
                sw = 1;
            }
            *ppList = (*ppList)->next;
        }
        *ppList = prev;
    }
    return 0;
    
}

int main(void) {
    llnode *root = NULL;
    int r=0;
    int i=0;
    
    printf("List A\n");
    r=ll_add_to_tail(&root,100);
    r=ll_add_to_tail(&root,200);
    r=ll_add_to_tail(&root,300);
    ll_del_from_tail(&root);
    ll_del_from_tail(&root);
    ll_del_from_tail(&root);
    
    for(i=0;i<10;i=i+1){
        r=ll_add_to_tail(&root,i*100);
    }
    r=ll_print(root);
    r=ll_free(root);
    
    printf("List B\n");
    root=NULL;
    r=ll_add_to_tail(&root,100);
    r=ll_add_to_tail(&root,200);
    r=ll_add_to_tail(&root,300);
    for(i=0;i<10;i=i+1){
        r=ll_add_to_head(&root,i*100);
    }
    
    
    r=ll_print(root);
    return 0;
    r=ll_sort(&root);
    printf("result\n");
    
    r=ll_print(root);
   
    r=ll_free(root);
    printf("Testing ll_insert_in_order\n");
    root=NULL;
    r=ll_add_to_tail(&root,100);
    r=ll_add_to_tail(&root,200);
    r=ll_add_to_tail(&root,300);
    printf("before\n");
    r=ll_print(root);
    r=ll_insert_in_order(&root,99);
    printf("after-a\n");
    r=ll_print(root);
    r=ll_insert_in_order(&root,101);
    printf("after-b\n");
    r=ll_print(root);
    r=ll_insert_in_order(&root,201);
    printf("after-c\n");
    r=ll_print(root);
    r=ll_insert_in_order(&root,301);
    printf("after-d\n");
    r=ll_print(root);
    r=ll_free(root);
    
    
    return 0;
}

