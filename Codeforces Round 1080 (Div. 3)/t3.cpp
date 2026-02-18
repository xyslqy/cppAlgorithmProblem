#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int t,n;
int a[N];
bool f[N];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i-1]==a[i]||a[i-1]==7-a[i]) f[i]=true;
			else f[i]=false;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(f[i]){
				ans++;
				f[i]=0;
				f[i+1]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

