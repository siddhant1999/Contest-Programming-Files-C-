//
//  main.cpp
//  Hay Stacks
//
//  Created by Siddhant Jain on 2014-10-13.
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

int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<int> occur (N+1, 0);
    
    while (K--) {
        int start, end;
        cin >> start >> end;
        
        for (int i = start; i <= end; i++)
            occur[i]++;
    }
    sort(occur.begin(), occur.end());
    //for (int i = 0; i < occur.size(); i++) {
      //  cout << " " << i << " : " << occur[i] << endl;
    //}
    cout << occur[N/2 + 1];
    
}

