//
//  main.cpp
//  Rotating Letters
//
//  Created by Siddhant Jain on 2014-03-11.
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

string rotate(string str){
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != 'I' && str[i] != 'O' && str[i] != 'S' && str[i] != 'H' && str[i] != 'Z' && str[i] != 'X' && str[i] != 'N') {
            return "NO";
        }
    }
    return "YES";
}
int main(void)
{
    string str;
    cin >> str;
    cout << rotate(str);
    return 0;
}