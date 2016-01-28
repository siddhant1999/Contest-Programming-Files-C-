//
//  main.cpp
//  Factor Solitaire
//
//  Created by Siddhant Jain on 2015-01-22.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

//
//  main.cpp
//  Template
//
//  Created by Siddhant Jain on 12/14/2013.
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
int num;

int recurse(int n, int c){
    if(n > num){
        return 1000000001;
    }
    if(n == num && c != 0){
        return c;
    }
    int mini = 1000000000;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            int kk = min(recurse(n+i, c+(n/i)), recurse(n + (n/i) , c + i));
            mini = min(kk, mini);
            // return the lowest cost, remember to code this in the base case
        }
    }
    return mini;
}

int main(void)
{
    cin >> num;
    
    cout << recurse(1, 0);
}

