#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n,m;
int a[N],b[N];
ll ans=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m,cmp);
	int p=1,cnt=0;
	for(int i=1;i<=m;i++){
		if(cnt+1<=b[i]){
			cnt++;
			ans+=a[p];
		}else{
			p++;
			if(p>n){
				cout<<-1;
				return 0;
			}
			cnt=1;
			ans+=a[p];
		}
	}
	cout<<ans;
	return 0;
}

