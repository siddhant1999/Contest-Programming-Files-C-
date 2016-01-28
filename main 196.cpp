//
//  main.cpp
//  Hills
//
//  Created by Siddhant Jain on 2015-02-04.
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

int recurse(int i, int diff, int lowval){
    return 0;
}
int main(void)
{
    
    
    int num;
    cin >> num;
    
    int maxi = 0;
    int mini = 2147483647;
    while (num--) {
        int temp;
        cin >> temp;
        myvec.push_back(temp);
        maxi = max(maxi, temp);
        mini = min(mini, temp);
    }
    int curdiff = maxi - mini-17;
    if (curdiff <= 0) {
        cout << 0;
        return 0;
    }
    if (curdiff%2 == 0) {
        cout << ((curdiff*curdiff)/2);
    }
    else
        cout << (curdiff+1)*(curdiff + 1)/2;
}
