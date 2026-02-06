#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,na,nb,as=0,bs=0;
int a[201],b[201];
int f[5][5]={
	{0,0,1,1,0},
	{1,0,0,1,0},
	{0,1,0,0,1},
	{0,0,1,0,1},
	{1,1,0,0,0},
};
signed main(){
	cin>>n>>na>>nb;
	for(int i=0;i<na;i++){
		cin>>a[i];
	}
	for(int i=0;i<nb;i++){
		cin>>b[i];
	}
	int i=0,j=0;
	for(int k=0;k<n;k++){
		as+=f[a[i]][b[j]];
		bs+=f[b[j]][a[i]];
		i++;
		j++;
		if(i==na){
			i=0;
		}
		if(j==nb){
			j=0;
		}
	}
	cout<<as<<" "<<bs;
	return 0;
}

