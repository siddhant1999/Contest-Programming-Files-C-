//
//  main.cpp
//  s5
//
//  Created by Siddhant Jain on 2015-02-18.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <set>
#include <map>
#include <ctime>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;
vcc board;
vc list, add;
int MAX = 999999999;

//best[n][left][right] == best sum we can get by chosing from pies A[1..n], and B[left..right]
int best[3000][100][100]; // 120 MB

int get( int n, int left, int right ){
    
}

int main(void)
{
    int num , m;
    cin >> num >> m;
    //board = vcc (num+1, vc (num+1, 0));
    int sum = 0;
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
        sum += temp;
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        add.push_back(t);
        sum += t;
    }
}