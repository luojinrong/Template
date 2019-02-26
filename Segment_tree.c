//线段树
#include <stdio.h>
#include <string.h>
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)>(b)?(b):(a)
#define maxn 100005

struct treenode{
	int maxa,minb,addmark,sum;
}node[maxn*4];

int n,q,a[maxn],b[maxn],l,r,ans;
char cz[10];

void pushUp(int root){
	node[root].maxa=max(node[root*2+1].maxa,node[root*2+2].maxa);
	node[root].minb=min(node[root*2+1].minb,node[root*2+2].minb);
	node[root].sum=node[root*2+1].sum+node[root*2+2].sum;
}

void build(int root,int nstart,int nend){
	node[root].addmark=0;
	if(nstart==nend){
		node[root].minb=b[nstart];
		node[root].maxa=node[root].sum=0;
		return;
	}
	int mid=(nstart+nend)>>1;
	build(root*2+1,nstart,mid);
	build(root*2+2,mid+1,nend);
	pushUp(root);
}

void pushDown(int root){
	if(node[root].addmark){
		node[root*2+1].addmark+=node[root].addmark;
		node[root*2+2].addmark+=node[root].addmark;
		node[root*2+1].maxa+=node[root].addmark;
		node[root*2+2].maxa+=node[root].addmark;
		node[root].addmark=0;
	}
}

void add(int root,int nstart,int nend,int astart,int aend){
	if(nstart>aend||nend<astart){
		return;
	}
	else if(astart<=nstart&&aend>=nend){
		node[root].maxa+=1;
		if(node[root].maxa<node[root].minb){
			node[root].addmark+=1;
			return;
		}
		if(nstart==nend&&node[root].maxa>=node[root].minb){
			node[root].sum+=1;
			node[root].minb+=b[nstart];
			return;
		}
	}
	pushDown(root);
	int mid=(nstart+nend)>>1;
	add(root*2+1,nstart,mid,astart,aend);
	add(root*2+2,mid+1,nend,astart,aend);
	pushUp(root);
}

void query(int root,int nstart,int nend,int qstart,int qend){
	if(nstart>qend||nend<qstart){
		return;
	}
	else{
		if(nstart>=qstart&&nend<=qend){
			ans+=node[root].sum;
			return;
		}
		pushDown(root);
		int mid=(nstart+nend)>>1;
		query(root*2+1,nstart,mid,qstart,qend);
		query(root*2+2,mid+1,nend,qstart,qend);
	}
}

int main(){
	while(scanf("%d%d",&n,&q)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		build(0,0,n-1);
		for(int Q=0;Q<q;Q++){
			scanf("%s%d%d",cz,&l,&r);
			if(!strcmp(cz,"add")){
				add(0,0,n-1,l-1,r-1);
			}
			else if(!strcmp(cz,"query")){
				ans=0;
				query(0,0,n-1,l-1,r-1);
				printf("%d\n",ans);
			}
		}
	}
}
