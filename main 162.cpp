//
//  main.cpp
//  Buildings
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

vc q1,q2;
vector<vector<bool> > board;

int recurse(int start, int end, int count) {
   // cout << q1[start] << " " << q2[start] << " " << count << endl;
    if (end == q1.size()) {
        return count;
    }
    if (q1[start] == q1[start+1]) {
        for (int i = q2[start]; i != q2[end];) {
            if (board[q1[start]][i] == true) {
                count++;
            }
            if (q2[start] > q2[end]) {
                i--;
            }else i++;

        }
        if (board[q1[start]][q2[end]] == true) {
            count++;
        }
        return recurse(end, end+1, count);
    }
    if (q2[start] == q2[start+1]) {
        
        for (int i = q1[start]; i != q1[end];) {
            if (board[i][q2[start]] == true) {
                count++;
            }if (q1[start] > q1[end]) {
                i--;
            }else i++;
        }
        if (board[q1[end]][q2[start]] == true) {
            count++;
        }
        return recurse(end, end+1, count);
    }
    return 0;
}
int main(void)
{
    int num;
    cin >> num;
    int maxi = 0;
    for (int i = 0; i < num; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        q1.push_back(t1);
        q2.push_back(t2);
        maxi = max(t1, max(t2,maxi));
    }
    board = vector<vector<bool>> (100000, vector<bool>(100000, false));
    for (int i = 0; i < q1.size(); i++) {
        board[q1[i]][q2[i]] = true;
    }
    q1.clear();
    q2.clear();
    int t;
    cin >> t;
    int x,y;
    while (t--) {
        cin >> x >> y;
        q1.push_back(x);
        q2.push_back(y);
    }
    cout << recurse(0,1,0);
}
