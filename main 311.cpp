//
//  main.cpp
//  9966
//
//  Created by Siddhant Jain on 2/9/2014.
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
map<char, char> refer;

int check(int i){
   // int ori = i;
    vector<char> digits;
    while (i > 0) {
        digits.push_back(i%10);
        i /= 10;
    }
    for (int j = 0; j < digits.size(); j++) {
        if ( refer.count(digits[j])==0 ) return 0;
        
            if (refer[digits[j]] != digits[digits.size() - j - 1]) {
                return 0;
            }
    }
    //cout << ori << endl;
    return 1;
    
}

int main(void)
{
    refer[ 1] = 1;
    refer[ 8] = 8;
    refer[ 9] = 6;
    refer[ 6] = 9;
    refer[ 0] = 0;
    
    
    int s, t, count = 0;
    cin >> s >> t;
    for (int i = s; i <= t; i++) {
        count += check(i);
    }
    cout << count;
}