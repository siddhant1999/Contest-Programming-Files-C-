//
//  main.cpp
//  Book Shelf dp
//
//  Created by Siddhant Jain on 2015-02-05.
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
typedef vector<int> vc;
typedef vector<vector<int> > vvc;

vvc board;
vc dp;
int main(void)
{
    int num, lim;
    cin >> num >> lim;
    
    board = vector<vector<int> > (num+4, vector<int>(3,0));
    dp = vc (num+1, 4294967293);
    dp[0] = 0;
    for (int i = 1; i <= num; i++){
        int h, w;
        cin >> h >> w;
        board[i][0] = h;
        board[i][1] = w;
    }
    dp[1] = board[1][0];//width of first book
    
    for (int i = 1; i <= num; i++) {//itterate over all the books
        int sum = 0;//width sum
        int he = 0;//height of the bookshelf
        for (int j = i; j <= num && sum+board[j][1] <= lim; j++) {
            sum += board[j][1];
            he = max(he, board[j][0]);
            dp[j] = min(he + dp[i-1], dp[j]);
        }
    }
        cout << dp[num];
}
