//
//  main.cpp
//  Lazy
//
//  Created by Siddhant Jain on 2014-12-16.
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
vector<int> nline;
map<int, int> patch;
vector<bool> number (10000000, 0);
int n, m;

int search(int index){
    int cursum = 0;
    for (int i = index - m; i <= index+m; i++) {
        if(number[i])
            if(patch.count(i) == 1)
                cursum += patch[i];
            //cout << endl<< "     " << index << " :  " << patch[i] << endl;
        
    }
    return cursum;
}

int main(void)
{
    cin >> n >> m;
    int maxi = 0;
    int mini = 1000000000;
    while (n--) {
        int temp, index;
        cin >> temp >> index;
        nline.push_back(index);
        patch[index] = temp;
        maxi = max(temp, maxi);
        mini = min(temp, mini);
    }
    //number = vector<bool> (maxi + 10,false);
    for (int i = 0; i < nline.size(); i++) {
        number[nline[i]] = true;
    }
    int x = 0;
    for (int i = mini+1; i < maxi ; i++) {
        //cout << i << " " << search(i) << endl;
        x = max(x, search(i));
    }
    cout << x;
    
}

