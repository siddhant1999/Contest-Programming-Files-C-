//
//  main.cpp
//  j3
//
//  Created by Siddhant Jain on 2/25/2014.
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
    int a, d;
    int ascore = 100, dscore = 100;
    while (num--) {
        cin >> a >> d;
        
        if (a > d)
            dscore = dscore - a;
        if (a < d)
            ascore = ascore - d;
    }
    cout << ascore << endl;
    cout << dscore;
}