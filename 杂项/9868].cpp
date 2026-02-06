#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int mx[3005],mi[3005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		mi[i]=0x3f3f3f3f;
		for(int j=0;j<m;j++){
			mx[i]=max(s[j]-'a',mx[i]);
			mi[i]=min(s[j]-'a',mi[i]);
		}
	}
	for(int i=1;i<=n;i++){
		bool flag=true;
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			if(mi[i]>=mx[j]){
				cout<<0;
				flag=false;
				break;
			}
		}
		if(flag) cout<<1;
	}
	return 0;
}

