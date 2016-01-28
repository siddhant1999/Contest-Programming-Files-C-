//
//  main.cpp
//  Junior 2013 Question 4
//
//  Created by Siddhant Jain on 10/15/13.
//  Copyright (c) 2013 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

int main(void)
{

	/*ifstream myinputfoo("chore.in");
	ofstream outfoo("chore.out");*/
	int limit, num,number;
	cin >> limit >> num;
	vector<int> chore;
	for (int i = 0 ; i < num;i++)
	{
    	cin >> number;
    	chore.push_back(number);
	}
	sort(chore.begin(),chore.end());
    int sum = 0;
    int i = 0;
	for (i = 0 ; i < chore.size() && sum <= limit;i++)
        sum += chore[i];
    cout << ""<<endl;
    cout << "Answer is: " << i << endl;
}

