//
//  main.cpp
//  Bombing
//
//  Created by Siddhant Jain on 2/10/2014.
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
int hello = 0;
vector<vector<int> > paths(100);
vector<vector<int> > times(100);

/*void route(char start, char end){
	if (start == 'B' || end == 'B') {
		hello++;
		return;
	}
	for (char j = 'A'; j < paths[end].size(); j++) {
		if (paths[end][j] == 5 && j != start) {
			route(end, j);
			paths[end][j] = -1;
		}
	}
}*/

int main(void)
{
    char in1, in2;
    while (1) {
        cin >> in1 >> in2;
		if (in1 == '*')
			break;
		else {
			paths[in1].push_back(in2);
			paths[in1][in2] = 5;
			
			times[in1].push_back(in2);
			times[in1][in2] = 0;
			
			paths[in2].push_back(in1);
			paths[in2][in1] = 5;
			cout << "A at I: " << paths['A']['I'] << endl;
			times[in2].push_back(in1);
			times[in2][in1] = 0;
		}
    }
	cout << endl << endl;
	
	for (char ii = 'B'; ii < 'Z' + 1; ii++) {
		cout << ii << endl;
		if (paths['A'][ii] == 5) {
			cout << endl << ii << endl << endl;
			//route('A', i);
			paths['A'][ii] = -1;
		}
	}
	if (hello > 0) {
		cout << "HELLO WORLD" << endl;
	}
}






