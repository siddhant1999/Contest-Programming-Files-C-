//
//  main.cpp
//  Candy Revised
//
//  Created by Siddhant Jain on 2014-10-16.
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

vector<int> list;

int a, b;

void recurse(map<int, int> quancal){
    int nextBig;
    
    for (double i = (list.size() - 1); i >= 0; i--) {
        if (quancal[list[i]] > 0) {
            nextBig = list[i];
            while (quancal[list[i]]--) {
                if (a <= b)
                    a += nextBig;
                else
                    b += nextBig;
            }
            
        }
        list.pop_back();
        
            if (i == 0)
                return;
                    
        }
}

int main(void)
{
    int num;
    cin >> num;
    map<int, int> calor;
    //cout << num << endl;
    while (num--) {
        int quan, calories;
        cin >> quan >> calories;
        //cout << quan << " " << calories << endl;
        list.push_back(calories);
        calor[calories] = quan;
    }
    sort(list.begin(), list.end());
    
    //cout << list[0] << " " << list[list.size() -1] << endl;
    recurse(calor);
    cout << abs(a-b);
    
}

