//
//  main.cpp
//  USACO 2
//
//  Created by Siddhant Jain on 2014-12-13.
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
vector<vector<bool> > board;
vector<int> list1;
vector<int> list2;
int counti = 0;
 int n,m;

bool inorout(int i , int j){
    if (i < 1) return false;
    if (i > n) return false;
    if (j < 1) return false;
    if (j > m) return false;
    if(!board[i][j])return false;
    
    return true;
}

bool check(int i, int j){
    if(!inorout(i , j-1) && inorout(i , j+1) && inorout(i , j+2)){
        return true;
    }
    if(!inorout(i-1 , j) && inorout(i+1 , j) && inorout(i+2 , j)){
        return true;
    }
    return false;
}

int main(void)
{
    freopen("crosswords.in", "r", stdin);
    freopen("crosswords.out", "w", stdout);
    
   
    cin >> n >> m;
    board = vector<vector<bool> >(n+1, vector<bool>(m+1, false));
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char temp;
            bool bol = false;
            cin >> temp;
            if(temp == '.') bol = true;
            board[i][j] = bol;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if(board[i][j])
                if(check(i,j)){
                    counti++;
                    list1.push_back(i);
                    list2.push_back(j);
                }
            }
    cout << counti << endl;
    for (int i  = 0; i < list1.size(); i++) {
        cout << list1[i] << ' ' << list2[i] << endl;
    }
}

