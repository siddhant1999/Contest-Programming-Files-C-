//
//  Orbital.cpp
//  
//
//  Created by Siddhant Jain on 2016-08-31.
//
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

// analysis period
double analysisPeriod_hour = 3;

// analysis interval
double dt_sec = 10;

// Satellite orbit elements
// Inputs:  a:     Semi-major axis in km
//          ecc:   Eccentricity
//          inc:   Inclination of orbit in degrees
//          Omega: Right ascension of ascending node in degrees
//          w:     Argument of perigee in degrees
//          M0:    Mean anolmaly at J2000

double a = 6775.97043;
double  ecc = 0.0005550;
double inc = 51.51299;
double Omega = 196.71244;
double w = 111.07975;
double M0 = 321.21369;
//ISS Orbit

double a = 6875;
double ecc = 0;
double inc = 105;
double Omega = 50;
double w = 60;
double M0 = 0;
// SSO Orbit

double a = 6378+600;
double ecc = 0;
double inc = 97.2166;
double Omega = 50;
double w = 0;
double M0 = 0;
// SSO Orbit

// Constants
double U = 398600.4415; // Gravitational Constant for Earth (km^3/s^2)
double Re= 6378;

//Load the sun vector from the csv file

int main(void)
{

	vc TIME;

	for (int i = 0; i <= analysisPeriod_hour*3600; i+=dt_sec)
	{
		TIME.push_back(i);
	}

	int NTIME = TIME.size();
	
	// Compute satellite position
	vcc pSat (NTIME, vc (3, 0));// Satellite position
	vcc vSat (NTIME, vc (3, 0));// Satellite velocity
	
	double p = a*(1-(ecc*ecc));

	double num = sqrt(U/(a*a*a));
	vc M = TIME;
	for (int i = 0; i < M.size(); i++)
	{
		M[i] = M[i] * num;
	}
	// Calculate change in satellite position. Kepler's third law
	
	double pi = 3.14159265;
	double convert = pi/180.0;

	for (int i = 0; i < NTIME; i++)
	{
	
		// updating the satellite position
		double nu = (M0*pi/180 + M[i]) %  (2*pi);
	
		// CREATING THE R VECTOR IN THE pqw COORDINATE FRAME
		vector<double> R_pqw;
		R_pqw.push_back(p*cos(nu)/(1 + ecc*cos(nu)));
		R_pqw.push_back(p*sin(nu)/(1 + ecc*cos(nu));
		R_pqw.push_back(0);

		// CREATING THE V VECTOR IN THE pqw COORDINATE FRAME
		vector<double> V_pqw;
		V_pqw.push_back(-(sqrt(U/p)*sin(nu)));
		V_pqw.push_back(sqrt(U/p)*(ecc + cos(nu)));
		V_pqw.push_back(0);
	
		// ROTATING THE pqw VECOTRS INTO THE ECI FRAME (ijk)

		vcc R { {cos(-Omega*convert), sin(-Omega*convert), 0},
				 {-sin(-Omega*convert), cos(-Omega*convert), 0},
				 {0, 0, 1} };


	

	     vcc a { {1, 0, 0},
				 {0, cos(-inc*convert), sin(-inc*convert)},
				 {0, -sin(-inc*convert), cos(-inc*convert)} };

		vcc b { {cos(-w*convert), sin(-w*convert), 0},
				 {-sin(-w*convert), cos(-w*convert), 0},
				 {0, 0, 1} };

		

	/*R = [cosd(-Omega) sind(-Omega) 0;
	     -sind(-Omega) cosd(-Omega) 0;
	     0 0 1];*/
	/*R = R*[1 0 0;
	       0 cosd(-inc) sind(-inc);
	       0 -sind(-inc) cosd(-inc)];*/

	/*R = R*[cosd(-w) sind(-w) 0;
	       -sind(-w) cosd(-w) 0;
	       0 0 1];*/


	pSAT(t,:) = (R*R_pqw)';
	vSAT(t,:) = (R*V_pqw)';
	}
	clear p M R R_pqw t U a ecc inc M0 nu Omega w V_pqw R2;
}