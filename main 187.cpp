//
//  main.cpp
//  Lights
//
//  Created by Siddhant Jain on 2015-02-07.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;

string s = "";
map<int, string> ds;

bool anyones(string t){
    for (int i = 0; i < t.length(); i++) {
        if (t[i] == '1') {
            return false;
        }
    }
    return true;
}

string foo(string s, int x, int y){
    for (int i = 0; i < y; i++) {
        s[i+x] = '0';
    }
    return s;
}

string check(string str, int n){
    
    int j = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '1') {
            j++;
        }
        else {
            if (j >= 4) {
                str = foo(str, i-j, j);
                if (anyones(str)) {
                    return n
                }
            }
            j = 0;
        }
    }
}

int best(string str){
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '0') {
            str[i] = '1';
            if (str == check(str)) {
                <#statements#>
            }
        }
    }
}

int main(void)
{
   
    int num;
    cin >> num;
    
    while (num--) {
        char temp;
        cin >> temp;
        s += temp;
    }
    cout << s;
}

