//
//  main.cpp
//  Bowling N
//
//  Created by Siddhant Jain on 2015-02-10.
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
/*
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;

vc board,sums;
vc cache;
int best (int dex, int wid, int remain){
    cout << "si";
    /*if (remain == 0) {
        return 0;
    }
    if (dex+1 > board.size()-wid) {
        int s = 0;
        for (int j = dex; j < board.size(); j++) {
                s += board[j];
        }
            return s;
    }
    */
    /*
     0 4
     1 5
     2 2
     3 8
     4 4
     5 2
     6 8 * never executes this best();
     7 2
     8 7
     *//*
    int mx = 0;
    for (int i = dex; i+wid-1 < board.size(); i++) {
        if (i < dex + wid) {
            for (int j = 1; j < wid; j++) {
                int s = 0;
                for (int k = i; k<k+j; k++) {
                    s += board[k];
                }
                mx = max(mx, s + best(i+j, wid, remain-1));
            }
        }
        else if(i+1 > board.size() - wid){
                mx = max(mx, best(i+wid, wid, remain-1));
            }
        else mx = max(mx, sums[i+wid-1] + best(i+wid, wid, remain-1));
    }
    return mx;
    return 0;
}
int main(void)
{
    int num;
    cin >> num;
    
    while (num--) {
        int pins, balls, w, sum = 0;
        cin >> pins >> balls >> w;
        for (int i = 0; i < pins; i++) {
            int temp;
            cin >> temp;
            board.push_back(temp);
            
            sum += temp;
            if (i >= w) {
                sum -= board[i-w];
            }
            sums.push_back(sum);
        }
        for (int i = 0; i < sums.size(); i++) {
            cout << board[i] << " " << sums[i] << endl;
        }
        cout << best(0,w,balls) << endl;
        board.clear();
        sums.clear();
        cache.clear();
    }
}
*/


#define MAX 30002
int w,k;

int nums[MAX], sums[MAX];

vector<vector<int> > best (501, vector<int>(MAX, -1));

int get_best(int left, int i) // working on pins {1,2,3,...i-1, i, i+1, i+2, i+w-1 } with width w
{
    if (left == 0 || i <=  0) return 0;
    
    if (best[left][i] != -1) return best[left][i];
    //best[left][i] = 0;
    
    return best[left][i] = max( get_best(left-1, i-w) + sums[i+w-1] - sums[i-1]   , get_best(left, i - 1));
}
#define in cin
int t, n;
int main()
{
    //ifstream in("test.txt");
    in >> t;
    
    while (t--){
        best = vector<vector<int> > (501, vector<int>(MAX, -1));
        in >> n >> k >> w;
        for (int i = 1; i <= n; i++){
            in >> nums[i];
            sums[i] = sums[i - 1] + nums[i];
        }
        
        
        cout << (get_best(k, n - w + 1)) << endl;
        
        
    }
    
    
    
    //cin.get();
    return 0;
}
