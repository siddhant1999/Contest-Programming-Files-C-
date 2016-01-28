//
//  main.cpp
//  hack3
//
//  Created by Siddhant Jain on 2015-01-11.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

//
//  main.cpp
//  hack2
//
//  Created by Siddhant Jain on 2015-01-10.
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
int num,row,col,cases,t1,t2,t3;
vector<vector<vector<int>>> board;
vector<int>q1,q2,q3, val;
int a,b,c,x,y,z;
int yyy;
int done = 0;
void add(int n,int m, int v){
    //cout << n << " " << m << " " << v << endl;
    if (board[yyy][n][m] == 9) {
        done = v;
    }
    q2.push_back(n);
    q3.push_back(m);
    val.push_back(v);
    
}

void handle(int n, int m, int v){
    yyy = v%4;
    if (yyy == 0)
        yyy = 4;
    
    if (board[yyy][n - 1][m] < 1 ||board[yyy][n - 1][m] > 5) {
        add(n-1,m,v+1);
    }
    if (board[yyy][n + 1][m] < 1 ||board[yyy][n + 1][m] > 5) {
        add(n+1,m,v+1);
    }
    if (board[yyy][n][m-1] < 1 ||board[yyy][n][m-1] > 5) {
        add(n,m-1,v+1);
    }
    if (board[yyy][n][m+1] < 1 ||board[yyy][n][m+1] > 5) {
        add(n,m+1,v+1);
    }
}

void stages(int cur){
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            
            int temp = board[cur][i][j];
            if (temp > 0 && temp < 5) {
                temp = (board[cur][i][j] + cur-1)%4 + 1;
                
                if (temp == 1) {
                    for (int kk = i-1; (board[cur][kk][j] == 0) || (board[cur][kk][j] > 5); kk--)
                        board[cur][kk][j] = 5;
                }
                if (temp == 2) {
                    for (int kk = j+1; (board[cur][i][kk] == 0) || (board[cur][j][kk] > 5); kk++)
                        board[cur][i][kk] = 5;
                }
                if (temp == 3) {
                    for (int kk = i+1; (board[cur][kk][j] == 0) || (board[cur][kk][j] > 5); kk++)
                        board[cur][kk][j] = 5;
                }
                if (temp == 4) {
                    for (int kk = j-1; (board[cur][i][kk] == 0) || (board[cur][j][kk] > 5); kk--)
                        board[cur][i][kk] = 5;
                }
            }
            
        }

    }
}

int main(void)
{
    
    cin >> num;
    
    for(int u = 1; u <= num; u++) {
        
        cin >> row >> col;
        board = vector<vector<vector<int>>> (5, vector<vector<int>>(row+2, vector<int>(col+2)));
        for (int i = 0; i <= row+1; i++) {
            board[0][i][0] = 5;
            board[0][i][col+1] = 5;
        }
        for (int i = 0; i <= col+1; i++) {
            board[0][0][i] = 5;
            board[0][row+1][i] = 5;
        }
        char temp;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                cin >> temp;
                if (temp == '^') {
                    board[0][i][j] = 1;
                }
                if (temp == '>') {
                    board[0][i][j] = 2;
                }
                if (temp == 'v') {
                    board[0][i][j] = 3;
                }
                if (temp == '<') {
                    board[0][i][j] = 4;
                }
                if (temp == '#') {
                    board[0][i][j] = 5;
                }
                if (temp == 'S') {
                    a = 0;
                    b = i;
                    c = j;
                    board[0][i][j] = 8;
                }
                if (temp == 'G') {
                    x = 0;
                    y = i;
                    z = j;
                    board[0][i][j] = 9;
                }
                if (temp == '.') {
                    board[0][i][j] = 0;
                }
            }
        }
        board[1] = board[0];
        board[2] = board[0];
        board[3] = board[0];
        board[4] = board[0];
        
        stages(1);
        stages(2);
        stages(3);
        stages(4);
        
        /*for (int i = 0; i < 5; i++) {
            for (int j  = 0; j <= row+1; j++) {
                for (int k  = 0; k <= col+1; k++) {
                    cout << board[i][j][k];
                }
                cout << endl;
            }
            cout << endl << endl;
        }*/
        q1.push_back(a);
        q2.push_back(b);
        q3.push_back(c);
        val.push_back(1);
        
        bool lll = false;
        for (int i = 0; i < q2.size(); i++) {
            if(done != 0){
                cout << "Case #" << u << ':' << " "<<  done-1 << endl;
                lll = true;
                break;
            }
            handle(q2[i],q3[i],val[i]);
        }
        if (!lll) {
            cout << "Case #" << u << ':' << " "<<  "impossible" << endl;
        }
        
        q1.clear();
        q2.clear();
        q3.clear();
        val.clear();
        board[0].clear();
        board[1].clear();
        board[2].clear();
        board[3].clear();
        board[4].clear();
        done = 0;
    }
}
