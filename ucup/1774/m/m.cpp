/*
 * m.cpp 2024-09-21
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
#include <cinttypes>

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

int main() {
#ifdef woshiluo
	freopen( "m.in", "r", stdin );
	freopen( "m.out", "w", stdout );
#endif


	ci32 n = 1 << read<i32>();
	std::vector<i64> a(n + 1), sum(n + 1, 0);
	for( int i = 1; i <= n; i ++ ) 
		a[i] = read<i32>();
	std::sort( a.begin() + 1, a.end() );
	std::reverse( a.begin() + 1, a.end() );

	for( int i = 1; i <= n; i ++ ) 
		sum[i] = sum[ i - 1 ] + a[i];

	i64 max = -0x3f3f3f3f3f3f3f3f;
	for( int k = 1; k <= n; k <<= 1 ) {
		for( int l = 1; l <= n; l += k ) {
			ci64 cur = sum[ l + k - 1 ] - sum[ l - 1 ];
			chk_Max( max, cur );
		}
	}
	printf( "%" PRId64 "\n", max );
	
}