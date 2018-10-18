//
//  main.cpp
//  Orbital Conversion
//
//  Created by Siddhant Jain on 2016-09-04.
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

// analysis period
double analysisPeriod_hour = 3;

// analysis interval
double dt_sec = 1000;

// Satellite orbit elements
// Inputs:  a:     Semi-major axis in km
//          ecc:   Eccentricity
//          inc:   Inclination of orbit in degrees
//          Omega: Right ascension of ascending node in degrees
//          w:     Argument of perigee in degrees
//          M0:    Mean anolmaly at J2000
/*
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
*/
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
    vector<double> TIME;
    
    for (int i = 0; i <= analysisPeriod_hour*3600; i+=dt_sec) {
        TIME.push_back(i);
    }

    long NTIME = TIME.size();

    // Compute satellite position
    vector< vector<double>> pSat (NTIME, vector<double> (3, 0));// Satellite position
    vector< vector<double>>  vSat (NTIME, vector<double> (3, 0));// Satellite velocity

    double p = a*(1-(ecc*ecc));

    double num = sqrt(U/(a*a*a));
    vector<double> M = TIME;
    for (int i = 0; i < M.size(); i++){
        M[i] = M[i] * num;
    }

    double pi = 3.14159265;
    double convert = pi/180.0;

    for (int i = 0; i < NTIME; i++) {
        double temp = (M0*pi/180 + M[i]);
        double div = temp / (2*pi);
        
        double nu = temp - (double(floor(div)) * 2 * pi);
        vector<double> R_pqw;
        R_pqw.push_back(p*cos(nu)/(1 + ecc*cos(nu)));
        R_pqw.push_back(p*sin(nu)/(1 + ecc*cos(nu)));
        R_pqw.push_back(0);
        
        
                    
        // CREATING THE V VECTOR IN THE pqw COORDINATE FRAME
        vector<double> V_pqw;
        V_pqw.push_back(-(sqrt(U/p)*sin(nu)));
        V_pqw.push_back(sqrt(U/p)*(ecc + cos(nu)));
        V_pqw.push_back(0);
        // ROTATING THE pqw VECOTRS INTO THE ECI FRAME (ijk)
        
        vector<vector<double >> R { {cos(-Omega*convert), sin(-Omega*convert), 0},
            {-sin(-Omega*convert), cos(-Omega*convert), 0},
            {0, 0, 1} };
        
        vector<vector<double >> c { {1, 0, 0},
            {0, cos(-inc*convert), sin(-inc*convert)},
            {0, -sin(-inc*convert), cos(-inc*convert)} };
        
        vector<vector<double >> b { {cos(-w*convert), sin(-w*convert), 0},
            {-sin(-w*convert), cos(-w*convert), 0},
            {0, 0, 1} };
        
        
        vector<vector<double >> pr1 { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
        //Dot Product

        //Second Dot Product
        pr1[0][0] = R[0][0] * c[0][0] + R[0][1] * c[1][0] + R[0][2] * c[2][0];
        pr1[0][1] = R[0][0] * c[0][1] + R[0][1] * c[1][1] + R[0][2] * c[2][1];
        pr1[0][2] = R[0][0] * c[0][2] + R[0][1] * c[1][2] + R[0][2] * c[2][2];
        
        pr1[1][0] = R[1][0] * c[0][0] + R[1][1] * c[1][0] + R[1][2] * c[2][0];
        pr1[1][1] = R[1][0] * c[0][1] + R[1][1] * c[1][1] + R[1][2] * c[2][1];
        pr1[1][2] = R[1][0] * c[0][2] + R[1][1] * c[1][2] + R[1][2] * c[2][2];
        
        pr1[2][0] = R[2][0] * c[0][0] + R[2][1] * c[1][0] + R[2][2] * c[2][0];
        pr1[2][1] = R[2][0] * c[0][1] + R[2][1] * c[1][1] + R[2][2] * c[2][1];
        pr1[2][2] = R[2][0] * c[0][2] + R[2][1] * c[1][2] + R[2][2] * c[2][2];
        
        
        //Third Dot Product
        R[0][0] = pr1[0][0] * b[0][0] + pr1[0][1] * b[1][0] + pr1[0][2] * b[2][0];
        R[0][1] = pr1[0][0] * b[0][1] + pr1[0][1] * b[1][1] + pr1[0][2] * b[2][1];
        R[0][2] = pr1[0][0] * b[0][2] + pr1[0][1] * b[1][2] + pr1[0][2] * b[2][2];
        
        R[1][0] = pr1[1][0] * b[0][0] + pr1[1][1] * b[1][0] + pr1[1][2] * b[2][0];
        R[1][1] = pr1[1][0] * b[0][1] + pr1[1][1] * b[1][1] + pr1[1][2] * b[2][1];
        R[1][2] = pr1[1][0] * b[0][2] + pr1[1][1] * b[1][2] + pr1[1][2] * b[2][2];
        
        R[2][0] = pr1[2][0] * b[0][0] + pr1[2][1] * b[1][0] + pr1[2][2] * b[2][0];
        R[2][1] = pr1[2][0] * b[0][1] + pr1[2][1] * b[1][1] + pr1[2][2] * b[2][1];
        R[2][2] = pr1[2][0] * b[0][2] + pr1[2][1] * b[1][2] + pr1[2][2] * b[2][2];
        
        for (int k=0; k<3; k++) {
            pSat[i][k]= (R[k][0]*R_pqw[0]) + (R[k][1]*R_pqw[1]) + (R[k][2]*R_pqw[2]);
        }
        for (int k=0; k<3; k++) {
            vSat[i][k]= (R[k][0]*V_pqw[0]) + (R[k][1]*V_pqw[1]) + (R[k][2]*V_pqw[2]);
        }
        
        pr1.clear();
        R.clear();
        c.clear();
        b.clear();
        R_pqw.clear();
        V_pqw.clear();
        
    }
    for (int l = 0; l < NTIME; l++) {
        cout << pSat[l][0] << " " << pSat[l][1] << " " << pSat[l][2] << endl;
    }
}