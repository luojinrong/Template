//归并排序求逆序对

#include <stdio.h>
#define maxn 1005
typedef long long ll;
ll n,a[maxn],c[maxn],ans;

void msort(int l,int r){
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	msort(l,mid);
	msort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]){
			c[k++]=a[j++];
		}
		else{
			c[k++]=a[j++];
			ans+=(mid-i+1);
		}
	}
	while(j<=mid){
		c[k++]=a[i++];
	}
	while(j<=r){
		c[k++]=a[j++];
	}
	for(i=l;i<=r;i++){
		a[i]=c[i];
	}
}

int main(){
	while(~scanf("%lld",&n)){
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		msort(0,n-1);
		printf("%lld\n",ans);
	}
}
