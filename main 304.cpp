//
//  main.cpp
//  Junior 2013 Question 3 Revised
//
//  Created by Siddhant Jain on 10/13/13.
//  Copyright (c) 2013 Siddhant Jain. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char digits[10];
int num_digits = 0;
int n;

int freq[10]; // freq[i] is the number of times that digit i occurrs

void extract(){
    sprintf(digits, "%d" , n);
    num_digits = strlen(digits);
    int i;
    for (i = 0; i<num_digits; i++) {
        digits[i] -= '0';
    }
    //sprintf( foo, “x=%d, y=%d”, x, y );
    /*int cur_val=n;
    num_digits = 0;
    
    while ( cur_val > 0 ){
        int digit=cur_val%10;
        cur_val/=10;
        digits[num_digits]=digit;
        
        //printf( "digit[%d]=%d\n", num_digits,digit);
        num_digits++;
     
    }
    */
}

bool is_distinct(){
    
    memset( freq, 0, sizeof(int)*10 );
    for ( int i=0; i<num_digits; i++ )
        freq[ digits[i] ]++;
    
    for ( int i=0; i<10; i++ ){
        //printf( "freq[%d]=%d\n", i, freq[i] );
        if ( freq[i] > 1 ){
            return false;
        }
    
    }
    return true;
    
}

int main(){
    
    scanf("%d",&n);
    
    while ( true ){
        n++;
        extract();
        if(is_distinct() == true){
            printf("%d\n", n);
            break;
        }
        
    }
    
}







