//
//  main.cpp
//  Blindfold
//
//  Created by Siddhant Jain on 2015-02-13.
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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;

vector<vector<char> > board;
vector<int> dir;
map<char, int> ip;

void go(int index, int face, int x, int y){
    if (board[x][y] == 'X' || board[x][y] == '0') return;
    if (index == dir.size()) board[x][y] = '*';
    if (index >= dir.size()) return;
    
    int cond = dir[index];
    if (cond == 0) {
        if (face == 1) go(index+1, face, x-1, y);
        if (face == 2) go(index+1, face, x, y+1);
        if (face == 3) go(index+1, face, x+1, y);
        if (face == 4) go(index+1, face, x, y-1);
    }
    if (cond == 1) go(index+1, face%4+1, x, y);
    if (cond == 2){
        if (face == 1)
            face = 5;
        go(index+1,face-1, x, y);
    }
    
}
int main(void)
{
    int r, c;
    cin >> r >> c;
    board = vector<vector<char> > (r+2, vector<char>(c+2,'0'));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            char temp;
            cin >> temp;
            board[i][j] = temp;
        }
    }
    /*for (int i = 0; i <= r+1; i++) {
        for (int j = 0; j <= c+1; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }*/
    
    int num;
    cin >> num;
    ip['F'] = 0;
    ip['R'] = 1;
    ip['L'] = 2;
    while (num--) {
        char t;
        cin >> t;
        dir.push_back(ip[t]);
    }
    
    /*reverse(dir.begin(), dir.end());
    cout << dir[0] << " " << dir[1] << " " << dir[2] << endl;*/
    for (int k = 1; k <= r; k++) {
        for (int j = 1; j <= c; j++) {
            for (int i = 1; i < 5; i++) {
                go(0, i, k, j);
            }
        }
     }
    
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << board[i][j];
        }
     cout << endl;
     }
}

