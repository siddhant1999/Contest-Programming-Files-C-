//
//  main.cpp
//  416
//
//  Created by Siddhant Jain on 2015-02-16.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

#include <iostream>

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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;

int main(void)
{
    string str;
    getline(cin, str);
    //cout << str;
    if (str.length() != 11 || str[3] != ' '
        ||  str[4] == ' '||  str[5] == ' ' ||  str[6] == ' ' ||  str[7] == ' '){
        cout << "invalid" <<endl;
        return 0;
    }
    string s = "";
    s += str[0];
    s += str[1];
    s += str[2];
    
    if (s == "416") {
        cout << "valuable" << endl;
        return 0;
    }
    if (s == "647" || s == "437") {
        cout << "valuableless" << endl;
        return 0;
    }
    cout << "invalid" << endl;
}