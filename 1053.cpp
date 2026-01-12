#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int e[50005][2];
int w[50005];
int a[50005],b[50005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>e[i][0]>>e[i][1];
	}
	w[1]=1;
	w[2]=e[1][1];
	for(int i=2;i<=n-1;i++){
		if(w[i-1]==e[w[i]][0]){
			w[i+1]=e[w[i]][1];
		}
		else if(w[i-1]==e[w[i]][1]){
			w[i+1]=e[w[i]][0];
		}
		else{
			cout<<-1;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		a[(w[i]-i+n)%n]++;
		b[(w[i]-(n-i+1)+n)%n]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,max(a[i],b[i]));
	}
	cout<<n-ans;
	return 0;
}

