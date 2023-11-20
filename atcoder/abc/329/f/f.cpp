/*
 * f.cpp 2023-11-18
 * Copyright (C) 2023 Woshiluo Luo <woshiluo.luo@outlook.com>
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

#include <set>
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

const i32 N = 2e5 + 1e4;

int main() {
#ifdef woshiluo
	freopen( "f.in", "r", stdin );
	freopen( "f.out", "w", stdout );
#endif

	ci32 n = read<i32>();
	ci32 q = read<i32>();
	std::set<i32> set[N];
	for( int i = 1; i <= n; i ++ ) {
		set[i].insert(read<i32>());
	}
	for( int i = 1; i <= q; i ++ ) {
		i32 u = read<i32>();
		i32 v = read<i32>();
		if( set[u].size() == 0 ) 
			;
		else if( set[v].size() == 0 ) {
			std::swap( set[u], set[v] );
		}
		else {
			bool flag = false;
			if( set[u].size() > set[v].size() ) {
				flag = true;
				std::swap( u, v );
			}
			while( !set[u].empty() ) {
				set[v].insert( *set[u].begin() );
				set[u].erase( set[u].begin() );
			}
			if( flag ) {
				std::swap( u, v );
				std::swap( set[u], set[v] );
			}
		}
		printf( "%lu\n", set[v].size() );
	}
}
