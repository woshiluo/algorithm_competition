/*
 * c.cpp 2024-07-08
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

#include <queue>
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
		struct Light {
			int id, x, r;
		};
		std::vector<Light> lights;

		for( int i = 0; i < n; i ++ ) {
			ci32 x = read<i32>();
			ci32 r = read<i32>();
			lights.push_back( (Light){ i, x, r } );
		}
		i32 vr = lights[0].x + lights[0].r;
		for( auto &light: lights ) {
			if( light.x <= vr ) 
				chk_Max( vr, light.x + light.r );
		}
		if( vr < lights.back().x ) {
			printf( "-1\n" );
			continue;
		}

		i32 vl = lights[ n - 1 ].x - lights[ n - 1 ].r;
		for( int i = n - 1; i >= 0; i -- ) {
			if( lights[i].x >= vl ) {
				chk_Min( vl, lights[i].x - lights[i].r );
			}
		}
		if( vl > lights[0].x ) {
			printf( "-1\n" );
			continue;
		}

		
		printf( "%lld\n", 3LL * ( lights.back().x - lights[0].x ) );
	}
}
