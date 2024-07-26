/*
 * d.cpp 2024-01-11
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

#include <map>
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


template <class T>
T aabs( T cur ) { return cur < 0? -cur: cur; }

std::map<i32, i32> dis;
std::map<i32, bool> vis;

int main() {
#ifdef woshiluo
	freopen( "d.in", "r", stdin );
	freopen( "d.out", "w", stdout );
#endif

	int n, k;
	while( scanf( "%d%d", &n, &k ) != EOF ) {
		std::queue<i32> q;
		q.push(n);
		dis.clear();
		vis.clear();
		dis[n] = 0;
		while( !q.empty() ) {
			ci32 top = q.front(); q.pop();
			if( top == k ) {
				printf( "%d\n", dis[top] );
				break;
			}
			if( dis[top] + 1 > aabs( n - k ) ) 
				continue;
			if( top - k > aabs( n - k ) )
				continue;
			if( dis.count( top + 1 ) == 0) {
				dis[ top + 1 ] = dis[top] + 1;
				q.push( top + 1 );
			}
			if( dis.count( top - 1 ) == 0 ) {
				dis[ top - 1 ] = dis[top] + 1;
				q.push( top - 1 );
			}
			if( dis.count( top << 1 ) == 0 ) {
				dis[ top << 1 ] = dis[top] + 1;
				q.push( top << 1 );
			}
		}
	}
}