//
//  main.cpp
//  ProperNumber
//
//  Created by Siddhant Jain on 12/17/2013.
//  Copyright (c) 2013 Siddhant Jain. All rights reserved.
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
int main(void)
{
    int num, i;
    int amount, sum=0;
	cin >> amount;
    
    while(amount--) {
        cin >> num;
        for (i=1; i< num; i++) {
            if (num%i == 0) {
                sum+= i;
                //cout << sum << endl;
            }
        }
        if (num==sum) {
            cout << num << " is a perfect number." << endl;
        }
        if (num<sum) {
            cout << num << " is an adundant number." << endl;
        }
        if (num>sum) {
            cout << num << " is a deficient number." << endl;
        }
        sum=0;
    }
}

