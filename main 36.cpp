//
//  main.cpp
//  Icon Scaling
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
int k;
string triple(string str){
    string result = "";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < k; j++) {
            result += str[i];
        }
    }
    return result;
}
int main(void)
{
    string a = "*x*", b = " xx", c = "* *";
    int n = 0;
    cin >> k;
    while (n < k) {
        cout << triple(a) << endl;
        n++;
    }
    n = 0;
    while (n < k) {
        cout << triple(b) << endl;
        n++;
    }
    n = 0;
    while (n < k) {
        cout << triple(c) << endl;
        n++;
    }

}