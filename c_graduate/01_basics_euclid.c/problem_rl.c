#include <assert.h>
#include <stdio.h>
//#include <stdlib.h>

int iabs( int x ) { return ( x < 0 ) ? -x : x; }

int eu_mod( int x, int y ) {
  int r;
  assert( y != 0 );
  r = x % y;
  if ( r < 0 )
    r += iabs( y );
  return r;
}

/// <summary>
/// Return greatest common divisor
/// </summary>
/// <param name="x">val 1</param>
/// <param name="y">val 2</param>
/// <returns>greatest common divisor</returns>
long long gcd( long long x, long long y ) {
  // x = y * p1 + x%y <=> y = q * p2 + y%q
  long long q = 1;
  while( q != 0 )
  {
    q = eu_mod( x, y );
    if ( q == 0 )
      break;
    x = y;
    y = q;
  }
  return y;
}

/// <summary>
/// Return greatest common divisor
/// </summary>
/// <param name="x">val 1</param>
/// <param name="y">val 2</param>
/// <returns>greatest common divisor</returns>
long long gcd_recursive( long long x, long long y ) {
  long long q;
  q = eu_mod( x, y );
  if ( q == 0 )
    return y;
  return gcd( y, q );
}

int main() {
  long long x = 0, y = 0, g;
  long long res;

  res = scanf( "%lld %lld", &x, &y );
  assert( res == 2 );
  g = gcd( x, y );
  printf( "%lld\n", g );

  // tests:

  //x = 14;
  //y = 8;
  //g = gcd( x, y );
  //assert( g == 2 );

  //x = 14;
  //y = -8;
  //g = gcd( x, y );
  //assert( g == 2 );

  //x = -14;
  //y = 8;
  //g = gcd( x, y );
  //assert( g == 2 );

  //x = 18;
  //y = -60;
  //g = gcd( x, y );
  //assert( g == 6 );

  //x = 698917;
  //y = 102089;
  //g = gcd( x, y );
  //assert( g == 7853 );

  return 0;
}