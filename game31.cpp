
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <time.h>

using namespace std;

map< vector<int>, char > win;

char getwin( vector<int> g ){
 int sum=g[0]+2*g[1]+3*g[2]+4*g[3]+5*g[4]+6*g[5];
 if ( sum > 31 ) return 1;

 if ( win.count(g) ) return win[g];

 int i,j;
 int WIN=0; 

 for ( i=0; i<6; i++ )
  if ( g[i]<4 ){
   g[i]++;
    if ( !getwin(g) ) WIN=1;
   g[i]--;
 }
 
 win[g]=WIN;
 return WIN;
}

int main( void ){
clock();

FILE *in,*out;
in=fopen( "in.in", "r" );
out=stdout;

int i,j,k,t;

fscanf( in, "%d", &t );

while ( t-- ){
 char buf[128];
 fscanf( in, "%s", buf );
 int L=strlen(buf);
 char c;

 vector<int> start(6,0);

 for ( i=0; i<L; i++ )
  start[ buf[i]-'0'-1 ]++;

 char a='A', b='B';
 if ( L%2 ) swap(a,b);
 
 if ( getwin( start ) ) fprintf( out, "%c", a );
 else fprintf( out, "%c", b );
 fputc( '\n', out );
}

printf( "%.4lf\n", double(clock())/CLOCKS_PER_SEC );
return 0;
}
