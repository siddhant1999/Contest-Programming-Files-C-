//
//  main.cpp
//  Setting
//
//  Created by Siddhant Jain on 2015-02-16.
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

vc store;
int main(void)
{
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        bool p = false;
        for (int i =0; i < store.size(); i++) {
            if (store[i] == temp) {
                p  =true;
                break;
            }
        }
        if (!p) {
            store.push_back(temp);
        }
    }
    cout << store.size();
    
}
