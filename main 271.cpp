//
//  main.cpp
//  Sumac Sequence
//
//  Created by Siddhant Jain on 2/2/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    vector<int> sumac(1000);
    int i = 2;
    cin >> sumac[0] >> sumac[1];
    
    for (; ; i++) {
        sumac[i] = sumac[i-2] - sumac[i-1];
        if (sumac[i-1] < sumac[i])
            break;
    }
    cout << i+1;
}