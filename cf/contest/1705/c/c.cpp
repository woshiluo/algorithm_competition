/*
 * c.cpp
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

const int N = 2e5 + 1e4;

ll l[N], r[N];

ll work( ll cur, cint n, cint c ) {
	if( cur <= n )
		return cur;
	cur -= n;
	for( int i = 1; i <= c; i ++ ) {
		const ll len = r[i] - l[i] + 1;
		if( cur <= len )
			return work( cur + l[i] - 1, n, c );
		else
			cur -= len;
	}
	
	return 0;
}


int main() {
#ifdef woshiluo
	freopen( "c.in", "r", stdin );
	freopen( "c.out", "w", stdout );
#endif

	int T = read<int>();
	while( T -- ) {
		cint n = read<int>();
		cint c = read<int>();
		cint q = read<int>();

		static char str[N];
		scanf( "%s", str + 1 );

		for( int i = 1; i <= c; i ++ ) {
			l[i] = read<ll>();
			r[i] = read<ll>();
		}

		for( int i = 1; i <= q; i ++ ) {
			ll x = read<ll>();
			printf( "%c\n", str[ work(x, n, c) ] );
		}
	}
}
