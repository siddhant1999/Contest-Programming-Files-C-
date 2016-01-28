//
//  main.cpp
//  Keep On
//
//  Created by Siddhant Jain on 2015-02-15.
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

vc path (14001, 0);
int a, b, t =0;
void foo(int x){
    
    if (x == 7000) {
        t++;
        return;
    }
    for (int i = x+a; i <= x+b && i <= 7000; i++) {
        if (path[i] == 1) {
            foo(i);
        }
    }
    return;
}
int main(void)
{
    //0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000
    path[0] = 1;
    path[990] = 1;
    path[1010] = 1;
    path[1970] = 1;
    path[2030] = 1;
    path[2940] = 1;
    path[3060] = 1;
    path[3930] = 1;
    path[4060] = 1;
    path[4970] = 1;
    path[5030] = 1;
    path[5990] = 1;
    path[6010] = 1;
    path[7000] = 1;
    
    
    cin >> a >> b;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        path[temp] = 1;
    }
    foo(0);
    cout << t;
}
