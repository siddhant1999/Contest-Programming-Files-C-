//
//  main.cpp
//  Bombing Revised
//
//  Created by Siddhant Jain on 2/11/2014.
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

using namespace std;
int dis = 0;

//char roads[256][256]; //
vector<vector<bool> > roads(256, vector<bool>(256, false));
vector<bool> visited(256, 0);
bool alive;

// standard DFS algorithm
void visit(char curnode){
    if (visited[curnode] == true) {
        return;
    }
    
    visited[curnode] = true;
    for (char j = 'A'; j <= 'Z'; j++) {
        if ( roads[curnode][j] == true) {
            visit( j );
        }
    }

}

int main(void)
{
    char in1, in2;
    while (1) {
        cin >> in1 >> in2;
		if (in1 == '*')
			break;
		else {
			roads[in1][in2] = 1;
            roads[in2][in1] = 1;
		}
    }
	for (char j = 'A'; j <= 'Z'; j++) {
        for (char i = j + 1; i <= 'Z'; i++) {
            // try every possible road (i,j)
            if ( roads[i][j] == true ) {
                
                // remove road (i,j)
                roads[i][j] = false;
                roads[j][i] = false;
                
                // run visit('A')
                fill( visited.begin(), visited.end(), false);
                visit('A');
                //  check if 'B' was visited at some point
                if (visited['B'] == false) {
                    cout << i << j << endl;
                    dis++;
                }
                // restore road (i,j)
                roads[i][j] = true;
                roads[j][i] = true;
            }
    }
	}
	cout << "There are "<< dis << " disconnecting roads.";
}
