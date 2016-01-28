//
//  main.cpp
//  Mouse
//
//  Created by Siddhant Jain on 1/11/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>


using namespace std;
char board[26][26];
int ways[26][26];
int cats;

int getways(int i, int j){
    if (ways[i][j] != -1) {
        return ways[i][j];
    }
    if ( board[i][j] !=0 )
            return 0;
    
    if (i == 0 || j == 0) {
        return 0;
    }
    if (i == 1 && j ==1) {
        return 1;
    }
    
    else {
        ways[i][j] = getways(i - 1, j) + getways(i, j -1);
        return ways[i][j];
    }
    
}

int main(void)
{
    int r, c;
    cin >> r;
    cin >> c;
    int cats;
    cin >> cats;
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            board[i][j] = 0;
            ways[i][j] = -1;
        }
    }
    
    int i,j;
    while ( cats-- ) {
            cin >> i >> j;
        board[i][j] = -1;
        }
    
    

    cout << getways(r, c) << endl;
}