/*
 * c.cpp 2024-03-05
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
	freopen( "c.in", "r", stdin );
	freopen( "c.out", "w", stdout );
#endif
	i32 T = read<i32>();
	while( T -- ) {
		ci32 n = read<i32>();
		ci32 l = read<i32>();
		struct Node {
			i32 a, b;
		};
		std::vector<Node> nodes;
		for( int i = 1; i <= n; i ++ ) {
			ci32 a = read<i32>();
			ci32 b = read<i32>();
			nodes.push_back( (Node) { a, b } );
		}
		std::sort( nodes.begin(), nodes.end(), [&]( const Node &_a, const Node &_b ) { return _a.b == _b.b? _a.a < _b.a: _a.b < _b.b; } );
		std::vector<i64> f( n * 2, -1 );
		f[0] = 0;
		i32 res = 0;
		for( int i = 0; i < n; i ++ ) {
			if( i != 0 ) {
				for( int j = 1; j <= n; j ++ ) {
					if( f[j] != -1 )
						f[j] += nodes[i].b - nodes[ i - 1 ].b;
				}
			}
			for( int j = n; j >= 1; j -- ) {
				if( f[ j - 1 ] != -1 ) {
					if( f[j] == -1 ) 
						f[j] = f[ j - 1 ] + nodes[i].a;
					else 
						chk_Min( f[j], f[ j - 1 ] + nodes[i].a );
				}
			}
			for( int j = 0; j <= n; j ++ ) {
				if( f[j] != -1 && f[j] <= l ) {
					chk_Max( res, j );
				}
			}
		}
		printf( "%d\n", res );
	}
	
}
