//
//  main.cpp
//  Matrix
//
//  Created by Siddhant Jain on 2014-07-20.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
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
int n,m;
int board[101][101];
int num;
int i,j,k;
bool found = false;
int done[101][101];

bool allowed( int x ){
    if (x == i || x==j || x== k)
        return true;
    
    return false;
}

void visit(int row, int column){
    
    done[row][column] = 0;
    
    if (row == m){
        found = true;
        return;
    }
    
    for (int z = -1; z <= 1; z++)
        for (int y = -1; y <= 1; y++)
            if (z == 0 || y == 0)
                if (done[row + z][column + y] == 1)
                    if (allowed(board[row + z][column + y]) == true)
                        visit(row+z, column + y);
}



int main(void)
{
    cin >> n >> m;
    for (int o = 1; o <= m;o++){
        for (int p = 1; p <= n;p++){
            cin >> num;
            board[o][p] = num;
            done[o][p] = 1;
        }
    }
    
    
    for (i = 0; i < 10; i++)
        for (j = i; j < 10; j++)
            for (k= j; k < 10; k++)
                for (int startcol = 1; startcol <= n; startcol++)
                    if ( allowed( board[1][startcol] )==true ) {
                        found=false;
                        for (int o = 1; o <= m;o++)
                            for (int p = 1; p <= n;p++)
                                done[o][p] = 1;
                        
                        visit( 1, startcol );
                        if ( found==true ){
                            cout << i << " " << j << " " << k;
                            return 0;
                        }
                    }
    cout << "-1 -1 -1";
}
