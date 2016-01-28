//
//  main.cpp
//  Moolympics
//
//  Created by Siddhant Jain on 2014-10-10.
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

vector<int> skill( 13, 0);
vector<bool> avail( 13, true );
int answer=1234456;

int comps=0;

void generate(int teamnum, int best, int worst){
    if(best-worst > answer)
        return;
    
    if (teamnum > 4) {
        int diff=best-worst;
        answer=min( answer, diff );
    }
    
    comps++;
    
    // form 1 team at a time
    for( int x = 1; x <= 12; x++)
        if (avail[x] == true)
            for (int y = x+1; y <= 12; y++)
                if (avail[y] == true)
                    for (int z = y+1; z <= 12; z++)
                        if(avail[z] == true){
                            avail[x] = false;
                            avail[y] = false;
                            avail[z] = false;
                            
                            int curskill;
                            curskill = skill[x] + skill[y] + skill[z];
                            
                            generate( teamnum+1, max(best, curskill), min(worst, curskill) );
                            
                            avail[x] = true;
                            avail[y] = true;
                            avail[z] = true;
                        }
}

int main(void)
{
    for (int i = 1; i <= 12; i++) {
        int temp;
        cin >> temp;
        skill[i] = temp;
    }
    
    generate(1, -30000001, 30000000);
    cout << answer << endl;
    cout << comps;
}

