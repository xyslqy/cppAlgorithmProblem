#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,f;
int m,x,y,z;
int d[10000001],c;
int p[10000001];
signed main(){
	cin>>n>>f;
	if(f==1){
		for(int i=0;i<n;i++){
			cin>>d[i];
		}
	}else{
		cin>>m>>x>>y>>z;
		for(int i=1;i<=n;i++){
			if(1<=i&&i<=m){
				cin>>c;
				d[i]=c;
			}else{
				d[i]=((x*d[i-2]+y*d[i-1]+z)%(int)1e9)+1;
			}
		}
	}
	int mi=1;
	for(int i=1;i<=n;i++){
		p[i]=0;
		int j=i;
		int k=0;
		do{
			p[i]=max(p[i],d[j]-k);
			k++;
			j++;
			if(j>n){
				j=1;
			}
		}while(j!=i);
		if(p[i]<p[mi]){
			mi=i;
		}
	}
	cout<<p[mi]<<' '<<mi;
	return 0;
}

