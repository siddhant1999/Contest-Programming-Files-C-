//
//  main.cpp
//  Travelling Salesmen
//
//  Created by Siddhant Jain on 2016-05-11.
//  Copyright © 2016 Siddhant Jain. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <bitset>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <iomanip>

using namespace std;

vector< vector<int> > board;
vector<int> list, done;

int main(void){
    int n, m;
    cin >> n >> m;
    board = vector<vector<int> > (n+1);
    done = vector<int> (n+1, -1);
    for (int i = 0;i< m; i++) {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        list.push_back(t);
    }
}