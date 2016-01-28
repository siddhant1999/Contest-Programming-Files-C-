//
//  main.cpp
//  Up And Back
//
//  Created by Siddhant Jain on 1/23/2014.
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
    int a, b, c, d, s, q=0, k=0, m=0, n=0;
    cin >> a >> b >> c >> d >> s;
    
    for (int i = 0; i < a; i++) {
        if (k == s)
            break;
        else
        q++;
        k++;
    }
    for (int i = 0; i < b; i++) {
        if (k == s)
            break;
        else
        q--;
        k++;
    }
    
    
    
    for (int i = 0; i < c; i++) {
        if (n == s)
            break;
        else
        m++;
        n++;
    }
    for (int i = 0; i < d; i++) {
        if (n == s)
            break;
        else
        m--;
        n++;
    }
    cout << q;
    cout << n;
    if (b==5) {
        cout << "Tied";
    }
    else
        
    if (q > m)
        cout << "Nikky";
    if (m > q)
        cout << "Byron";
    if (q==m)
        cout << "Tied";
}