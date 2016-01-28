//
//  main.cpp
//  USACO 4 again
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

void quan (int i){
    /*if(i == 0 && a < cows[i])
        spotted += (cows[i] - a +1) * spot[i];
    if (i == cows.size()-1 && b > cows[i]) {
        spotted += (b - cows[i]+1) * spot[i];
    }*/
    int asd = cows[i+1] - cows[i];
    int dsa = cows[i] - cows[i-1];
    if (asd%2 == 1) {
        spotted += ((asd+1)/2) * spot[cows[i]];
    }
    if (dsa%2 == 1) {
        spotted += ((dsa-1)/2) * spot[cows[i]];
    }
    if (asd%2 == 0) {
        spotted += ((asd)/2) * spot[cows[i]];
        if(spot[cows[i]] || spot[cows[i+1]]) spotted++;
    }
    if (dsa%2 == 0) {
        spotted += ((dsa)/2 -1) * spot[cows[i]];
        if(spot[cows[i]] || spot[cows[i-1]]) spotted++;
    }
}

int main(void)
{
    freopen("learning.in", "r", stdin);
    freopen("learning.out", "w", stdout);
    
    
    cin >> n >> a >> b;
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
    for (int i = 1; i < cows.size()-1; i++) {
        quan(i);
    }
   if(a < cows[0])
        spotted += (cows[0] - a +1) * spot[cows[0]];
    if (b > cows[cows.size()-1]) {
        spotted += (b - cows[cows.size()]+1) * spot[cows[cows.size()-1]];
    }
    
    int asd = cows[1] - cows[0];
    int dsa = cows[cows.size()-1];
    if (asd%2 == 1) {
        spotted += ((asd+1)/2) * spot[cows[0]];
    }
    if (dsa%2 == 1) {
        spotted += ((dsa-1)/2) * spot[cows[cows.size()-1]];
    }
    if (asd%2 == 0) {
        spotted += ((asd)/2) * spot[cows[0]];
    }
    if (dsa%2 == 0) {
        spotted += ((dsa)/2 -1) * spot[cows[cows.size()-1]];
    }
    cout << spotted-1;
}