//
//  main.c
//  Exam Practice
//
//  Created by Siddhant Jain on 2017-12-13.
//  Copyright © 2017 Siddhant Jain. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

struct info{
    int index;
    float average;
    char UserID;
    int *element;
};

int func(char **str){
    *str[1] = 'o';
    return 0;
}
int main(void) {
    //struct info elements[8];
    struct info t;
    t.index = 1;
    t.average = 0.2;
    t.UserID = '3';
    char s[8];
    func(&s);
    printf("%c", s[1]);
    return 0;
}
