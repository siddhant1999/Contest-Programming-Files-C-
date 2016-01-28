//
//  main.cpp
//  idk
//
//  Created by Siddhant Jain on 2014-09-12.
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
int x, mincur = 123456789;
void recurse(int cur){
    if (cur > mincur) {
        return;
    }
    if (cur >= x && cur < mincur) {
        cout << cur << endl;
        mincur = cur;
        return;
    }
    for (int i = 2; i <= 9; i++) {
        recurse(cur * i);
    }
}

int main(void)
{
    
    cin >> x;
    
    recurse(1);
}

