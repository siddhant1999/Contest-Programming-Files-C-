//
//  main.cpp
//  hack2
//
//  Created by Siddhant Jain on 2015-01-10.
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
int num,q1,q2,q3,cases,t1,t2,t3;
vector<int> w1,w2,w3;

bool recurse(int i1,int i2,int i3){
    if (i1 == 0 && i2 == 0 && i3 == 0) {
            return true;
    }
    int add = 0;
    for (int i = 0; i < w1.size(); i++) {
        if (w1[i] <= i1 && w2[i] <= i2 && w3[i] <= i3){
            add++;
            int a = w1[i];
            int b = w2[i];
            int c = w3[i];
            w1[i] = 999999999;
            w2[i] = 999999999;
            w3[i] = 999999999;
            if(recurse(i1-a, i2-b, i3-c)) return true;
            w1[i] = a;
            w2[i] = b;
            w3[i] = c;
        }
    }
    
    return false;
}

int main(void)
{
    
    cin >> num;
    
    for(int i = 1; i <= num; i++) {
        
        cin >> q1 >> q2 >> q3;
        
        cin >> cases;
        while (cases--) {
            cin >> t1 >> t2 >> t3;
            w1.push_back(t1);
            w2.push_back(t2);
            w3.push_back(t3);
        }
        cout << "Case #" << i << ": ";
        if (recurse(q1,q2,q3))
            cout << "yes" << endl;
        
        else cout << "no" << endl;
        
        w1.clear();
        w2.clear();
        w3.clear();
    }
}
