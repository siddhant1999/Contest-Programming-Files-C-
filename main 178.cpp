//
//  main.cpp
//  s1
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

vc sal (27, -1);
vector<int> ing;
vc si;
int main(void)
{
    int test;
    cin >> test;
    sal[1] = 1;
    sal[2] = 1;
    sal[3] = 1;
    sal[5] = 1;
    sal[7] = 1;
    sal[12] = 1;
    sal[15] = 1;
    sal[18] = 1;
    while (test--) {
        int temp;
        cin >> temp;
        for(int i =0; i< temp;i++) {
            char t;
            cin >> t;
            int k = t-'A'+1;
            ing.push_back(k);
            //cout << k << "---";
        }
        for(int i =0; i< temp;i++) {
            int t;
            cin >> t;
            si.push_back(t);
        }
    

        bool g  = false;
    for (long i = 0; i < 47; i++) {
        if (g) {
            break;
        }
        unsigned int p = 0;
        for (unsigned int k = 0; k < ing.size(); k++) {
            if (g) {
                break;
            }
            if (sal[ing[k]] == 1 ) {
                //cout << ing[k] <<endl;
                p++;
            }
        }
        if (p == ing.size()) {
            //cout << ing.size();
            cout << i << endl <<endl;
            g = true;
        }
        for (unsigned int j = 0; j < ing.size(); j++) {
            ing[j] += si[j];
            //cout << "fdsfdsf fsdfsd " << ing[j] <<endl;
                ing[j] = (ing[j]-1)%26;
                ing[j]++;
            //cout << ing[j] <<endl;
            
            
        }
        
    }
        if (!g) {
            cout << -1 << endl;
        }
        si.clear();
        ing.clear();
        sal.clear();
    }
}


