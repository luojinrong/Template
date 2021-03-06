//a^b%m=a^(b%f(m))
//其中 f(m) 为欧拉函数
//

#include<stdio.h>
#include<string.h>
typedef long long ll;
const ll maxn=1e5+5,m=1e9+7;
char s[100005];
ll qpow(ll a,ll b){//快速幂
	ll r=1,base=a;
	while(b){
		if(b%2){
			r=r*base%m;
		}
		base=base*base%m;
		b>>=1;
	}
	return r;
}

ll mod(){//求b%f(m)
	ll len=strlen(s),ans=0;
	for(int i=0;i<len;i++){
		ans=ans*10+(s[i]-'0');
		ans%=(m-1);
	}
	return ans;
}

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%s",s);
		ll t=mod();
		printf("%lld\n",qpow(2,t));
	}
}
