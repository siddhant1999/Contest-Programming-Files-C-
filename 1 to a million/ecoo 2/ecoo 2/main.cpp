//
//  main.cpp
//  ecoo 2
//
//  Created by Siddhant Jain on 2016-04-30.
//  Copyright © 2016 Siddhant Jain. All rights reserved.
//

//
//  main.cpp
//  ecoo 1
//
//  Created by Siddhant Jain on 2016-04-30.
//  Copyright © 2016 Siddhant Jain. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <fstream>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <ctime>
using namespace std;
//board = vcc (num+1, vc (num+1, 0));


#define x0 first
#define y0 second.first
#define z0 second.second

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define mpp(one,two,three) make_pair( one,  make_pair( two, three ) )
#define tp(one) cout << (one).first << " " << (one).second << endl;
#define ms(thing, val) memset( (thing), (val), sizeof(thing) )
#define mt make_tuple
#define fori(lim) for(int (i) = (0); (i) < (lim);(i)++ )
#define forj(lim) for(int (j) = (0); (j) < (lim);(j)++ )
#define fork(lim) for(int (k) = (0); (k) < (lim);(k)++ )
#define input ios::sync_with_stdio(false)
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vc list;
int a;
string str;

void decode(){
    char t = char (str[str.length()-1]-a);
    
    string sss ="";//account of negatives
    sss+= t;
    int sum = int (t-'a');
   
    ///remember sss isbackwards
    for (int i = str.length()-2; i>= 0; i--) {
        char abc = char (str[i]-a);//sum
        //negative
        int aaa = int (abc) - sum;
        if (aaa < 97) {
            while(aaa < 97)
                aaa += 26;
        }
        //cout << "abc ::" <<  abc << " "<< char(aaa) << endl;
        sum+=(aaa-97);
        sss+= char (aaa);
        
        //sum += int (aaa-'a');
    }
    reverse(sss.begin(), sss.end());
    int q = int(sss[0])-97;
    int w = int(sss[1])-97;
    int words = q*26 + w;
    int k = 2+words;
    
    for (int i = 0; i < words; i++) {
        int num = 2+i;
        int val = int(sss[num])-97;
        
        for(int ll = 0;ll < val;ll++) {
            cout << sss[k+ll];
        }
        k+=val;
        cout << " ";
    }
    cout << endl;
}



int main(void)
{
    //input;
    ifstream in("DATA22.txt");
    
    fork(1){
        in >> a;
        char nothing  = in.get();
        
        getline(in, str);
        
        int c =1;
        fori(str.length()){
            if (str[i] == ' ') {
                c++;
            }
        }
        if (c == 1) {
            decode();
            continue;
        }
        int f = c/26;
        int s = c%26;
        char fab = 'a' + f;
        char sab = 'a' + s;
        string key = "";
        key += fab;
        key+= sab;
        
        int kk = 0;
        fori(str.length()){
            if (str[i] == ' ') {
                char abc = 'a' + kk%26;
                key +=abc;
                kk = 0;
                continue;
            }
            kk++;
        }
        char abc = 'a' + kk%26;
        key += abc;
        string sss = key;
        fori(str.length()){
            if (str[i] != ' ') {
                sss += str[i];
            }
        }
        vc prefix (sss.length() +1, 0);
        for (int i = sss.length()-1; i >= 0; i--) {
            prefix[i] = prefix[i+1] + int(int (sss[i])-'a');
        }
        for (int i = 0; i <= sss.length(); i++) {
            int abcd = (prefix[i] + a)%26;
            char aba = abcd + 'a';
            cout << aba;
        }
        cout << endl;
    }
    
    
    
}

