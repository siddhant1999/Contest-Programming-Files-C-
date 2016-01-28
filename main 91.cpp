//
//  main.cpp
//  Artwork
//
//  Created by Siddhant Jain on 2014-03-18.
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

int main(void)
{
    int num;
    cin >> num;
    for (int i = 1; i <= num; i++) {
        int j = i;
        while (j--) {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = num; i >= 1; i--) {
        int j = i;
        while (j--) {
            cout << "*";
        }
        cout << endl;
    }
}