//
//  main.cpp
//  Sorting
//
//  Created by Siddhant Jain on 2014-03-12.
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
    int num, temp;
    vector<int> myvec;
    cin >> num;
    
    while (num--) {
        cin >> temp;
        myvec.push_back(temp);
    }
    sort(myvec.begin(), myvec.end());
    for (int i = 0; i < myvec.size(); i++) {
        cout << myvec[i] << endl;
    }
}