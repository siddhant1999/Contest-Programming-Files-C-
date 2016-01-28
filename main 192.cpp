//
//  main.cpp
//  Monkey
//
//  Created by Siddhant Jain on 2015-02-07.
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
typedef long long int big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;

vc node;
vcc board;
int main(void)
{
    while (1) {
        int num;
        cin >> num;
        board = vector<vector<int> >(101, vector<int>(101, -1));
        node = vc (101);
        
        for (int i = 0; i < num; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            
        }
    }
}