//
//  main.cpp
//  Map
//
//  Created by Siddhant Jain on 2015-01-01.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <map>
using namespace std;

vector<vector<char> > board;



void handle(int x , int y){
    check(x + 1, y);
    check(x - 1, y);
    check(x, y+1);
    check(x, y-1);
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    
    char temp;
    board = vector<vector<char> > (n + 2, vector<char>(m+2, 0));
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            cin >> temp;
            board[i][j] = temp;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if(board[i][j] == 'X'){
                handle(i,j);
            }
        }
    }
    
}

