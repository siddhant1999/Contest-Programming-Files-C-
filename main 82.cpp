//
//  main.cpp
//  Lonely Integer
//
//  Created by Siddhant Jain on 2014-07-19.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int lonelyinteger(vector<int> nums) {
    vector<int> freq(101,0);
    
    for (int i =0; i < nums.size(); i++) {
        freq[nums[i]]++;
    }
    for (int j = 0; j < 101; j++) {
        if (freq[j] == 1) {
            return j;
        }
    }
    return 0;
}
int main() {
    int res;
    
    int bigN;
    cin >> bigN;
    //cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> numbers;
    int curint;
    for(int _a_i=0; _a_i<bigN; _a_i++) {
        cin >> curint;
        numbers.push_back(curint);
    }
    
    res = lonelyinteger(numbers);
    cout << res;
    
    return 0;
}




