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
		struct Segment {
			int l, r, id;
		};
		std::vector<Light> lights;
		std::vector<Segment> segs;
		for( int i = 0; i < n; i ++ ) {
			ci32 x = read<i32>();
			ci32 r = read<i32>();
			lights.push_back( (Light){ i, x, r } );
			segs.push_back( (Segment){ x - r, x + r, i } );
		}
		std::sort( segs.begin(), segs.end(), []( const auto &_a, const auto &_b ) {

		});
		std::sort( lights.begin(), lights.end(), []( const auto &_a, const auto &_b ) { if( _a.x == _b.x ) return _a.id < _b.id; return _a.x < _b.x; } );
		for( auto &light: lights ) {
			while(!segs.empty()) {
				auto &[l, r, id] = segs.back();
				if( l <= light.x ) {
				}
			}
		}
	}
	
}
