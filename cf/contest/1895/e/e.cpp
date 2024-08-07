/*
 * e.cpp 2023-11-03
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

const int N = 1e6 + 1e4;

struct Card { i32 id, x, y; };

struct SegmentTree {/*{{{*/
	int n;
	struct Data { 
		int max, id; 
		Data operator+ ( const Data &_b ) const {
			if( _b.max > max )
				return _b;
			else
				return *this;
		}
	} tree[ N << 2 ];

	void build( ci32 cur, ci32 left, ci32 rig, std::vector<Data> &data ) {
		if( left == rig ) {
			tree[cur] = data[left];
			return ;
		}

		ci32 mid = ( left + rig ) >> 1;
		build( cur << 1, left, mid, data );
		build( cur << 1 | 1, mid + 1, rig, data );

		push_up(cur);
		
	}
	void init( ci32 _n, std::vector<Data> &data ) {
		n = _n;
		build( 1, 1, n, data );
	}

	void push_up( ci32 cur ) { tree[cur] = tree[ cur << 1 ] + tree[ cur << 1 | 1 ]; }

	Data query( ci32 from, ci32 to, ci32 cur, ci32 left, ci32 rig ) {
		if( from <= left && rig <= to ) 
			return tree[cur];
		ci32 mid = ( left + rig ) >> 1;

		Data res = { 0, 0 };
		if( from <= mid ) 
			res = res + query( from, to, cur << 1, left, mid );
		if( to > mid ) 
			res = res + query( from, to, cur << 1 | 1, mid + 1, rig );

		return res;
	}
	Data query( ci32 from, ci32 to ) { return query( from, to, 1, 1, n ); }
} sgt_a, sgt_b;/*}}}*/

struct Edge {
	i32 to, next;
} e[ N << 1 ];
int ehead[N], ecnt;
void add_edge( ci32 from, ci32 to ) {
	ecnt ++;
	e[ecnt].to = to;
	e[ecnt].next = ehead[from];
	ehead[from] = ecnt;
}

// 0 lose
// 1 win
// 2 draw
void dfs( ci32 cur, std::vector<i32> &sg, std::vector<bool> &vis ) {
	vis[cur] = true;
	bool has_circle = false;
	int p = 0, size = 0;
	for( int i = ehead[cur]; i; i = e[i].next ) {
		ci32 to = e[i].to;
		size ++;
		if( vis[to] && sg[to] == -2 ) {
			has_circle = true;
			continue;
		}
		if( !vis[to] )
			dfs( to, sg, vis );
		if( sg[to] == 0 ) 
			p = 1;
		if( sg[to] == 2 ) 
			has_circle = true;
	}
	if( size == 0 || p == 1 ) 
		sg[cur] = 1;
	else if( has_circle ) 
		sg[cur] = 2;
	else
		sg[cur] = 0;
}

int main() {
#ifdef woshiluo
	freopen( "e.in", "r", stdin );
	freopen( "e.out", "w", stdout );
#endif

	i32 T = read<i32>();
	while( T -- ) {
		i32 counter = 0;
		ci32 n = read<i32>();
		std::vector<int> nums;
		std::vector<Card> a(n);
		for( auto &[id, x, y]: a ) {
			counter ++;
			id = counter;
			x = read<i32>();
			nums.push_back(x);
		}
		for( auto &[id, x, y]: a ) {
			y = read<i32>();
			nums.push_back(y);
		}
		ci32 m = read<i32>();
		std::vector<Card> b(m);
		for( auto &[id, x, y]: b ) {
			counter ++;
			id = counter;
			x = read<i32>();
			nums.push_back(x);
		}
		for( auto &[id, x, y]: b ) {
			y = read<i32>();
			nums.push_back(y);
		}
		std::sort( nums.begin(), nums.end() );
		nums.erase( std::unique( nums.begin(), nums.end() ), nums.end() );
		auto find = [&nums] ( ci32 cur ) { return std::lower_bound( nums.begin(), nums.end(), cur ) - nums.begin() + 1; };
		for( auto &[_, x, y]: a ) {
			x = find(x);
			y = find(y);
		}
		for( auto &[_, x, y]: b ) {
			x = find(x);
			y = find(y);
		}

		ci32 tot = nums.size() + 5;
		{
			std::vector<SegmentTree::Data> max_a(tot + 1);
			for( auto &[id, x, y]: a ) {
				if( y > max_a[x].max ) {
					max_a[x] = { y, id };
				}
			}
			sgt_a.init( tot, max_a );
		}
		{
			std::vector<SegmentTree::Data> max_b(tot + 1);
			for( auto &[id, x, y]: b ) {
				if( y > max_b[x].max ) {
					max_b[x] = { y, id };
				}
			}
			sgt_b.init( tot, max_b );
		}

		ecnt = 0;
		memset( ehead, 0, sizeof(i32) * ( n + m + 5 ) );
//		std::vector<i32> in_degree( n + m + 1 );
		for( auto &[id, x, y]: a ) {
			const auto data = sgt_b.query( y + 1, tot );
			if( data.id == 0 ) 
				continue;
			add_edge( id, data.id );
		}
		for( auto &[id, x, y]: b ) {
			const auto data = sgt_a.query( y + 1, tot );
			if( data.id == 0 ) 
				continue;
			add_edge( id, data.id );
		}

		std::vector<i32> sg( n + m + 2, -2 );
		std::vector<bool> vis( n + m + 2, false );
		std::vector<i32> count(3);
		for( int i = 1; i <= n; i ++ ) {
			dfs( i, sg, vis );
			count[ sg[i] ] ++;
		}
		printf( "%d %d %d\n", count[1], count[2], count[0] );
	}
}
