//
//  main.cpp
//  Soccer
//
//  Created by Siddhant Jain on 1/22/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

int j, comb = 0;

void recurse(int player, int maxjersey){
   // cout << player << " " << maxjersey << endl;
    if (player == 4) {
        comb++;
        return;
    }
    
    for (int i = maxjersey + 1; i < j; i++) {
        recurse(player+1, i);
        
    }
}

int main(void)
{
    cin >> j;
    recurse(1, 0);
   /* for (int x = 1; x < j; x++) {
        for (int y= x + 1; y < j; y++) {
            for (int z=y+1; z < j; z++) {
                comb++;
                //cout << x << "," << y << "," << z << "     Comb: "<< comb <<endl;
            }
        }
    }*/
    cout << comb;
}