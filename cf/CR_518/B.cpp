#include <cstdio>

long long ans,b,tmp;

int main(){
	scanf("%lld",&b);
	for(long long i=1;i*i<=b;i++){
		if(b%i==0){
			ans+=2;
			if(i*i==b) ans--;
		}
	}
	printf("%lld",ans);
}
