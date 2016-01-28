//
//  main.cpp
//  USACO 4
//
//  Created by Siddhant Jain on 2014-12-13.
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
vector<int> cows;
int n,a,b;
map<int, bool> spot;
int spotted = 0;

void manual(int x, int y, int co1, int co2){
    int asd = y - x;
    if (asd%2 == 1) {
        if(x + (asd-1)/2 >= a)
            spotted += (x + (asd-1)/2 - a + 1) * spot[co1];
        if(y - (asd-1)/2 <= b)
            spotted += (b - (y - (asd-1)/2) + 1) * spot[co2];
    }
    else {
        if(x + (asd)/2  -1 >= a)
            spotted += (x + (asd)/2 - a) * spot[co1];
        if(y - (asd)/2 +1 <= b)
            spotted += (b - (y - (asd)/2)) * spot[co2];
    }
}

int binary(int low, long high, int k)
{
    int mid;
    while ( low <= high )
    {
        mid = (low + high) / 2;
        if ( cows[mid] == k ) return mid;
        if (low==high) return low;
        if ( cows[mid] < k )
            low = mid + 1;
        else
            high = mid;
    }
    return low;
    
}

void quan(int x, int y, int co1, int co2){
    if (x < a || y > b) {
        manual(x,y,co1,co2);
        return;
    }
    int asd = y - x;
    if (asd%2 == 1) {
        spotted += ((asd+1)/2 * spot[co1]) + ((asd+1)/2 * spot[co2]);
    }
    else {
        spotted += ((asd)/2 * spot[co1]) + ((asd)/2 * spot[co2]);
        if (spot[co1] || spot[co2]) {
            spotted++;
        }
    }
}

int main(void)
{
   freopen("learning.in", "r", stdin);
   freopen("learning.out", "w", stdout);
    
    
    cin >> n >> a >> b;
    if (a == b) {
        cout << 0;
        return 0;
    }
    while (n--) {
        string temp;
        int num;
        cin >> temp >> num;
        cows.push_back(num);
        
        if (temp == "NS")
            spot[num] = false;
        
        if (temp == "S")
            spot[num] = true;
    }
    sort(cows.begin(), cows.end());
    
    int ax = binary(0, cows.size()-1, a);//lower bound
    if (ax == cows.size() -1){// a is lower than this index
        if(a > cows[cows.size()-1]){
            if (spot[cows[cows.size()-1]]) {
                cout << b-a+1;
                return 0;
            }
            else {
                cout << 0;
                return 0;
            }
        }
    }
    int bx = binary(0, cows.size()-1, b);//upper bound
    if (bx == 0){// a is lower than this index
        if(b < cows[0]){
            if (spot[cows[0]]) {
                cout << b-a+1;
                return 0;
            }
            else {
                cout << 0;
                return 0;
            }
        }
    }
    if (a < cows[ax]) {
        if(ax)
            ax--;
    }
    if (b < cows[bx]) {
        if(bx < cows.size()-1)
            bx++;
    }
    //take care of outside
    
    if(a < cows[0]){
        if (spot[cows[0]]) {
            spotted += cows[0] - a;
        }
    }
    if(b > cows[cows.size()-1]){
        if (spot[cows[cows.size()-1]]) {
            spotted += b - cows[cows.size()-1];
        }
    }
        
    for (int i  = ax; i <= bx; i++) {
        quan(cows[i], cows[i+1], i, i+1);
    }
    for (int i  = 0; i < cows.size(); i++) {
       // cout << spot[cows[i]] << endl;
    }
    cout << spotted;
}

/*3 1 1
 S 10
 NS 4
 S 1
 */

