//
//  main.cpp
//  Office
//
//  Created by Siddhant Jain on 1/20/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int begin, end;
    cin >> begin >> end;
    
    cout << "All positions change in year " << begin << endl;
    while( begin + 60 <= end) {
        begin += 60;
        cout << "All positions change in year " << begin << endl;
        }
}