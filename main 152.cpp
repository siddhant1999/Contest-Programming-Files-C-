//
//  main.cpp
//  Miners
//
//  Created by Siddhant Jain on 2015-02-21.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <fstream>
#include <set>
#include <map>
#include <ctime>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;
vcc board;
vector<char> list;
int MAX = 999999999;

string check(string x) {
    string s = "";
    for (int i = int (x.length()-1); i >= 0 && i >= int (x.length()-2); i--)
        s += x[i];
    
    return s;
}

int foo(string x) {
    bool m = false, b = false, f = false;
    int c = 0;
    for (int i = int (x.length()-1); i >= 0 && i >= int (x.length()-3); i--) {
        char q = x[i];
        if (q == 'M' && !m) {
            c++;
            m = true;
        }
        else if (q == 'B' && !b) {
            c++;
            b = true;
        }
        else if (q == 'F' && !f) {
            c++;
            f = true;
        }
    }
    return c;
}

int mine(string a, string b, string s) {
    if (s.length() == 0) {
        return 0;
    }
    cout << a << " " << b << " " << s << endl;
    if (check(a) == check(b)) {
        a += s[0];
        s.erase(0,1);
        return foo(a) + mine(a, b, s);
    }
    
    int m = foo(a+s[0]);
    int h = m + mine(a + s[0], b ,s.substr(1, s.length()-1));
    int n = foo(b + s[0]);
    int k = n + mine(a, b + s[0] ,s.substr(1, s.length()-1));
    
    return max(h,k);
    
    
}

int main(void)
{
    int num;
    cin >> num;
    string s = "";
    for (int i = 0; i < num; i++) {
        char temp;
        cin >> temp;
        s += temp;
        list.push_back(temp);
    }
    string a = "", b = "";
    cout << mine(a,b,s);
}
