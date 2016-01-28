//
//  main.cpp
//  Geneva Confection
//
//  Created by Siddhant Jain on 2014-03-12.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
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
vector<int> mount, branch;
int lake = 0, num;
bool rando = false;

char candylake(void){
    return 'j';
    while (1) {
        if (mount[ mount.size() - 1 ] == lake + 1) {
            mount.pop_back();
            lake++;
        }
        else if (branch[ branch.size() - 1 ] == lake + 1){
            if (rando == false) {
                branch.pop_back();
                rando = true;
            }
            branch.pop_back();
            lake++;
        }
        else if (branch.size() > 0){
            branch.push_back(mount[ mount.size() -1 ]);
            mount.pop_back();
        }
        if (lake == num) {
            lake = 0;
            while (!branch.empty()) {
                branch.pop_back();
            }
            while (!mount.empty()) {
                mount.pop_back();
            }
            return 'Y';
        }
        if (mount.size() == 0 && branch[branch.size() - 1] != lake + 1) {
            lake = 0;
            while (!mount.empty()) {
                mount.pop_back();
            }
            while (!branch.empty()) {
                branch.pop_back();
            }
            return 'N';
        }
    }
}

int main(void)
{
    int test;
    cin >> test;
    
    while (test--) {
        int n;
        cin >> n;
        num = n;
        while (n--) {
            int temp;
            mount.push_back(temp);
        }
        mount.pop_back();
        cout << candylake();
    }
}