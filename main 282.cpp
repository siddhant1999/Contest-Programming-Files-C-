//
//  main.cpp
//  Middle
//
//  Created by Siddhant Jain on 1/21/2014.
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
    vector<int> num;
    int input;
    cin >> input;
    num.push_back(input);
    cin >> input;
    num.push_back(input);
    cin >> input;
    num.push_back(input);
    
    sort(num.begin(), num.end());
    cout << num[1] << endl;
}