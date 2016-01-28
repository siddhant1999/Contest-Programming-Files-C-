//
//  main.cpp
//  Troyangles
//
//  Created by Siddhant Jain on 2015-02-14.
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
/*
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;

vector<vector<char> > board;
int num;
int tot = 0;

void sm(int x, int y, int ith){
    int n = x+1;
    bool c = false;
    for (int m = y-1; m < y-1 + ith + 2; m++) {
        if (board[n][m] != '#') {
            c = true;
            break;
        }
    }
    if (!c) {
        tot++;
        sm(n, y-1, ith+2);
    }
    else return;
}

void check(void){
    for (int i = 1; i <= num; i++)
        for (int j = 1; j <= num; j++)
            if(board[i][j] == '#'){
                tot++;
                sm(i, j, 1);
            }
}

int main(void)
{
    cin >> num;
    board = vector<vector<char> > (num+2, vector<char>(num+2,'0'));
    
    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++) {
            char temp;
            cin >> temp;
            board[i][j] = temp;
        }
    }
    check();
    cout << tot;
}*/

#define x first
#define y second
#define MAX 2002

int heights[MAX][MAX];
int l[MAX], r[MAX];
int n;
#define min3(x,y,z) min( (x), min( (y), (z)  )   )
int answer = 0;
#define in cin
int main()
{
    //ifstream in("test.txt");
    in >> n;
    string s;
    for (int i = 1; i <= n; i++){
        in >> s;
        //trace(s);
        for (int j = 1; j <= n; j++){
            
            if (s[j - 1] == '#'){
                
                heights[i][j] = 1;
                l[j] = l[j-1] + 1; r[j] = 1;
                
            }
            else{
                heights[i][j] = 0;
                l[j] = r[j] = 0;
            }
        }
        
        for (int j = n; j >= 1; j--)
            if (heights[i][j])
                r[j] = r[j + 1] + 1;
        
        
        for (int j = 1; j <= n; j++){
            int thing = min3(heights[i - 1][j] + 1, l[j], r[j]);
            if (thing > heights[i][j])
                heights[i][j] = thing;
            answer += heights[i][j];
            //trace3(i, j, heights[i][j]);
        }
        
    }
    cout << answer;
    //cin.get();
    return 0;
}