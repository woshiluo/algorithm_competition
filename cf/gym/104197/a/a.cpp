/*
 * a.cpp 2023-10-18
 * Copyright (C) 2023 Woshiluo Luo <woshiluo.luo@outlook.com>
 *
 * 「Two roads diverged in a wood,and I—
 * I took the one less traveled by,
 * And that has made all the difference.」
 *
 * Distributed under terms of the GNU GNU AGPLv3+ license.
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <queue>
#include <vector>
#include <algorithm>

typedef const int cint;
typedef long long ll;
typedef unsigned long long ull;

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
T pow( T a, int p ) {
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
	freopen( "a.in", "r", stdin );
	freopen( "a.out", "w", stdout );
#endif

	int T = read<int>();
	while( T -- ) {
		cint n = read<int>();
		std::vector<int> a(n);
		for( auto &x: a ) 
			x = read<int>();
		std::sort( a.begin(), a.end() );
		std::deque<int> q;
		q.push_back( a.back() ); a.pop_back();
		int flag = 0;
		while( !a.empty() ) {
			if( flag ) 
				q.push_front( a.back() );
			else
				q.push_back( a.back() );
			flag ^= 1;
			a.pop_back();
		}

		while( !q.empty() ) {
			a.push_back( q.front() );
			q.pop_front();
		}
		
		ll res = 0;
		for( int i = 1; i < n; i ++ ) 
			res += 1LL * a[i] * a[ i - 1 ];
		res += 1LL * a[0] * a.back();
		
		printf( "%lld\n", res );
	}
}