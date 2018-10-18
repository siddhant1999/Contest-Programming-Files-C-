//
//  main.c
//  CSC190 Lab1.1
//
//  Created by Siddhant Jain on 2018-01-10.
//  Copyright © 2018 Siddhant Jain. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

char opp(char s){
    if (s==')') return '(';
    if (s==']') return '[';
    if (s=='}') return '{';
    return 0;
}

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
    if (x==NULL) return -1;
    if (*x==NULL) return -1;
    
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
        if (value == '(' || value == '[' || value == '{') {
            push(&input_list, value);
        }
        if (value == ')' || value == ']' || value == '}') {
            char l;
            if(pop(&input_list, &l) == -1){
                printf("FAIL,%d\n", n);
                return 0;
            }
            if (l != opp(value)) {
                //push(&input_list, l);
                printf("FAIL,%d\n", n);
                return 0;
            }
        }
    }
    if (input_list == NULL) {
        printf("PASS");
    }
    if ( !(rvalue==0) ) { printf("ERR: llnode_print returned an error\n"); }
    
    return 0;
}
