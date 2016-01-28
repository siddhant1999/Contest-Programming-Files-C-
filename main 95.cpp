//
//  main.cpp
//  Typing
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
    vector<char> letters(0, 91);
    int num;
    cin >> num;
    while (num--) {
        for (int i = 0; i < 26; i++) {
            char temp;
            cin >> temp;
            letters[temp]++;
        }
    }
}