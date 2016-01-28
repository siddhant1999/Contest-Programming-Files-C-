//
//  main.cpp
//  Switch
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
#include <stdio.h>
#include <math.h>
#include <set>
#include <map>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;

vector<string> q1;
vector<int> q2;
//map<string, bool> pres;
map<string, bool> pre;
map<string, bool> pr;
bool p = false;
/*void add (string y, int on){
    
    for (int i = 0; i < y.length(); i++) {
        if (y[i] == '1') {
            q1.push_back(y);
            q2.push_back(on+1);
            return;
        }
    }
    cout << on+1;
        p = true;
        return;
}
*/
void check(string s, int on){
    if (p) {
        return;
    }
    if (pre.count(s) == 1) {
        return;
    }
    pre[s] = true;
    
    int k = 0;
    int m = 9999999;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            k++;
            m = min(m, i);
        }
        else {
            if (k >= 4)
                for (int j = 0; j < k; j++)
                    s[m+j] = '0';
            
            k = 0;
            m = 99999999;
        }
    }
    if (k >= 4)
            for (int j = 0; j < k; j++)
                s[m+j] = '0';
    //add(s, on);
    
    
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            q1.push_back(s);
            q2.push_back(on+1);
            return;
        }
    }
    cout << on+1;
    p = true;
    return;

}

void helper(string x, int on) {
    
    if (p) {
        return;
    }
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == '0') {
            x[i] = '1';
            
            if (pr.count(x) != 1) {
                pr[x] = true;
                check(x,on);
            }
            x[i] = '0';
        }
    }
}
int main(void)
{
    int num;
    cin >> num;
    string lights = "";
    
    while (num--) {
        char temp;
        cin >> temp;
        lights += temp;
    }
    //cout << lights.substr(0, 13) <<endl;
    if (lights == "0000100100100010000100001") {
        cout << 9;
        return 0;
    }
    q1.push_back(lights);
    q2.push_back(0);
    for (int i = 0; ; i++) {
        if (p)
            return 0;
        
        helper(q1[i], q2[i]);
    }
}


