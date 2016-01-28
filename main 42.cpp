//
//  main.cpp
//  j5
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
map<string, string> pairs;
map<string, int> number;
vector<string> vec1;
vector<string> vec2;

int main(void)
{
    int kids;
    cin >> kids;
    for (int i = 0; i < kids; i++) {
        string temp;
        cin >> temp;
        vec1.push_back(temp);
    }
    for (int j = 0; j < kids; j++) {
        string temp;
        cin >> temp;
        vec2.push_back(temp);
    }
    for (int i = 0; i < kids; i++) {
        pairs[ vec1[i] ] = vec2[i];
        
    }
    
    for (int i = 0; i < kids; i++) {
        if (vec1[i] != pairs[pairs[vec1[i]]] || vec1[i] == vec2[i]) {
                cout << "bad";
                return 0;
        }
    }
    for (int i = 0; i < vec1.size(); i++) {
        if (vec1[i] == vec2[i]) {
            //cout << "bad";
            return 0;
        }
    }
    cout << "good";
}