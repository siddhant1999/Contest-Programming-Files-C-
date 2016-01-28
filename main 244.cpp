//
//  main.cpp
//  Candies Gregson
//
//  Created by Siddhant Jain on 2014-10-24.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

//
//  Candy Gregson.h
//
//
//  Created by Siddhant Jain on 2014-10-24.
//
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

int main(void){
    int size;
    cin >> size;
    int candies[size][2];
    
    int totalCandies = 0;
    int totalCalories = 0;
    
    for (int i = 0; i < size; i++)
    {
        cin >> candies[i][0];
        cin >> candies[i][1];
        totalCandies += candies[i][0];
        totalCalories += candies[i][0] * candies[i][1];
    }
    int MAX = totalCalories / 2;
    int min[MAX - 1];
    
    for (int i = 0; i <= MAX; i++)
        min[i] = 0;
    
    for (int i = 0; i < size; i++)
    {
        int cals = candies[i][1];
        for (int j = candies[i][0]; j > 0; j--)
        {
            for (int k = MAX; k > 0; k--)
            {
                if (cals <= k)
                {
                    min[k] = max(min[k], min[k - cals] + cals);
                }
            }
        }
    }
    cout << totalCalories - 2*min[MAX];
}