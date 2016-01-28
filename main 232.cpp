//
//  main.cpp
//  Task KEMIJA
//
//  Created by Siddhant Jain on 2014-11-08.
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
    string str;
    getline(cin, str);
    char prv = 'a';
    for (int i = 0; i < str.length(); i++) {
        if (prv == 'a' || prv == 'e' || prv == 'i' || prv == 'o' || prv == 'u') {
            if (str[i] == 'p') {
                str.erase(i, 2);
            }
        }
        prv = str[i];
    }
    //str.erase(1,1);
    cout << str;
    
}

