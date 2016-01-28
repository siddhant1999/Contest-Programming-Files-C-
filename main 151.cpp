//
//  main.cpp
//  s3
//
//  Created by Siddhant Jain on 2015-02-18.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <set>
#include <map>
#include <ctime>
using namespace std;

vector<bool> board;
vector<int> list;
int MAX = 999999999;

int main(void)
{
    int lim, num;
    cin >> lim >> num;
    board = vector<bool> (lim+1, false);
    //cache = vc(num+1, -9);
    list.push_back(0);
    for (int i = 1; i <= num; i++) {
        int temp;
        cin >> temp;
        /*pii x;
        x.first = temp;
        x.second = i;
        pr.push_back(x);*/
        list.push_back(temp);
        
    }
    /*sort(pr.begin(), pr.end());
    for (long i = pr.size()-1; i > 0; i--) {
        if (pr[i].first > pr[i-1].first) {
            //cout <<pr[i].first << " " <<pr[i-1].first << endl;
            int mini = pr[i].second;
            
            cache[mini] = pr[i].first;
            
            
        }
    }*/
    int c = 0;
    int x = 1;
    while (x) {
        //cout << x;
        if (x >= list.size()-1) {
            cout <<  c;
            break;
        }
        long k;
        if(list[x]<  board.size()-1 ) k=list[x];
        else k = board.size() -1;
        for (long i = k; i >=1 && i < board.size(); i--) {
            if (!board[i]) {
                board[i] = true;
                x++;
                c++;
                break;
            }
            else if (i == 1){
                cout << c;
                return 0;
            }
        }
    }
        // cout << foo(1, 0);

    
}

 #define MAX 100001
#define fori(lim) for(int (i) = (0); (i) < (lim);(i)++ )
#define forj(lim) for(int (j) = (0); (j) < (lim);(j)++ )
 vector<int> nums;
 vector<int>::iterator it;
 
 #define in cin
 int main()
 {
	
	//ifstream in("test.txt");
	//freopen("test.txt", "r", stdin);
	
	in >> n >> m;
	nums.reserve(n);
	for (int i = 1; i <= n; i++)
        nums.pb(i);
 
	int counter = 0;
 
	fori(m){
 in >> t;
 
 if (nums.size()){
 
 it = upper_bound(nums.begin(),nums.end(), t);
 if (it == nums.begin())
     break;
 
 nums.erase(--it);
 counter++;
 }
 else break;
 
	}
	trace(counter);
 
	//cin.get();
	return 0;
 }
