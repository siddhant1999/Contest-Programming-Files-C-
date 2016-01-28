//
//  main.cpp
//  Posts
//
//  Created by Siddhant Jain on 2015-02-11.
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

vector<vector<string>> str (2);
int lim, num;


void best(int index, string a, string b, vc s, vector<bool> limits){
    cout << "index: " << index << " a: " << a << " b: " << b<< " ";
    for (int w = 0; w < s.size(); w++) {
        cout << s[w];
    }
    cout << endl;
    if (s.size() < lim) {
    if (a == b) {
        cout << "*************************************" <<endl;
        bool p = true;
        for (int j = 0; j < num; j++) {
            if (limits[j] == false) {
                p = false;
                break;
            }
        }
        if (p == true) {
            cout << s.size() << endl;
            for (int q = 0; q < s.size(); q++) {
                cout << s[q] << endl;
            }
            return;
        }
       
    }
    int jkl = 0;
    for (int i = 0; i < min(a.length(), b.length()); i++) {
        if (a[i] != b[i]) {
            jkl++;
        }
    }
    if (jkl == 0) {
    for (int i = 0; i < num; i++) {
        if (b == "abaaaaaa") {
            cout << "yyyyyyyyyyyyyy" <<endl;
        }
        //cout << i <<endl;
        s.push_back(i);
        limits[i]= true;
        a+=str[0][i];
        b+=str[1][i];
        if (a == "abaaaaaab" || b == "abaaaaaab")
            cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
        best(i, a, b, s, limits);
        limits[i] = false;
        s.pop_back();
    }
    }}
        
}

int main(void)
{
    
    cin >> lim >> num;
    int u =2;
    int k = 0;
    vector<bool> limits;
    while (u--) {
        for (int i = 0; i < num; i++) {
            string temp;
            cin >> temp;
            str[k].push_back(temp);
            //str[k+2].push_back("0");
            limits.push_back(false);
        }
        k++;
    }
    
    cout << str[0][2] << " " << str[1][2] <<endl;
    for (int i =0; i < num; i++) {
        vc seq;
        seq.push_back(i);
        limits[i] = true;
        best(i, str[0][i], str[1][i], seq, limits);
        limits[i] = false;
        seq.pop_back();
    }
}

