//
//  main.cpp
//  Moo Sick
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

vc myvec;
vc total;
vc ival;

int main(void)
{
    int num;
    cin >> num;
    
    while (num--) {
        int temp;
        cin >> temp;
        total.push_back(temp);
    }
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        myvec.push_back(temp);
    }
    sort(myvec.begin(),myvec.end());
    int tot = 0;
    vc let(n);
    for (int i = 0; i < total.size(); i++) {
        for (int j = 0; j < n; j++) {
            let[j] = total[i+j];
        }
        sort(let.begin(), let.end());
        int y = let[0]-myvec[0];
        
        for (int k = 0; k < n; k++) {
            if(let[k]-myvec[k]!= y) break;
            if (k== n-1) {
                tot++;
                ival.push_back(i);
            }
        }
        
    }
    cout << tot << endl;
    
    for (int i = 0; i < ival.size(); i++) {
        cout << ival[i]+1 << endl;
    }
}