//
//  main.cpp
//  Candy Once Again
//
//  Created by Siddhant Jain on 2014-10-17.
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

vector<int> calor;
vector<int> quantity;
//divide the candies as if person 'a' will either get 0, 1, 2, ... available

int totalsum(int n) {
    
    if (n == calor.size())
        return 0;
    
    return calor[n] * quantity[n] + totalsum(n+1);
}

void seperate (int index, int sum){
    //set base cases for this
    //make another function for the computation of the difference
    //remember to 'retrun' if the diff is already too big to save time
    for (int i = 0; i <= quantity[index]; i++) {
        int curcal = calor[index] * i;
        sum+= curcal;
        seperate(index+1, sum);
        sum-= curcal;
    }
}

int main(void)
{
    int cases;
    cin >> cases;
    
    
    while (cases--) {
        int num, cal;
        cin >> num >> cal;
        calor.push_back(cal);
        quantity.push_back(num);
        
    }
    vector<int> team;
    totalsum(0);
    seperate(0, 0);
}

