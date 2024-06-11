/*
 * b.cpp 2024-03-01
 * Copyright (C) 2024 Woshiluo Luo <woshiluo.luo@outlook.com>
 *
 * 「Two roads diverged in a wood,and I—
 * I took the one less traveled by,
 * And that has made all the difference.」
 *
 * Distributed under terms of the GNU GNU AGPLv3+ license.
 */

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <algorithm>

using i32 = int32_t;
using u32 = uint32_t;
using ci32 = const int32_t;
using cu32 = const uint32_t;

using i64 = int64_t;
using u64 = uint64_t;
using ci64 = const int64_t;
using cu64 = const uint64_t;

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
T pow( T a, i32 p ) {
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

	i32 T = read<i32>();
	while( T -- ) {
		ci32 n = read<i32>();
		std::vector<int> mp[2];
		mp[0].resize( n + 1 ); mp[1].resize( n + 1 );
		for( int i = 1; i <= n; i ++ ) {
			scanf( "%1d", &mp[0][i] );
		}
		for( int i = 1; i <= n; i ++ ) {
			scanf( "%1d", &mp[1][i] );
		}
		int cur_best = 1;
		printf( "%d", mp[0][1] );
		for( int i = 1; i < n; i ++ ) {
			if( mp[1][i] == mp[0][ i + 1 ] ) {
				printf( "%d", mp[1][i] );
				cur_best ++;
				continue;
			}
			if( mp[1][i] < mp[0][ i + 1 ] ) {
				for( int j = i; j < n; j ++ ) {
					printf( "%d", mp[1][j] );
				}
				break;
			}
			else {
				printf( "%d", mp[0][ i + 1 ] );
				cur_best = 1;
			}
		} 
		printf( "%d\n", mp[1][n] );
		printf( "%d\n", cur_best );
	}
}
