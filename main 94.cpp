//
//  main.cpp
//  Median
//
//  Created by Siddhant Jain on 2014-03-13.
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

int main(void)
{
    int num;
    cin >> num;
    vector<double> store;
    
    while (num--) {
        double temo;
        cin >> temo;
        store.push_back(temo);
    }
    sort(store.begin(), store.end());
    
    if (store.size()%2 == 0) {
        double lon = (store[store.size() / 2 - 1] + store[store.size() / 2]) / 2;
        cout << "The median on the test is " <<lon;
    }
    if (store.size()%2 == 1)
        cout << "The median on the test is " << store[(store.size() - 1) / 2];
}