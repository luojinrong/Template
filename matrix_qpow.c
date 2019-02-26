#include <stdio.h>
#define maxn 105
#define max(a,b) {(a)>(b)?(a):(b)}
#define min(a,b) {(a)>(b)?(b):(a)}
typedef long long ll;
struct matrix{
	ll m[maxn][maxn];
}begin,one;
ll n,m;

void mat_times(struct matrix*a,struct matrix*b){
	struct matrix ans;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans.m[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				ans.m[i][j]+=a->m[i][k]*b->m[k][j];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a->m[i][j]=ans.m[i][j];
		}
	}
}

void mat_qpow(ll b){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			one.m[i][j]=i==j?1:0;
		}
	}
	while(b){
		if(b%2){
			mat_times(&one,&begin);
		}
		mat_times(&begin,&begin);
		b>>=1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			begin.m[i][j]=one.m[i][j];
		}
	}
}

int main(){
	struct matrix zj;
	zj.m[0][0]=zj.m[1][0]=1;zj.m[0][1]=zj.m[1][1]=0;
	n=2;
	while(~scanf("%lld",&m)){
		begin.m[0][0]=begin.m[1][0]=begin.m[0][1]=1;begin.m[1][1]=0;
		if(m==1||m==2){
			printf("1\n");
		}
		else{
			mat_qpow(m-2);
			mat_times(&begin,&zj);
			printf("%lld\n",begin.m[0][0]);
		}
	}
}
