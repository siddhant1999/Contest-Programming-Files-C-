//
//  main.cpp
//  Hacking
//
//  Created by Siddhant Jain on 2015-02-08.
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
    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = 'a'; b <= 'z'; b++) {
            for (char c = 'a'; c <= 'z'; c++) {
                for (char d = 'a'; d <= 'z'; d++) {
                    for (char e = 'a'; e <= 'z'; e++) {
                        for (char f = 'a'; f <= 'z'; f++) {
                            cout << a << b << c << d << e << f <<endl;
                        }
                    }
                }
            }
        }
    }
}

