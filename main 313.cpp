//
//  main.cpp
//  Mirrors
//
//  Created by Siddhant Jain on 2/8/2014.
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
using namespace std;
int n, m;
char input;

//1 = left
//2 = top
//3 = right
//4 = bottum

vector<vector<char> > field(40, vector<char>(40, '*'));
vector<int> maximum;
int check(int i, int j,int steps, int wherefrom){
    if (i < 0 || i > n || j < 0 || j > m) {
        maximum.push_back(steps);
        return steps;
    }
    if (field[i][j] == '*' || !ispunct(field[i][j])){
        maximum.push_back(steps);
        return steps;
    }
    if (field[i][j] == '/') {
        if (wherefrom == 1)
            maximum.push_back(check(i+1, j, steps + 1, 4));
        if (wherefrom == 2)
            maximum.push_back(check(i, j-1, steps + 1, 3));
        if (wherefrom == 3)
            maximum.push_back(check(i-1, j, steps + 1, 2));
        if (wherefrom == 4)
            maximum.push_back(check(i, j+1, steps + 1, 1));
    }
    else {
        
    if (wherefrom == 1)
        maximum.push_back(check(i+1, j, steps + 1, 4));
    if (wherefrom == 2)
        maximum.push_back(check(i, j-1, steps + 1, 3));
    if (wherefrom == 3)
        maximum.push_back(check(i-1, j, steps + 1, 2));
    if (wherefrom == 4)
        maximum.push_back(check(i, j+1, steps + 1, 1));
    }
    return 0;
}


int main(void)
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> input;
            field[i][j] = input;
        }
    }
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= m+1; j++) {
            cout << field[i][j];
        }
        cout << endl;
    }
    for (int k = 1; k <= m ; k++) {
       maximum.push_back(check(1, k, 0, 2));
       maximum.push_back(check(n-1, k, 0, 4));
    }
    for (int l = 1; l <= n ; l++) {
       maximum.push_back(check(l, 1, 0, 1));
       maximum.push_back(check(l, n-1, 0, 3));
    }
    sort(maximum.begin(), maximum.end());
    cout << maximum[maximum.size()-1] - 1;
}







