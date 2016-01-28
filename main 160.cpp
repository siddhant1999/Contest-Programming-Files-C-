//
//  main.cpp
//  Setting Again
//
//  Created by Siddhant Jain on 2015-02-16.
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

vc board;
int main(void)
{
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        board.push_back(temp);
    }
    sort(board.end(), board.begin());
    
    while (1) {
        int cur = board[0]+1;
        for (int i = 0; i < board.size(); i++) {
            if(board[i] < cur){
                cur = board[i];
                board[i] = -5;
            }
            else if (<#condition#>)
        }
    }
}
