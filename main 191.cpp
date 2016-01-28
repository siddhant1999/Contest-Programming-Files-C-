//
//  main.cpp
//  Simple Encryption
//
//  Created by Siddhant Jain on 2015-02-07.
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
typedef vector<int> vc;
typedef vector<vector<int> > vvc;

int main(void)
{
    
    
    string code, words;
    getline(cin, code);
    getline(cin, words);
    for (int i = 0; i < words.length(); i++) {
        if (words[i] < 'A' || words[i] > 'Z') {
            words.erase(i,1);
            i--;
        }
    }
    long s = code.length();
    for (int i =0; i < words.length(); i++) {
        words[i] = (code[(i%s)]%65 + words[i]);
        if (words[i] > 'Z') {
            words[i] -= 26;
        }
        cout << words[i];
    }
}
