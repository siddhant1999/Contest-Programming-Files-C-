

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
vector<int> list;

void dig(int value){
    vector<int> digits ;
    int mini = 10;
    int maxi = 0;
    long p1 = 0,p2 = 0;
    for( ; value > 0 ; value /= 10 ){
        if(value%10 != 0){
            int cur1 = mini, cur2 = maxi;
            mini = min(mini, value%10);
            if (cur1 !=mini)
                p1 = digits.size();
            
            maxi = max(maxi, value%10);
            if (cur2 !=maxi)
                p2 = digits.size();
        }
        digits.push_back( value%10);
    }
    
        reverse( digits.begin(), digits.end());
    
    long x = digits.size() - 1 - p1;
    long y = digits.size() - 1 - p2;
    vector<int> repeat = digits;
    for(int i = 0;i < x; i++) {
        if(digits[x] != digits[i]){
            int a  = digits[i];
            digits[i] = digits[x];
            digits[x] = a;
            break;
        }
    }
    for (int i = 0; i < digits.size(); i++) {
            cout << digits[i];
    }
    cout << " ";
    for(int i = 0;i < y; i++) {
        if(repeat[y] != repeat[i]){
            int a  = repeat[i];
            repeat[i] = repeat[y];
            repeat[y] = a;
            break;
        }
    }
    for (int i = 0; i < repeat.size(); i++) {
        cout << repeat[i];
    }
    cout << endl;
}

int main(void)
{
    int num;
    cin >> num;
    
    for (int i = 1; i <= num; i++) {
        int curt;
        cin >> curt;
        cout << "Case #" << i << ' ';
        dig(curt);
    }
}

