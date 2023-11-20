/*
 * g.cpp 2023-11-18
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

const int N = 1e5 + 1e4;

struct Edge {
	int to, next;
} e[ N << 1 ];
int ehead[N], ecnt;
void add_edge( ci32 from, ci32 to ) {
	ecnt ++;
	e[ecnt].to = to;
	e[ecnt].next = ehead[from];
	ehead[from] = ecnt;
}

i32 lowbit( ci32 cur ) { return cur & ( - cur ); }
struct BIT {
	int n;
	int tree[N];

	void init( int _n ) {
		n = _n;;
		memset( tree, 0, sizeof(int) * ( n + 1 ) );
	}

	void add( i32 cur, i32 val ) {
		for( ; cur <= n; cur += lowbit(cur) )
			tree[cur] += val;
	}

	int query( i32 cur ) {
		if( cur == 0 ) 
			return 0;
		i32 res = 0;
		for( ; cur; cur -= lowbit(cur) ) 
			res += tree[cur];
		return res;
	}
} bit;

int size[N], dfn[N], idx;
void dfs( i32 cur, i32 la ) {
	size[cur] = 1; dfn[cur] = idx; idx ++;
	for( int i = ehead[cur]; i; i = e[i].next ) {
		if( e[i].to == la ) 
			continue;
		dfs( e[i].to, cur );
		size[cur] += size[ e[i].to ];
	}
}

int main() {
#ifdef woshiluo
	freopen( "g.in", "r", stdin );
	freopen( "g.out", "w", stdout );
#endif

	i32 T = read<i32>();
	while( T -- ) {
		ci32 n = read<i32>();
		ci32 q = read<i32>();

		bit.init( n + 5 );
		ecnt = 0; idx = 1;
		memset( ehead, 0, sizeof(int) * ( n + 1 ) );

		std::vector<int> p( n + 1 );
		struct Op { int id, x; };
		std::vector<std::vector<Op>> add( n + 1 ), del( n + 1 );

		for( int i = 1; i < n; i ++ ) {
			ci32 u = read<i32>();
			ci32 v = read<i32>();
			add_edge( u, v );
			add_edge( v, u );
		}
		dfs(1, 0);
		for( int i = 1; i <= n; i ++ ) {
			scanf( "%d", &p[i] );
		}
		for( int i = 1; i <= q; i ++ ) {
			ci32 l = read<i32>();
			ci32 r = read<i32>();
			ci32 x = read<i32>();
			add[l].push_back( (Op) { i, x } );
			del[r].push_back( (Op) { i, x } );
		}
		std::vector<int> ans( q + 1 );
		for( int i = 1; i <= n; i ++ ) {
			for( auto &op: add[i] ) {
				ans[ op.id ] -= bit.query( dfn[op.x] + size[ op.x ] - 1 ) - bit.query( dfn[op.x] - 1 );
			}
			bit.add( dfn[ p[i] ], 1 );
			for( auto &op: del[i] ) {
				ans[ op.id ] += bit.query( dfn[op.x] + size[ op.x ] - 1 ) - bit.query( dfn[op.x] - 1 );
			}
		}
		for( int i = 1; i <= q; i ++ ) {
			if( ans[i] > 0 ) 
				printf( "YES\n" );
			else
				printf( "NO\n" );
		}
		printf( "\n" );
	}

}
