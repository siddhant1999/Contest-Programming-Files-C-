//
//  main.cpp
//  Line Sweep
//
//  Created by Siddhant Jain on 2015-02-17.
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

vector<pair<int, int> > board;

int main(void)
{
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int t1, t2, t3, t4;
        cin >> t1 >> t2 >> t3 >> t4;
        pair<int, int> xs;
        xs.first = t1;
        xs.second = t2;
        board.push_back(xs);
        xs.first = t3;
        xs.second = t4;
        board.push_back(xs);
        
        for (int i = t1; i <= t3; i++) {
            xs.first = i;
            xs.second = t2;
            board.push_back(xs);
            xs.second = t4;
            board.push_back(xs);
        }
        for (int i = t2; i <= t4; i++) {
            xs.first = t1;
            xs.second = t2;
            board.push_back(xs);
            xs.first = t3;
            board.push_back(xs);
        }
    }
    
}
