//
//  main.cpp
//  Global Warming
//
//  Created by Siddhant Jain on 2015-02-07.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

/*
 For example, if the following five-year averages are observed:
 
 3, 4, 6, 4, 5, 7, 5
 
 then we can calculate that the temperature changes first 1 tenth up, then 2 up, then 2 down, 1 up, 2 up, and 2 down. There is a cycle of changes of length three which covers all of the temperature differences: (+1, +2, −2). In other words, if we look at the differences starting at the first position, there is a cycle of length three of the form (+1, +2, −2) followed by another cycle of length three of exactly the same form.
 
 By way of another example, suppose the following average temperatures are observed:
 
 3, 4, 6, 7
 
 In this case, there is a difference of one up, two up, then one up. We would consider the shortest cycle to be length two in this case: the cycle (+1, +2). Notice that this cycle occurs once, followed by one truncated occurrence of exactly the same cycle.
 

*/
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
vc myvec;
vc diffs;

bool check(int x){
    for (int i = 0; i < diffs.size(); i++) {
        if(diffs[i%x] != diffs[i]){
            return false;
        }
    }
    return true;
}

void calc(void){
    int j;
    diffs.push_back(myvec[1] - myvec[0]);
        for (int i = 2; i < myvec.size(); i++) {
            j = myvec[i] - myvec[i-1];
            diffs.push_back(j);
        }
    
}
/*
 -2 2 3 4
 -2 2 3 4
 
 
 
*/

int main(void)
{
    while (1) {
        int num;
        cin >> num;
        //cout <<"fwfsdf" << num << endl;
        if (num == 0) {
            return 0;
        }
        while (num--) {
            int temp;
            cin >> temp;
            myvec.push_back(temp);
        }
        if (myvec.size() == 1 || myvec.size() == 2) {
            cout << "1" <<endl;
            
        }
        else {
        calc();
        for (int i = 1; i <= diffs.size(); i++) {
            if(check(i)){
                cout << i << endl;
                break;
            }
        }
        }
        myvec.clear();
        diffs.clear();
    }
}

