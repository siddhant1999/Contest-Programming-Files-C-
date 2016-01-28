//
//  main.cpp
//  USACO 3
//
//  Created by Siddhant Jain on 2014-12-13.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <iostream>
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
vector<int> list;
vector<bool> grouped;
int counter = 0;

void keepchecking(long x){
    if (x == 0) {
        grouped[x] = false;
        return;
    }
    if (list[x-1] > list[x]) {
        grouped[x-1] = false;
        list[x-1] = list[x];
        keepchecking(x-1);
    }
    return;
}
void checkback(long x){
    if(x == 0){
        counter++;
        grouped[x] = false;
        return;
    }
    if(list[x-1] > list[x]){
        grouped[x-1] = false;
        list[x-1] = list[x];
        keepchecking(x-1);
    }
    counter++;
}

int main(void)
{
    
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    
    int num;
    cin >> num;
    
    while (num--) {
        int temp, real;
        cin >> temp;
        cin >> real;
        list.push_back(real);
        grouped.push_back(true);
    }
    checkback(list.size()-1);
    for (long i = list.size()-2; i >= 0; i --) {
        if (grouped[i]) {
            checkback(i);
        }
    }
    cout << counter;
}

