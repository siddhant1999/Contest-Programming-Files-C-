//
//  main.cpp
//  Message Relay
//
//  Created by Siddhant Jain on 2014-11-08.
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

bool floodfill(int x, int kk){
    //for (int i = 1; i < cows.size(); i++)
        //cout << cows[i] << endl;
    //cout << endl << endl;
    //cout << x << endl;
    int cur = cows[x];
    if (cur == -1||cur == kk) {
        return true;
    }
    if (cur == 0) {
        return false;
    }
    cows[x] = kk;
    if(floodfill(cur, kk) == true){
        cows[x] = -1;
        return true;
    }
    return false;
}

int main(void)
{
    int num;
    cin >> num;
    cows.push_back(-1);
    while (num--) {
        int temp;
        cin >> temp;
        cows.push_back(temp);
    }
    // 1 indexed
    for (int i = 1; i < cows.size(); i++) {
        int kk =  i + 9000;
        floodfill(i, kk);
    }
    int count = 0;
    for (int i = 1; i < cows.size(); i++) {
        //cout << cows[i] << endl;
        
        if (cows[i] > 1000 || cows[i] == 0) {
            count++;
        }
    }
    cout << count;
}

