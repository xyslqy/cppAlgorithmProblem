#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
struct num{
	int i,n;
}a[500005];
int ans[500005];
bool cmp(num a,num b){
	return a.n>b.n;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].n;
		a[i].i=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(a[1].n<=j-i&&a[i].n<=n-j+1&&a[j].n<=i-1){
				cout<<"YES"<<endl;
				for(int k=1;k<=i-1;k++) ans[a[k].i]=1;
				for(int k=i;k<=j-1;k++) ans[a[k].i]=2;
				for(int k=j;k<=n;k++)   ans[a[k].i]=3;
				for(int k=1;k<=n;k++)   cout<<ans[k];
				return 0;
			}
			if(a[1].n<=n-j+1&&a[i].n<=i-1&&a[j].n<=j-1){
				cout<<"YES"<<endl;
				for(int k=1;k<=i-1;k++) ans[a[k].i]=1;
				for(int k=i;k<=j-1;k++) ans[a[k].i]=3;
				for(int k=j;k<=n;k++)   ans[a[k].i]=2;
				for(int k=1;k<=n;k++)   cout<<ans[k];
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}

