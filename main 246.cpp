//
//  main.cpp
//  Digits
//
//  Created by Siddhant Jain on 2014-10-20.
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
vector<int> vecb2;
vector<int> vecb3;

int func(){
    string base2, base3;
    cin >> base2 >> base3;
    //create functions for the calculation of base 2 and 3
    int sum = 0;
    
    vector<int> cur2 = vecb2;
    vector<int> cur3 = vecb3;
    
    for (double n = base2.size() - 1; n >= 0; n--) {
        sum = base2[n] - '0';
        vecb2.push_back(sum);
        cur2.push_back(sum);
        
    }
    for (double n = base3.size() - 1; n >= 0; n--) {
        sum = base3[n] - '0';
        vecb3.push_back(sum);
        cur3.push_back(sum);
    }
    
    //cout << cur2[0] << cur2[1]<< cur2[2];
    //cursum += vecb2[i] * pow(2, i);
    
    int total2 = 0;
    int total3 = 0;
    
    //Create vectors that you will edit
    for (int num = 0; num < vecb2.size(); num++)
        total2 += vecb2[num] * pow(2, num);
    
    for (int number = 0; number < vecb3.size(); number++)
        total3 += vecb3[number] * pow(3, number);
    
    //cout << total2 << " " << total3 << endl;
    // Remember to reinitialize the cur vector
    int cursum = 0;
    for (int i = 0; i < vecb2.size(); i++) {
        if (vecb2[i] == 1)
            cur2[i] =0;
        else
            cur2[i] = 1;
        
        if (cur2[i] == 1)
            cursum = total2 + (pow(2, i) * cur2[i]);
        else
            cursum = total2 - (pow(2, i));
        
        //cout << "2: " << cursum << endl;
        int cursum3 = 0;
        for (int j = 0; j < vecb3.size(); j++) {
            for (int k = 0; k <= 2; k++) {
                
                if (vecb3[j] != k) {
                    cursum3 = 0;
                    int temp = k;
                    if (temp > vecb3[j])
                        cursum3 = total3 + (pow(3, j) * (temp - vecb3[j]));
                    else
                        cursum3 = total3 - (pow(3, j) * (vecb3[j] -temp));
                //cout << "3: " << "j " << j<< "k "<<k <<" " << cursum3 << endl;
                    if (cursum == cursum3)
                        return cursum3;
                    cursum3 = 0;
                }
            }
        }
        cursum = 0;
        
    }
    return 0;
}

int main(void)
{
    cout << func();
}

