#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7,N=1e5+10;
int q,ans=0;
int f[N],a[N];
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1==1) res=(ll)res*x%mod;
		y>>=1;
		x=(ll)x*x%mod;
	}
	return res;
}
int main(){
	int x=0,tot1=0,tot2=0;
	f[0]=1;
	while(true){
		char c=getchar();
		if(c>='0'&&c<='9'){
			x=x*10-'0'+c;
		}else{
			a[++tot1]=x;
			x=0;
			if(c=='+'){
				f[++tot2]=1;
			}
			else if(c=='-'){
				f[++tot2]=-1;
			}else if(c=='*'){
				f[++tot2]=0;
			}else{
				break;
			}
			
		}
	}
	x=1;
	int ff=1;
	for(int i=1;i<=tot1;i++){
		x=(ll)x*a[i]%mod;
		if(f[i]!=0){
			ans=((ll)ans+(ll)ff*x%mod)%mod;
			x=1;
			ff=f[i];
		}
	} 
	cin>>q;
	while(q--){
		int k,c;
		char cc;
		cin>>k>>cc>>cc;
		if(cc=='+') c=1;
		if(cc=='-') c=-1;
		if(cc=='*') continue;
		if(f[k]==0){
			int cnt=a[k];
			for(int i=k-1;f[i]==0&&i>=1;i--){
				cnt=(ll)cnt*a[i]%mod;
			}
			for(int i=k+1;f[i-1]==0&&i<=tot1;i++){
				cnt=(ll)cnt*a[i]%mod;
			}
			ans=(ll)ans
			f[k]=c;
			
		}
	}
	return 0;
}

