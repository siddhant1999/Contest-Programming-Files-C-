//
//  main.cpp
//  Coding Spree
//
//  Created by Siddhant Jain on 2015-11-13.
//  Copyright © 2015 Siddhant Jain. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <fstream>
#include <set>
#include <map>
#include <bitset>
#include <ctime>
using namespace std;

int matrix[2000][2000] = {0};

int knapsack(int index, int size, int weights[],int values[]){
    int take,dontTake;
    
    take = dontTake = 0;
    
    if (matrix[index][size]!=0)
        return matrix[index][size];
    
    if (index==0){
        if (weights[0]<=size){
            matrix[index][size] = values[0];
            return values[0];
        }
        else{
            matrix[index][size] = 0;
            return 0;
        }
    }
    
    if (weights[index]<=size)
        take = values[index] + knapsack(index-1, size-weights[index], weights, values);
    
    dontTake = knapsack(index-1, size, weights, values);
    
    matrix[index][size] = max (take, dontTake);
    
    return matrix[index][size];
    
}

int main(){
    int nItems = 4;
    cin >> nItems;
    int knapsackSize = 10;
    cin >> knapsackSize;
    int weights[nItems];
    int values[nItems];
    for (int i = 0; i < nItems; i++) {
        int a, b;
        cin >> a >> b;
        weights[i] = b;
        values[i] = a;
    }
    
    cout << knapsack(nItems-1,knapsackSize,weights,values);
    return 0;
}
