//
//  main.c
//  Preping for Test
//
//  Created by Siddhant Jain on 2017-11-15.
//  Copyright © 2017 Siddhant Jain. All rights reserved.
//

#include <stdio.h>

void swap(int *num1, int *num2) {
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main(void) {
    int a = 1;
    int b = 2;
    int q[10]={3};
    int *y= (int*) malloc(4*sizeof(int));
    y[0] =1;
    y[1] = 2;
    y[2] = 3;
    y[3] = 4;
    printf("%p, %p, %p, %p\n\n", &y[0], &y[1], &y[2], &y[3]);
    printf("%d\n\n", *y);
    printf("%d\n\n\n", q[2]);
    float t = 4.1234567;
    printf("%.2f\n", t);
    printf("%d %d\n", a, b);
    swap(&a, &b);
    printf("%d %d\n", a, b);
}
