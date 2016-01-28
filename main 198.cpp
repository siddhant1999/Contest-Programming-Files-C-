//
//  main.cpp
//  Gifts
//
//  Created by Siddhant Jain on 2015-02-03.
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
int n, b;

vc p;
vc s;
vc t;
vc c;
vc l;

int recurse(int i, int sum){
    if ((t[i] + sum) <= b) {
        <#statements#>
    }
}

int main(void)
{
    
    
  
    cin >> n >> b;
    
    while (n--) {
        int temp, cost;
        cin >> temp >> cost;
        p.push_back(temp);
        s.push_back(cost);
        t.push_back(temp + cost);
        c.push_back(temp/2 + cost);
        l.push_back(temp/2);
    }
    
}