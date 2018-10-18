//
//  main.c
//  CSC190 Lab1
//
//  Created by Siddhant Jain on 2018-01-08.
//  Copyright © 2018 Siddhant Jain. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct llnode {
    char value;
    struct llnode *next;
};
typedef struct llnode llnode;

int llnode_add_to_tail(llnode **x,char value) {
    if (x==NULL) { return -1; }
    if (*x==NULL) {
        *x = (llnode *) malloc(sizeof(llnode));
        (*x)->value = value;
        (*x)->next = NULL;
        return 0;
    } else {
        return llnode_add_to_tail(&((*x)->next),value);
    }
}
int llnode_add_to_head(llnode **x,char value) {
    llnode *y = (llnode *) malloc(sizeof(llnode));
    (y)->value = value;
    (y)->next = *x;
    *x=y;
    return 0;
}
int llnode_print_from_head(llnode *x) {
    if (x==NULL) { return 0; }
    else {
        printf("%c\n",x->value);
        return llnode_print_from_head(x->next);
    }
}

int llnode_print_from_tail(llnode *x) {
    if (x==NULL) { return 0; }
    else {
        if (x->next == NULL) {
            printf("%c\n",x->value);
            return 0;
        } else {
            llnode_print_from_tail(x->next);
            printf("%c\n",x->value);
            return 0;
        }
    }
}

int push(llnode **x, char value){
    return llnode_add_to_tail(x,value);
}

int pop(llnode **x, char *return_value){
    if (x==NULL) { return -1; }
    if (*x==NULL) {
        return -1;
    }
    if ((*x)->next == NULL) {
        *return_value=(*x)->value;
        *x=NULL;
        return 0;
    }
    if (((*x)->next)->next ==NULL) {
        *return_value = ((*x)->next)->value;
        (*x)->next = NULL;
        return 0;
    }
    return pop(&((*x)->next),return_value);
    
}

int main(void) {
    int n=0;
    char value=0;
    char rvalue=0;
    llnode *input_list=NULL;
while (scanf("%c",&value) != EOF) {
        n++;
    
        //llnode_add_to_tail(&input_list,value);
        //llnode_add_to_head(&input_list,value);
        scanf("%c",&value);
    push(&input_list, value);
    }
    char return_value;
    /*pop(&input_list, &l);
    printf("%c", l);
    pop(&input_list, &l);
    printf("%c", l);
    pop(&input_list, &l);
    printf("%c", l);*/
    printf("INFO: you entered %d items\n",n);
    rvalue=llnode_print_from_head(input_list);
    if ( !(rvalue==0) ) { printf("ERR: llnode_print returned an error\n"); }
    
    return 0;
}
