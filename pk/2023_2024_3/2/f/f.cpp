/*
 * f.cpp 2024-07-08
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
	freopen( "f.in", "r", stdin );
	freopen( "f.out", "w", stdout );
#endif

	ci32 n = read<i32>();
	ci32 k = read<i32>();
	std::vector<i32> a(k), b(k);
	// a 1 count / to all 0
	// b 0 count / to all 1
	for( int i = 0; i < n; i ++ ) {
		ci32 p = read<i32>();
		a[ i % k ] += p & 1;
		b[ i % k ] += !(p & 1);
	}
	int p = 0;
	std::vector<std::vector<i32>> f(k + 1, std::vector<i32>(2, 0));
	f[0][0] = 0;
	f[0][1] = n + 1;
	for( int i = 1; i <= k; i ++ ) {
		f[i][0] = Min( f[ i - 1 ][1] + b[ i - 1 ], f[ i - 1 ][0] + a[ i - 1 ] );
		f[i][1] = Min( f[ i - 1 ][0] + b[ i - 1 ], f[ i - 1 ][1] + a[ i - 1 ] );
	}

	printf( "%d\n", f[k][0] );
}