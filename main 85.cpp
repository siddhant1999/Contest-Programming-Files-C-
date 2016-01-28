//
//  main.cpp
//  Dinner for 5
//
//  Created by Siddhant Jain on 2014-06-11.
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
    vector<int> score (5, 0);
    vector<int> holder (5, 0);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            int cur;
            cin >> cur;
            score[i] += cur;
            holder[i] += cur;
        }
    }
    
   sort(score.begin(), score.end());
    
    for (int i = 0; i < 5; i++) {
        if (holder[i] == score[4])
            cout << i + 1;
    }
    cout << " " << score[4];
}