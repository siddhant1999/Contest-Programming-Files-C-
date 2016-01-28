//
//  main.cpp
//  Substrings Set Data
//
//  Created by Siddhant Jain on 2/2/2014.
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
using namespace std;

int main(void)
{
    int num;
    //cin >> num;
    //while (num--) {
    string s;
    cin >> s;
    //cout << '[' << s << ']' << endl;
    set<string> subs;
    
    for(int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            string temp = s.substr(i, j-i + 1);
            //cout << i << " "<< j << " " << temp << endl;
            subs.insert(temp);
        }
        
    }
    cout << subs.size() + 1;
    //}
}