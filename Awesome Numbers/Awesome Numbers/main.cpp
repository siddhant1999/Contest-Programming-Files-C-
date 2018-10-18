//
//  main.cpp
//  Awesome Numbers
//
//  Created by Siddhant Jain on 2015-06-30.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
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
#include <ctime>
using namespace std;
//board = vcc (num+1, vc (num+1, 0));

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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1000000000;
vcc board;
vc list, as;

int inc(int val){
    int sum = 0;
    for (int i = 0; i < as.size(); i++) {
        sum += as[i];
    }
    if (sum%2 == 0) {
        return 1;
    }else return 0;
}

int perf(int val){
    for (int i = 0; i < list.size(); i++) {
        if (val%list[i]==0) {
            return 0;
        }
    }
    return 1;
}

int dig(int val){
    vc as;
    int value = val;
    int digits = log10((float)value) + 1; //this determines the number of digits
    
    for (int i = digits - 1; i >= 0; i--) {
        int divisor = pow((float)10, i);
        int digit = value / divisor;
        
        value -= digit * divisor;
        
        as.push_back(digit);//insert digit into vector
    }
    
    int num = as[0];
    for (int i = 1; i < as.size(); i++) {
        if (num <= as[i]) {
            return 0;
        }
        num = as[i];
    }
    return 1;
}

int main(void)
{
    list.push_back(4);
    list.push_back(9);
    list.push_back(25);
    list.push_back(49);
    list.push_back(121);
    list.push_back(169);
    list.push_back(289);
    list.push_back(361);
    list.push_back(529);
    list.push_back(841);
    list.push_back(961);
    list.push_back(1369);
    list.push_back(1681);
    list.push_back(1849);
    list.push_back(2209);
    list.push_back(2809);
    list.push_back(3481);
    list.push_back(3721);
    list.push_back(4489);
    list.push_back(5041);
    list.push_back(5329);
    list.push_back(6241);
    list.push_back(6889);
    list.push_back(7921);
    list.push_back(9409);
    list.push_back(10201);
    list.push_back(10609);
    list.push_back(11449);
    list.push_back(11881);
    list.push_back(12769);
    list.push_back(16129);
    list.push_back(17161);
    list.push_back(18769);
    list.push_back(19321);
    list.push_back(22201);
    list.push_back(22801);
    list.push_back(24649);
    list.push_back(26569);
    list.push_back(27889);
    list.push_back(29929);
    list.push_back(32041);
    list.push_back(32761);
    list.push_back(36481);
    list.push_back(37249);
    list.push_back(38809);
    list.push_back(39601);
    list.push_back(44521);
    list.push_back(49729);
    list.push_back(51529);
    list.push_back(52441);
    list.push_back(54289);
    list.push_back(57121);
    list.push_back(58081);
    list.push_back(63001);
    list.push_back(66049);
    list.push_back(69169);
    list.push_back(72361);
    list.push_back(73441);
    list.push_back(76729);
    list.push_back(78961);
    list.push_back(80089);
    list.push_back(85849);
    list.push_back(94249);
    list.push_back(96721);
    list.push_back(97969);
    list.push_back(100489);
    list.push_back(109561);
    list.push_back(113569);
    list.push_back(120409);
    list.push_back(121801);
    list.push_back(124609);
    list.push_back(128881);
    list.push_back(134689);
    list.push_back(139129);
    list.push_back(143641);
    list.push_back(146689);
    list.push_back(151321);
    list.push_back(157609);
    list.push_back(160801);
    list.push_back(167281);
    list.push_back(175561);
    list.push_back(177241);
    list.push_back(185761);
    list.push_back(187489);
    list.push_back(192721);
    list.push_back(196249);
    list.push_back(201601);
    list.push_back(208849);
    list.push_back(212521);
    list.push_back(214369);
    list.push_back(218089);
    list.push_back(229441);
    list.push_back(237169);
    list.push_back(241081);
    list.push_back(249001);
    list.push_back(253009);
    list.push_back(259081);
    list.push_back(271441);
    list.push_back(273529);
    list.push_back(292681);
    list.push_back(299209);
    list.push_back(310249);
    list.push_back(316969);
    list.push_back(323761);
    list.push_back(326041);
    list.push_back(332929);
    list.push_back(344569);
    list.push_back(351649);
    list.push_back(358801);
    list.push_back(361201);
    list.push_back(368449);
    list.push_back(375769);
    list.push_back(380689);
    list.push_back(383161);
    list.push_back(398161);
    list.push_back(410881);
    list.push_back(413449);
    list.push_back(418609);
    list.push_back(426409);
    list.push_back(434281);
    list.push_back(436921);
    list.push_back(452929);
    list.push_back(458329);
    list.push_back(466489);
    list.push_back(477481);
    list.push_back(491401);
    list.push_back(502681);
    list.push_back(516961);
    list.push_back(528529);
    list.push_back(537289);
    list.push_back(546121);
    list.push_back(552049);
    list.push_back(564001);
    list.push_back(573049);
    list.push_back(579121);
    list.push_back(591361);
    list.push_back(597529);
    list.push_back(619369);
    list.push_back(635209);
    list.push_back(654481);
    list.push_back(674041);
    list.push_back(677329);
    list.push_back(683929);
    list.push_back(687241);
    list.push_back(703921);
    list.push_back(727609);
    list.push_back(734449);
    list.push_back(737881);
    list.push_back(744769);
    list.push_back(769129);
    list.push_back(776161);
    list.push_back(779689);
    list.push_back(786769);
    list.push_back(822649);
    list.push_back(829921);
    list.push_back(844561);
    list.push_back(863041);
    list.push_back(877969);
    list.push_back(885481);
    list.push_back(896809);
    list.push_back(908209);
    list.push_back(935089);
    list.push_back(942841);
    list.push_back(954529);
    list.push_back(966289);
    list.push_back(982081);
    
    /*while (true) {
        int n;
        cin >> n;
        cout << "list.push_back("<< n <<");" << endl;
    }*/
    //int num;
    //cin >> num;
    
    int r = 5;
    int a,b;
    while (r--) {
        cin >> a >> b;
        int sum = 0;
        for (; a <= b; a++) {
            if (dig(a) || perf(a) || inc(a)) {
                sum++;
            }
        }
        cout << sum << endl;
    }

    
    //insert last digit into vector
    /*for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }*/
}
