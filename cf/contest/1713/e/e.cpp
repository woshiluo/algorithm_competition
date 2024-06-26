/*
 * e.cpp
 * Copyright (C) 2022 Woshiluo Luo <woshiluo.luo@outlook.com>
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

#include <algorithm>

typedef const int cint;
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

const int N = 1100;

struct Set {
	int set[ N << 4 ];
	void init( cint n ) { for( int i = 0; i <= n; i ++ ) set[i] = i; }
	int get_fa( cint cur ) {
		if( set[cur] == cur )
			return cur;
		set[cur] = get_fa( set[cur] );
		return set[cur];
	}
	int& operator[]( const int cur ) { 
		return set[ get_fa(cur) ];
	}
} set;

int a[N][N];
bool tag[N][N];

int main() {
#ifdef woshiluo
	freopen( "e.in", "r", stdin );
	freopen( "e.out", "w", stdout );
#endif
	int T = read<int>();
	while( T -- ) {
		cint n = read<int>();
		for( int i = 1; i <= n; i ++ ) {
			for( int j = 1; j <= n; j ++ ) {
				a[i][j] = read<int>();
			}
		}

		set.init( n * 3 );
		for( int i = 1; i <= n; i ++ ) {
			for( int j = 1; j <= n; j ++ ) {
				if( i >= j ) 
					continue;
				if( a[i][j] == a[j][i] ) 
					continue;

				bool p = ( a[i][j] < a[j][i] );
				bool f1 = ( set[i] == set[j] );
				bool f2 = ( set[i] == set[ j + n ] );

				if( p && !f2 ) {
					set[i] = set[j];
					set[ i + n ] = set[ j + n ];
				}
				if( !p && !f1 ) {
					set[i] = set[ j + n ];
					set[j] = set[ i + n ];
				}
			}
		}

		for( int i = 1; i <= n; i ++ ) {
			for( int j = 1; j <= n; j ++ ) {
				bool flag = ( set[i] == set[ j + n ] );

				if( flag ) 
					printf( "%d ", a[j][i] );
				else
					printf( "%d ", a[i][j] );
			}
			printf( "\n" );
		}
	}
}
