//
//  main.cpp
//  Unfriend
//
//  Created by Siddhant Jain on 2015-02-14.
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
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
vcc f (7);

int somename(int index){
    if (f[index].size() == 0) {
        return 2;
    }
    int sum = 1;
    for (int i = 0; i < f[index].size(); i++) {
        sum *= somename(f[index][i]);
    }
    return sum+1;
}
int main(void)
{
    int num;
    cin >> num;
    for (int i = 1; i < num; i++) {
        int temp;
        cin >> temp;
        f[temp-1].push_back(i-1);
    }
    cout << somename(num-1)-1;
}

