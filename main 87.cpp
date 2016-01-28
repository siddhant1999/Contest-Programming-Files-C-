//
//  main.cpp
//  Typing1
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
    num++;
    while (num--) {
    char cot[81];
    cin.getline(cot, 81);
    string str = cot;
    
    int sum = 0;
    for (int i = 0; i < str.length(); i++) {
        if (cot[i] != ' ') {
            char cur = cot[i];
            int curint = cur;
            sum += curint;
        }
    }
    if (str.length() > 0) {
        
    if (sum == 2847)
        cout << "OK." << endl;
        
    if (sum != 2847)
        cout << "Nope." << endl;
    }
    }
}