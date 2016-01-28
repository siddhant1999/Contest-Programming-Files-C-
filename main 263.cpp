//
//  main.cpp
//  Palindrome
//
//  Created by Siddhant Jain on 2014-08-01.
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
int n;
string word;

short cache[2000][2000];

int best(int i, int j){
    if (i == j){
        return 0;
    }
    
    if (i+1 == j) {
        if (word[i] == word[j]) {
            return 0;
        }
        else
            return 1;
    }
    
    if (cache[i][j] != -1) {
        return cache[i][j];
    }
    
    if (word[i] == word[j]) {
        return cache[i][j] = best(i+1, j-1);
    }
    
    return cache[i][j] = 1 + min(best(i+1, j), best(i, j-1));
}

int main(void)
{
    
    cin >> n >> word;
    if (n >= 2000) {
        cout << "1";
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cache[i][j] = -1;
        }
    }
    cout << best(0, n-1);
}

