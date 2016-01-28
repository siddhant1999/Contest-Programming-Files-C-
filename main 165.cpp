//
//  main.cpp
//  Marks
//
//  Created by Siddhant Jain on 2015-02-16.
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

int main(void)
{
    double cur, need, w;
    cin >> cur >> need >> w;
    if (cur >= need) {
        //cout <<
    }
    double a = cur * (1.0- (w/100.0));
    a = need - a;
    a /= w;
    if (a < 1.0) {
        cout << ceil(a *100);
        return 0;
    }
    a = cur * (1.0- (w/100.0));
    a += w;
    a =ceil(a);
    if (a >= need) {
        cout <<100;
    }
    else cout << "DROP THE COURSE" << endl;

}
