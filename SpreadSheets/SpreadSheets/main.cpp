//
//  main.cpp
//  SpreadSheets
//
//  Created by Siddhant Jain on 2015-07-22.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <fstream>
#include <set>
#include <map>
#include <ctime>
using namespace std;
//board = vcc (num+1, vc (num+1, 0));

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1000000000;
vcc board;
vc list;

bool myfunc (int i,int j) { return (i<j); }

int main(void)
{
    list.push_back(4);
    list.push_back(2);
    list.push_back(9);
    list.push_back(1);
    list.push_back(3);
    list.push_back(4);
    list.push_back(7);
    
    sort(list.begin(), list.end(), myfunc);
    for(int i = 0; i <list.size(); i++){
        cout << list[i] << endl;
    }
    
    int r, c;
    cin >> r >> c;
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
}