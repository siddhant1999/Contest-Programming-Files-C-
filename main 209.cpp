//
//  main.cpp
//  fb1
//
//  Created by Siddhant Jain on 2015-01-17.
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

vector<bool> vec(10000001, true);
vector<int> cache(10000001, 0);

void primes(void){
    for (int i = 2; i*i <= vec.size(); i++) {
        if (vec[i]) {
            for (int j = i*i; j <= 10000000; j += i) {
                vec[j] = false;
            }
        }
    }
    /*for (int k = 0; k < vec.size(); k++) {
        cout << k << " : " << vec[k] << endl;
    }*/
}


int fun(int a, int b, int k){
    int tot = 0;
    for (int i = a; i <= b; i++) {
        if (cache[i] == 0) {
            int counter = 0;
            if (vec[i]) counter++;
            for (int j = 2; j*j <= i; j++) {
                if (i%j == 0) {
                    if (vec[i/j] && i/j != j) counter++;
                    if (vec[j]) counter++;
                }
            }
            cache[i] = counter;
        }
        if (cache[i] == k) {
            tot++;
        }
        
    }
    return tot;
}

int main(void)
{
    time_t start = time(0);
    
    primes();
    fun(2, 10000000, 0);
    cout << "***************************" << endl;
    double seconds_since_start = difftime( time(0), start);
    cout << seconds_since_start;
    int num;
    cin >> num;
    
    for (int q = 1; q <= num; q++) {
        int a,b,k;
        cin >> a >> b >> k;
        cout <<"Case #" << q << ": "<< fun(a,b,k) << endl;
    }
}

