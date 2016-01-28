//
//  main.cpp
//  Pascal
//
//  Created by Siddhant Jain on 12/14/2013.
//  Copyright (c) 2013 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

long double tri[50][50]={0};
int main(void)
{
	int n,i,j;
	cin >> n;
	tri[1][1] = 1;
    for (i=2; i < 50; i++) {
        for (j=1; j <=i; j++) {
            tri[i][j] = tri[i-1][j-1] + tri[i-1][j];
        }
    }
    
     for (j=1; j <= n; j++) {
         cout << tri[n][j] << " ";
     }
    cout<<endl;
}

