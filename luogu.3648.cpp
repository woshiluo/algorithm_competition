#include <cstdio>
#include <deque>

const int N = 1e5 + 1e4;
const int K = 210;

int n, k;
int a[N], sum[N];
int f[N][K];
std::deque<int> q[K];

int main() {
	scanf( "%d%d", &n, &k );
	for( int i = 1; i <= n; i ++ ) {
		scanf( "%d", &a[i] );
		sum[i] = sum[ i - 1 ] + a[i];
	}

	q[0].push(0);
	for( int j = 1; j <= k; j ++ ) {
		for( int i = 1; i <= n; i ++ ) {
		}
	}
}
