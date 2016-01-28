//
//  main.cpp
//  Queens
//
//  Created by Siddhant Jain on 2014-03-02.
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
vector<vector<int> > board(8, vector<int>(8, 1));
int qcount = 0;

void danger(int xcor, int ycor){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == xcor || j == ycor){
                if (board[i][j] != 7){
                board[i][j] = 0;
                }
            }
            
            if (xcor - i == ycor - j) {
                if (board[i][j] != 7){
                    board[i][j] = 0;
                }
            }
        }
    }
    
    
}

void queens(int n,int x, int y){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //cout << board[i][j];
            if (board[i][j] == 1) {
                board[i][j] = 7;
                qcount++;
                danger(i, j);
            }
            if (qcount >= 8) {
                return;
            }
        }
        //cout << endl;
    }
}
int main(void)
{
    queens(8, 0, 0);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }

}