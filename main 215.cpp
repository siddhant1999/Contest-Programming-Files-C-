//
//  main.cpp
//  Super Plumber
//
//  Created by Siddhant Jain on 2014-12-03.
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
vector<vector<char> > board;
vector<vector<int> > visited;
int num, m;

bool check(int i, int j){
    if (i < 0) return false;
    if (j < 0) return false;
    if (i > num) return false;
    if (i > m) return false;
    return true;
    /*
    if(i == num && j == m){
        if(board[i][j] == '*'){
            visited[i][j] = 0;
            return curval;
        }
        else {
            visited[i][j] = (board[i][j]-'0');
            return curval + visited[i][j];
        }
    }
    if(visited[i][j] != -1) return visited[i][j];
    */
}

void helper(int x ,int y, int val){
    if (check(x+1, y) == true){
        return;
    }//down
    if (check(x+1, y) == true){
        
    }//up

    if (check(x, y+1) == true){
        
    }//right

}

int main(void)
{

    cin >> num >> m;
    board = vector<vector<char> > (num, vector<char>(m, 0));
    visited = vector<vector<int> > (num, vector<int>(m, -1));
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++) {
            int temp;
            cin >> temp;
            board[i][j] = temp;
        }
    
    helper(num,0, (board[num][0]-'0'));
    
}

