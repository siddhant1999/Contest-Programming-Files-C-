//
//  main.cpp
//  Prime it
//
//  Created by Siddhant Jain on 2015-07-21.
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
vc list;

int main(void)
{
    list.push_back(2);
    list.push_back(3);
    list.push_back(5);
    list.push_back(7);
    list.push_back(11);
    list.push_back(13);
    list.push_back(17);
    list.push_back(19);
    list.push_back(23);
    list.push_back(29);
    list.push_back(31);
    list.push_back(37);
    list.push_back(41);
    list.push_back(43);
    list.push_back(47);
    list.push_back(53);
    list.push_back(59);
    list.push_back(61);
    list.push_back(67);
    list.push_back(71);
    list.push_back(73);
    list.push_back(79);
    list.push_back(83);
    list.push_back(89);
    list.push_back(97);
    list.push_back(101);
    list.push_back(103);
    list.push_back(107);
    list.push_back(109);
    list.push_back(113);
    list.push_back(127);
    list.push_back(131);
    list.push_back(137);
    list.push_back(139);
    list.push_back(149);
    list.push_back(151);
    list.push_back(157);
    list.push_back(163);
    list.push_back(167);
    list.push_back(173);
    list.push_back(179);
    list.push_back(181);
    list.push_back(191);
    list.push_back(193);
    list.push_back(197);
    list.push_back(199);
    list.push_back(211);
    list.push_back(223);
    list.push_back(227);
    list.push_back(229);
    list.push_back(233);
    list.push_back(239);
    list.push_back(241);
    list.push_back(251);
    list.push_back(257);
    list.push_back(263);
    list.push_back(269);
    list.push_back(271);
    list.push_back(277);
    list.push_back(281);
    list.push_back(283);
    list.push_back(293);
    list.push_back(307);
    list.push_back(311);
    list.push_back(313);
    list.push_back(317);
    list.push_back(331);
    list.push_back(337);
    list.push_back(347);
    list.push_back(349);
    list.push_back(353);
    list.push_back(359);
    list.push_back(367);
    list.push_back(373);
    list.push_back(379);
    list.push_back(383);
    list.push_back(389);
    list.push_back(397);
    list.push_back(401);
    list.push_back(409);
    list.push_back(419);
    list.push_back(421);
    list.push_back(431);
    list.push_back(433);
    list.push_back(439);
    list.push_back(443);
    list.push_back(449);
    list.push_back(457);
    list.push_back(461);
    list.push_back(463);
    list.push_back(467);
    list.push_back(479);
    list.push_back(487);
    list.push_back(491);
    list.push_back(499);
    list.push_back(503);
    list.push_back(509);
    list.push_back(521);
    list.push_back(523);
    list.push_back(541);
    list.push_back(547);
    list.push_back(557);
    list.push_back(563);
    list.push_back(569);
    list.push_back(571);
    list.push_back(577);
    list.push_back(587);
    list.push_back(593);
    list.push_back(599);
    list.push_back(601);
    list.push_back(607);
    list.push_back(613);
    list.push_back(617);
    list.push_back(619);
    list.push_back(631);
    list.push_back(641);
    list.push_back(643);
    list.push_back(647);
    list.push_back(653);
    list.push_back(659);
    list.push_back(661);
    list.push_back(673);
    list.push_back(677);
    list.push_back(683);
    list.push_back(691);
    list.push_back(701);
    list.push_back(709);
    list.push_back(719);
    list.push_back(727);
    list.push_back(733);
    list.push_back(739);
    list.push_back(743);
    list.push_back(751);
    list.push_back(757);
    list.push_back(761);
    list.push_back(769);
    list.push_back(773);
    list.push_back(787);
    list.push_back(797);
    list.push_back(809);
    list.push_back(811);
    list.push_back(821);
    list.push_back(823);
    list.push_back(827);
    list.push_back(829);
    list.push_back(839);
    list.push_back(853);
    list.push_back(857);
    list.push_back(859);
    list.push_back(863);
    list.push_back(877);
    list.push_back(881);
    list.push_back(883);
    list.push_back(887);
    list.push_back(907);
    list.push_back(911);
    list.push_back(919);
    list.push_back(929);
    list.push_back(937);
    list.push_back(941);
    list.push_back(947);
    list.push_back(953);
    list.push_back(967);
    list.push_back(971);
    list.push_back(977);
    list.push_back(983);
    list.push_back(991);
    list.push_back(997);
    int n;
    cin >> n;
    if (n <= 1) {
        cout << "not";
        return 0;
    }
    vector<int>::iterator it;
    it = find(list.begin(), list.end(), n);
    if (it != list.end())
        cout << "prime";
    else
        cout << "not";
    
    return 0;
}