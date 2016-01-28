//
//  main.cpp
//  Chores
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
typedef vector<int> vc;
typedef vector<vector<int> > vvc;

vc myvec;
int main(void)
{
    
    int lim;
    cin >> lim;
    int num;
    cin >> num;
    
    while (num--) {
        int temp;
        cin >> temp;
        myvec.push_back(temp);
    }
    sort(myvec.begin(), myvec.end());
    int tot = 0;
    int n = 0;
    for (int i = 0; i < myvec.size(); i++) {
        if (tot+myvec[i] <= lim) {
            tot += myvec[i];
            n++;
        }
    }
    cout << n;
}
