//
//  main.cpp
//  Herding
//
//  Created by Siddhant Jain on 2014-11-07.
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
map<char, int> cardinal;
char directions[1002][1002];
int filled[1001][1001] = {0};
int traps = 0;

bool flood(int x, int y, int fillernum){
    cout << "x: " << x << " y: " << y << " fnum : " << fillernum << endl;
    if (filled[x][y] == fillernum)
        return true;
    if (filled[x][y] != 0) {
        return false;
    }
    filled[x][y] = fillernum;
    if (directions[x][y] == 'N')
        if(flood(x-1, y, fillernum)) traps++;
    if (directions[x][y] == 'S')
        if(flood(x+1, y, fillernum)) traps++;
    if (directions[x][y] == 'E')
        if(flood(x, y+1, fillernum)) traps++;
    if (directions[x][y] == 'W')
        if(flood(x, y-1, fillernum)) traps++;
    
    return false;
}

int main(void)
{
    int n, m, orign, origm;
    cin >> n >> m;
    cardinal['N'] = 1;
    cardinal['S'] = -1;
    cardinal['E'] = 1;
    cardinal['W'] = -1;
    
    orign = n;
    origm = m;
    
    for (int k = 0; k <= m + 1; k++) {
        directions[0][k] = '0';
        directions[k][0] = '0';
        directions[n+ 1][k] = '0';
        directions[k][m+ 1] = '0';
    }
    //vector<vector<char> > directions(n + 1, vector<char>(m + 1, -1));
    //directions[orign][origm] = '6';
    //cout << directions[orign][origm];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char temp;
            cin >> temp;
            directions[i][j] = temp;
        }
    //for (int i = 0; i <= n+1; i++){
      //  for (int j = 0; j <= m+1; j++) {
        //    cout << directions[i][j];
        //}
        //cout << endl;
    //}
    //return 0;
    //cout << directions[n][m];
    int curnum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (directions[i-1][j] != 'S' && directions[i+1][j] != 'N' && directions[i][j-1] != 'E' && directions[i][j+1] != 'W') {//this is a starting point
                curnum++;
                flood(i, j, curnum);//sending it the starting point so it can fill the grid
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (filled[i][j] == 0) {
                curnum++;
                flood(i, j, curnum);
            }
        }
    }

    /*for (int i = 0; i <= n+10; i++) {
        for (int j = 0; j <10; j++) {
            cout << filled[i][j];
        }
        cout << endl;
    }*/
    cout <<traps;
}

