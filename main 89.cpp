//
//  main.cpp
//  Big Bang
//
//  Created by Siddhant Jain on 2014-06-10.
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
    int k;
    cin >> k;
    
    string code;
    cin >> code;
    
    string word = "";
    for (int i=0; i < code.length(); i++) {
        char cha = code[i];
        int value = cha - (3 * (i + 1)) - k;
        //cout << cha<< " " << value << endl << endl;
        char val = value;
        if (val > 64) {
            cout << val;
        }
        if (val <= 64) {
            val = val + 26;
            cout << val;
        }
    }
}