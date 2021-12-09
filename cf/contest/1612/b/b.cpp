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

int main() {
#ifdef woshiluo
	freopen( "b.in", "r", stdin );
	freopen( "b.out", "w", stdout );
#endif
	int T = read<int>();
	while( T -- ) {
		int n, a, b;
		static int res[110];
		std::vector<bool> vis; vis.resize(110, 0);
		n = read<int>(); a = read<int>(); b = read<int>();
		bool flag = true;
		res[1] = a;
		res[ ( n >> 1 ) + 1 ] = b;
		vis[a] = vis[b] = true;
		for( int i = 2; i <= ( n >> 1 ); i ++ ) {
			bool upd = false;
			for( int j = n; j >= 1; j -- ) {
				if( !vis[j] ) {
					res[i] = j;
					vis[j] = true;
					upd = true;
					break;
				}
			}
			if( !upd ) 
				flag = false;
		}
		for( int i = ( n >> 1 ) + 2; i <= n; i ++ ) {
			bool upd = false;
			for( int j = n; j >= 1; j -- ) {
				if( !vis[j] ) {
					res[i] = j;
					vis[j] = true;
					upd = true;
					break;
				}
			}
			if( !upd ) 
				flag = false;
		}
		for( int i = 1; i <= ( n >> 1 ); i ++ ) 
			if( res[i] < a ) 
				flag = false;
		for( int i = ( n >> 1 ) + 1; i <= n; i ++ ) 
			if( res[i] > b ) 
				flag = false;
		if( flag ) 
			for( int i = 1; i <= n; i ++ ) 
				printf( "%d ", res[i] );
		else 
			printf( "-1" );
		printf( "\n" );
	}
}
