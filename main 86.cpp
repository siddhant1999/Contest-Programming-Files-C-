//
//  main.cpp
//  Chocolate
//
//  Created by Siddhant Jain on 2014-06-11.
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
    
    while (num--) {
        int n1, n2;
        cin >> n1 >> n2;
        
        cout << (n1 * n2 - 1) << endl;
    }
}