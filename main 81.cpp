//
//  main.cpp
//  Number Matrix
//
//  Created by Siddhant Jain on 2014-07-19.
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
//remember to create a done array
int done[101][101];
bool found = false;


void visit(int row, int column){
    if (row == m) {
        found=true;
    }
    done[row][column] = -1;
    for (int a = -1; a <=1; a++)
        for (int b = -1; b <=1; b++)
            if (a==0 || b==0)
                if (done[row + a][column + b] == 0)
                    visit(row + a, column + b);
    
}



bool allowed( int x ){
    if (x == i || x==j || x== k) {
        return true;
    }
    return false;
}

int main(void)
{
    int kkk = -1;
    for (int q = 0; q <= 100; q++)
        for (int w = 0; w <= 100; w++)
            done[q][w] = kkk;
   
    //ifstream in("matrix.txt");
    cin >> n >> m;
    //vector<vector<int>> board(n, vector<int>(m,-1));
    for (int o = 1; o <= m;o++){
        for (int p = 1; p <= n;p++){
            cin >> num;
            board[o][p] = num;
            done[o][p] = 0;
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
                                done[o][p] = 0;
                        
                       // visit( 1, startcol );
                        if ( found==true ){
                            cout << i << " " << j << " " << k;
                            return 0;
                        }
                    }
    
}
