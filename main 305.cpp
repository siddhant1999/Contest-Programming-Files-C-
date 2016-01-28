//
//  main.cpp
//  Examples
//
//  Created by Siddhant Jain on 10/27/13.
//  Copyright (c) 2013 Siddhant Jain. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    int v2 = rand() % 5;
    printf("%d\n", v2);
    }
}

float x=167.00045900;
int y=x;
double fractional=fabs(x-int(x));
printf("%5.1f, %lf, %d", x, fractional, y);
//if ( fractional<0.0000001 )

