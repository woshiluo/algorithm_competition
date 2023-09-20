#include<cstdio>
#include<bitset>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e9+5,MOD=1e9+7;
int T,n,*h,*p;
char *mu;
bitset<N> np;
void sieve() {
	n=int(1e9);
	mu[1]=1;
	h[1]=1;
	const int S=1<<26;
	fr(i,2,n) {
		if(!np[i]) p[++p[0]]=i,mu[i]=-1,h[i]=i;
		for(int j=1,ni;j<=p[0]&&(ni=i*p[j])<=n;++j) {
			np[ni]=1;
			if(i%p[j]==0) {
				h[ni]=h[i];
				break;
			}
			h[ni]=h[i]*p[j];
			mu[ni]=-mu[i];
		}
		if(i%S==0)
			cout<<h[i]<<' '<<int(mu[i])<<endl;
	}
}
int main() {
	h=new int[N];
	p=new int[N/10];
	mu=new char[N];
	memset(h,0,sizeof(int)*N);
	memset(p,0,sizeof(int)*(N/10));
	memset(mu,0,sizeof(char)*N);
	sieve();
	return 0;
}
