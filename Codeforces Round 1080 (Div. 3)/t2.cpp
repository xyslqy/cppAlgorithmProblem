#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005];
bool vis[200005];
vector<int> vec;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			vis[i]=false;
		}
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			vec.clear();
			for(int j=i;j<=n;j*=2){
				vis[j]=true;
				vec.push_back(a[j]);
			}
			sort(vec.begin(),vec.end());
			for(int j=i,k=0;j<=n;j*=2,k++){
				a[j]=vec[k];
			}
		}
		bool flag=true;
		for(int i=2;i<=n;i++){
			if(a[i]<a[i-1]){
				flag=false;
				cout<<"NO\n";
				break;
			}
		}
		if(flag){
			cout<<"YES\n";
		}
	}
	return 0;
}

