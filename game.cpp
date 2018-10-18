#include <stdio.h>
#include <string.h>
FILE *in,*out;
int pile[16];

char d[2][7][7][7][7][7][7];

int can_win( char player, int sum ){
if ( sum>31 )
 return 1;

 if ( player=='A' ){
  if ( d[0][pile[1]][pile[2]][pile[3]][pile[4]][pile[5]][pile[6]]>-1 )
   return d[0][pile[1]][pile[2]][pile[3]][pile[4]][pile[5]][pile[6]];
 }
else{

  if ( d[1][pile[1]][pile[2]][pile[3]][pile[4]][pile[5]][pile[6]]>-1 )
   return d[1][pile[1]][pile[2]][pile[3]][pile[4]][pile[5]][pile[6]];
}
//  printf( "player=%c sum=%d\n", player, sum );
//  getch();

int i;
int k=0;
int total=0;
for ( i=1; i<=6; i++ )
 if ( pile[i] ){
   total++;
   pile[i]--;
    if ( player=='A' )
     k+=can_win( 'B', sum+i );
    else
     k+=can_win( 'A', sum+i );
   pile[i]++;
  }

  if ( k==total ) // B won everything
    return (d[player-'A'][pile[1]][pile[2]][pile[3]][pile[4]][pile[5]][pile[6]]=0);
  else
   return (d[player-'A'][pile[1]][pile[2]][pile[3]][pile[4]][pile[5]][pile[6]]=1);
}

void main( void ){
in=fopen( "game.in", "r" );
out=fopen( "game.out", "w" );
out=stdout; // CHANGEEEEE
int ngames,len;
fscanf( in, "%d", &ngames );
while ( ngames-- ){
memset( d, -1, sizeof(d) );
//printf( "size=%d\n", sizeof(d) );
int i;
char temp[16];
for ( i=1; i<=6; i++ )
 pile[i]=4;
fscanf( in, "%s", temp );
len=strlen( temp );
int startscore=0;
for ( i=0; i<len; i++ ){
  pile[temp[i]-'0']--;
  startscore+=temp[i]-'0';
 }
if ( len%2==0 ){
if ( can_win( 'A', startscore ) )
 fputc( 'A', out );
else
 fputc( 'B', out );
}
else{
if ( can_win( 'B', startscore ) )
 fputc( 'B', out );
else
 fputc( 'A', out );

}
  fputc( '\n', out );
}

}
