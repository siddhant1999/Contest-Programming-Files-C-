//
//  main.cpp
//  Maze
//
//  Created by Siddhant Jain on 2015-02-15.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//
/*
 3
 2
 2
 -|
 *+
 3
 5
 +||*+
 +++|+
 **--+
 2
 3
 +*+
 +*+
*/


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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<char> vc;
typedef vector<vector<char> > vcc;
int a,b;
vcc board;
vector<vector<int> >vis;
int mn = 999999999;

int foo(int x, int y, int count){
    if (board[x][y] == '*' || board[x][y] == '#' ) {
            return 999999999;
    }
    if (vis[x][y] != -1) {
        vis[x][y] = min(vis[x][y], count+1);
        return vis[x][y];
    }
    if (x == a && b == y) {
        mn = min(count, mn);
        return count;
    }
    vis[x][y] = count;
    int mini = 999999999;
    if (board[x][y] == '+') {
        mini = min(foo(x+1, y, count+1), mini);
        mini = min(foo(x-1, y, count+1), mini);
        mini = min(foo(x, y+1, count+1), mini);
        mini = min(foo(x, y-1, count+1), mini);
    }
    else if (board[x][y] == '|') {
        mini = min(foo(x+1, y, count+1), mini);
        mini = min(foo(x-1, y, count+1), mini);
    }
    else if (board[x][y] == '-') {
        mini = min(foo(x, y+1, count+1), mini);
        mini = min(foo(x, y-1, count+1), mini);
    }
    return mini;
}

int main(void)
{
    int num;
    cin >> num;
    
    for (int l = 0; l < num; l++) {
        
        cin >> a >> b;
        board = vcc (a+2, vc(b+2, '#'));
        vis = vector<vector<int> > (a+2, vector<int>(b+2, -1));
        for (int i = 1; i <= a; i++)
            for (int j = 1; j <= b; j++) {
                char temp;
                cin >> temp;
                board[i][j] = temp;
                
            }
        
        vis[1][1] = -1;
        foo(1, 1, 1);
        if (mn == 999999999) {
            cout << -1 << endl;
        }else cout << mn <<endl;

        board.clear();
        vis.clear();
        mn = 999999999;
    }
}
