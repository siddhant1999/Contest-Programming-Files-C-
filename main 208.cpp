//
//  main.cpp
//  USACO 1 Cow Routing
//
//  Created by Siddhant Jain on 2015-01-18.
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
int a,b;
vector<int> vec;
int mini = 1000000000;


int main(void)
{
    
    cin >> a >> b;
    int num;
    cin >> num;
    
    while (num--) {
        int cost, n;
        cin >> cost >> n;
        
        int temp;
        int ith = -1;
        
        for (int i = 0; i < n; i++) {
            cin >> temp;
            if (temp == a)
                ith = 2;
            
            if (temp == b)
                if (ith != -1)
                    mini = min(cost, mini);
        }
    }
    if (mini == 1000000000) {
        cout << -1;
        return 0;
    }
    cout << mini;
}

