#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,f[500005];
ll l[500005],sum[500005],ans;
string s;
stack<int> st;
vector<int> b[500005];
int dfs(int x){
	int t=0;
	if(s[x-1]=='('){
		st.push(x);
	}else{
		t=st.top();
		st.pop();
		l[x]=l[f[t]]+1;
	}
	sum[x]=sum[f[x]]+l[x];
	for(int y:b[x]){
		dfs(y);
	}
	if(t!=0)st.push(t);
	else if(!st.empty()) st.pop();
}
signed main(){
	cin>>n>>s;
	for(int i=2;i<=n;i++){
		cin>>f[i];
		b[f[i]].push_back(i);
	}
	dfs(1);
	for(int i = 1; i <= n; i ++)
		ans ^= sum[i] * (ll)i;
	printf("%lld", ans);
	return 0;
}

