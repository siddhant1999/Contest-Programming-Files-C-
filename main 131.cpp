//
//  main.cpp
//  Mountain Alps
//
//  Created by Siddhant Jain on 2014-11-26.
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

vector<vector<int> > board, level;
vector<vector<bool> > visited;
vector<int> q1, q2;
int num;
bool returner = false;
void add(int x, int y){
    if(returner == true) return;
    //cout << "add : " << x << " " << y << endl;
    if (x == num && y == num) {
        cout << level[x][y] + 1;
        q1.clear();
        q2.clear();
        returner = true;
        cout << endl;
        /*for (int i = 0; i <= num ; i++) {
            for (int j = 0; j <= num; j++) {
                cout << level[i][j] << " ";
            }cout << endl;
        }*/
        return;
    }
    
    q1.push_back(x);
    q2.push_back(y);
}

void check(int x, int y, int prevx, int prevy){
    //cout << "check: " << x << " " << y << endl;
    if (x > 0 && y > 0 && x <= num && y <= num)
        if ((board[prevx][prevy] - board[x][y]) <= 2 && (board[x][y] - board[prevx][prevy] <= 2))
            if (visited[x][y] == false || level[x][y] > level[prevx][prevy]){
                visited[x][y] = true;
                if(board[1][1] < board[x][y])
                    level[x][y] = level[prevx][prevy] + 1;
                else level[x][y] = level[prevx][prevy];
                add(x,y);
            }
}

void handle(int x, int y){
    //cout << "handle: " << x << " " << y << endl;
    check(x + 1, y, x, y);
    check(x - 1, y, x, y);
    check(x, y+1, x, y);
    check(x, y-1, x, y);
}

int main(void)
{
    int n;
    cin >> n;
    while(n--){
    cin >> num;
    q1.clear();
    q2.clear();
    returner = false;
    board = vector<vector<int> >(num+1);
    level = vector<vector<int> >(num+1, vector<int>(num+1, 0));
    visited = vector<vector<bool> >(num+1, vector<bool>(num+1, false));
    int temp;
    visited[1][1] = true;
    
    for (int k = 0; k <= num; k++) {
        board[0].push_back(0);
        board[k].push_back(0);
    }
    for (int i = 1; i <= num; i++)
        for (int j = 1; j <= num; j++) {
            cin >> temp;
            board[i].push_back(temp);
        }
    
    /*for (int i = 0; i <= num; i++){
        for (int j = 0; j <= num; j++) {
            cout << board[i][j] << " ";
        }cout << endl;
    }*/
    
    q1.push_back(1);
    q2.push_back(1);
    level[1][1] = 0;
    //cout << board[q1[0]][q2[0]];
    for (int i = 0; i < q1.size(); i++) {
        handle(q1[i], q2[i]);
    }
    if (returner == false) {
        cout << "CANNOT MAKE THE TRIP";
    }
}
}
