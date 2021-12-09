/*
 * b.cpp
 * Copyright (C) 2021 Woshiluo Luo <woshiluo.luo@outlook.com>
 *
 * 「Two roads diverged in a wood,and I—
 * I took the one less traveled by,
 * And that has made all the difference.」
 *
 * Distributed under terms of the GNU AGPLv3+ license.
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;

inline bool isdigit( const char cur ) { return cur >= '0' && cur <= '9'; }/*{{{*/
template <class T> 
T Max( T a, T b ) { return a > b? a: b; }
template <class T> 
T Min( T a, T b ) { return a < b? a: b; }
template <class T> 
void chk_Max( T &a, T b ) { if( b > a ) a = b; }
template <class T> 
void chk_Min( T &a, T b ) { if( b < a ) a = b; }
template <typename T>
T read() { 
	T sum = 0, fl = 1; 
	char ch = getchar();
	for (; isdigit(ch) == 0; ch = getchar())
		if (ch == '-') fl = -1;
	for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * fl;
}
template <class T> 
T pow( T a, int p ) {
	T res = 1;
	while( p ) {
		if( p & 1 ) 
			res = res * a;
		a = a * a;
		p >>= 1;
	}
	return res;
}/*}}}*/

const int N = 2e5 + 1e4;

int a[N], b[N];

int main() {
	int T = read<int>();
	while( T -- ) {
		int n;
		scanf( "%d", &n );
		for( int i = 1; i <= n; i ++ ) {
			scanf( "%1d", &a[i] );
		}
		for( int i = 1; i <= n; i ++ ) {
			scanf( "%1d", &b[i] );
		}
		a[0] = a[ n + 1 ] = 0;
		int cnt = 0;
		for( int i = 1; i <= n; i ++ ) {
			if( b[i] ) {
				if( a[i] == 0 ) {
					cnt ++;
					continue;
				}
				if( a[ i - 1 ] == 1 ) {
					cnt ++;
					a[ i - 1 ] = 0;
					continue;
				}
				if( a[ i + 1 ] == 1 ) {
					cnt ++;
					a[ i + 1 ] = 0;
					continue;
				}
			}
		}
		printf( "%d\n", cnt );
	}
}
