//
//  main.cpp
//  Magician
//
//  Created by Siddhant Jain on 2014-05-13.
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
vector<vector<int> > cards(5, vector<int>(5, -1));
vector<int> spec1(4);
vector<int> spec2(4);

int mynum(void){
    vector<int> mycard;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (spec1[i] == spec2[j]) {
                mycard.push_back(spec1[i]);
            }
        }
    }
    if (mycard.size() > 1){
        return -5;//magician cheated
    }
    else if (mycard.size() == 1){
        return mycard[0];
    }
    else {
        return -1;//volunteer cheated
    }
}

int main(void)
{
    int testcases;
    cin >> testcases;
    testcases++;
    int cases = 0;
    while (testcases--) {
        cases++;
        int row1;
        cin >> row1;
        row1 -= 1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int temp;
                cin >> temp;
                cards[i][j] = temp;
                if (i == row1) {
                    spec1[j] = temp;
                }
            }
        }
        
        int row2;
        cin >> row2;
        row2 -= 1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int temp;
                cin >> temp;
                cards[i][j] = temp;
                if (i == row2) {
                    spec2[j] = temp;
                }
            }
        }
        int ans = mynum();
        if (ans == -5) {
            cout << "Case #" << cases << ": " << "Bad magician!" << endl;
        }
        if (ans == -1) {
            cout << "Case #" << cases << ": " << "Volunteer cheated!" << endl;
        }
        if (ans > 0) {
            cout << "Case #" << cases << ": " << ans << endl;
        }
    }
}