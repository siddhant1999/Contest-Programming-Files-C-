//
//  main.cpp
//  Div 11
//
//  Created by Siddhant Jain on 2015-02-07.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vc;
typedef vector<vector<int> > vvc;

int main(void)
{
    
    
    int num;
    cin >> num;
    
    while (num--) {
        string n;
        cin >> n;
        int pp = 0;
        for (int i = 0; i < n.length()-1; i++) {
            if (n[i] == '0') {
                pp++;
            }
            else break;
        }
        n.erase(0, pp);
        vc foo;
        int u = 1;
        for (int i = 0; i < n.length(); i++){
            /*if (n[i] != '0') {
                u++;
            }*/
            if (u != 0) {
                foo.push_back(n[i]-'0');
            }
        }
        for (long i = foo.size()-1; i > 1; i--) {
            int y = foo[i];
            foo[i] = -2;
            for (long j = i-1; j > 0; j--) {
                if (foo[j]-y < 0) {
                    foo[j] = 10 + foo[j] -y;
                
                    //foo[i-1] -= 1;
                    if (foo[j-1]-(foo[j]-y) > 0) {
                        break;
                    }
                }
                else {
                foo[j] -= y;
                break;
                }
            }
            
            for (int k = 0; k < foo.size(); k++)
                if (foo[k] != -2)
                    cout << foo[k];
                
            
            cout << endl;
        }
        int qw;
        if (foo[1] == -2) {
            qw = 1;
        }
        else qw =foo[0] * 10 + foo[1];
        
        if((qw)%11== 0)
            cout << "The number "<< n << " is divisible by 11."<< endl;
        else  cout << "The number "<< n << " is not divisible by 11."<< endl;
    }
}
