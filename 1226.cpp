#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,p;
int po(int a,int b,int p){
	int res=1;
	while(b!=0){
		if(b%2==1) res=res*a%p;
		a=a*a%p;
		b/=2;
	}
	return res;
}
signed main(){
	cin>>a>>b>>p;
	cout<<a<<'^'<<b<<" mod "<<p<<"="<<po(a,b,p);
	return 0;
}

