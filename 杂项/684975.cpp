#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int ans;
queue<int> a;
signed main(){
	cin>>n>>k;
	int x;
	cin>>x;
	a.push(x);
	ans=x;
	for(int i=1;i<n;i++){
		cin>>x;
		a.push(x);
		ans^=x;
	}
	for(int i=1;i<k;i++){
		ans^=ans;
		ans^=a.front();
		a.pop();
		a.push(ans);
	}
	cout<<ans;
	return 0;
}

