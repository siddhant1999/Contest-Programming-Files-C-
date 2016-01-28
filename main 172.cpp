//
//  main.cpp
//  The Geneva Confection
//
//  Created by Siddhant Jain on 2015-02-14.
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

vc mount, lake, branch;

char check(void){
    while (mount.size()) {
        if (mount[mount.size()-1] == lake[lake.size()-1]+1) {
            lake.push_back(mount[mount.size()-1]);
            mount.pop_back();
        }
        else if (branch.size()){
            if (branch[branch.size()-1] == lake[lake.size()-1]+1) {
                lake.push_back(branch[branch.size()-1]);
                branch.pop_back();
            }
            else if (branch[branch.size()-1] < mount[mount.size()-1]){
                return 'N';
            }
            else if (branch[branch.size()-1] > mount[mount.size()-1]){
                branch.push_back(mount[mount.size()-1]);
                mount.pop_back();
            }
        }
        else {
            branch.push_back(mount[mount.size()-1]);
            mount.pop_back();
        }
    }
    return 'Y';
}
int main(void)
{
    int test;
    cin >> test;
    while (test--) {
        int num;
        cin >> num;
        for (int i = 0; i < num; i++) {
            int temp;
            cin >> temp;
            mount.push_back(temp);
        }
        lake.push_back(0);
        cout << check() << endl;
        lake.clear();
        mount.clear();
        branch.clear();
    }
}
