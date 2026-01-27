#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int b[300005],mx[300005],ans=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++){
		mx[i]=max(mx[i-1],b[i]+i);
	}
	for(int i=1;i<=n;i++){
		if(max(mx[i-1],mx[n]-1)<=b[i]+n) ans++;
	}
	cout<<ans;
	return 0;
}

