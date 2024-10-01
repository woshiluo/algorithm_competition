/*
 * a.cpp 2024-09-29
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
constexpr T Max( T a, T b ) { return a > b? a: b; }
template <class T> 
constexpr T Min( T a, T b ) { return a < b? a: b; }
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
constexpr T pow( T a, i32 p ) {
	T res = 1;
	while( p ) {
		if( p & 1 ) 
			res = res * a;
		a = a * a;
		p >>= 1;
	}
	return res;
}/*}}}*/

const i32 N = 1100;

std::vector<std::pair<i32, i32>> ops;

void build( ci32 l, ci32 r, std::vector<std::pair<i32, i32>> &list ) {
	if( list.size() == 0 ) 
		return ;
	if( l == r ) 
		return ;
	ci32 mid = ( l + r ) >> 1;

	std::vector<std::pair<i32, i32>> cl, cr;
	for( auto &x: list ) {
		if( x.second <= mid ) 
			cl.push_back(x);
		else {
			cr.push_back(x);
			ops.emplace_back( 2, x.first );
		}
	}
	for( int i = l + 1; i <= mid; i ++ ) {
		ops.emplace_back( 1, i );
	}
	build( l, mid, cl );
	build( mid + 1, r, cr );
}

int main() {
#ifdef woshiluo
	freopen( "a.in", "r", stdin );
	freopen( "a.out", "w", stdout );
#endif
	std::vector<std::pair<i32, i32>> list;
	ci32 n = read<i32>();
	for( int i = 1; i <= n; i ++ ) 
		list.emplace_back( i, read<i32>() );

	build( 0, n, list );

	printf( "%zu\n", ops.size() );
	for( auto &[op, x]: ops ) {
		printf( "%d %d\n", op, x );
	}

		
	return 0;
}
