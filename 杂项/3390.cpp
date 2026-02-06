#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;

struct mat{
	int a[101][101];
	mat(){
		memset(a,0,sizeof(a));
	}
	mat(int x){
		memset(a,0,sizeof(a));
		for(int k=0;k<n;k++){
			a[k][k]=x;
		}
	}
	
}; 
mat operator * (mat a,mat b){
	mat c=mat();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				c.a[i][j]=a.a[i][k]*b.a[k][j];
			}
		}
	}
	return c;
}

mat pow(mat a,int k){
	mat r=mat(1);
	
	while(k){
		if(k&1){
			r=r*a;
		}
		a=a*a;
		k>>1;
	}
	return r;
}
mat a;
signed main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a.a[i][j];
		}
	}
	mat c=pow(a,k);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<c.a[i][j];
		}
	}
	return 0;
}

