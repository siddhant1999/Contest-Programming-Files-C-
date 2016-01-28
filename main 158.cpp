//
//  main.cpp
//  Servicing
//
//  Created by Siddhant Jain on 2015-02-17.
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

vcc board;
int num, a;

int getbest(int ind, int count, vector<bool> done, vc used){
    bool c = true;
    for (int i = 1; i <= a; i++) {
        if (done[i]) {
            c = false;
            break;
        }
    }
    if (c) {
        cout << "HI";
        return count;
    }
    for (int i = 0; i < board[ind].size(); i++) {
        cout << "P";
        done[i] = true;
    }
    int maxi = 999999999;
    for (int j = 1; j <= a; j++) {
        bool f = true;
        for (int i = 0; i < used.size(); i++) {
            if (j == used[i]) {
                f = false;
            }
        }
        if (f) {
            used.push_back(j);
            if (!done[j]) {
                done[j] = true;
                maxi = min(maxi, getbest(j, count+1, done, used));
                done[j] = false;
            } else maxi = min(maxi, getbest(j, count+1, done, used));
            used.pop_back();
        }
    }
    return maxi;
}

int main(void)
{
    
    cin >> a >> num;
    board = vcc (a+1);
    for (int i = 0; i < num; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        board[t1].push_back(t2);
        board[t2].push_back(t1);
    }
    vector<bool> done (a+1, false);
    vc used;
    int maxi = 999999999;
    
    for (int i = 1; i <= a; i++) {
        done[i] = true;
        used.push_back(i);
        maxi = min(maxi, getbest(i, 0, done, used));
        used.pop_back();
        done[i] = false;
    }
    cout << maxi;
}
