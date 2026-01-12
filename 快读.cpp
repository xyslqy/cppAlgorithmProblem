#include<bits/stdc++.h>
#define ll long long
#define gc() getchar_unlocked()
using namespace std;
int inline read(){
	int x=0,f=1;char c=gc();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=gc();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=gc(); 
	}
	return x*f;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
ll n,ans=0;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		ll x=read();
		ans+=x;
	}
	write(ans);
	return 0;
}

