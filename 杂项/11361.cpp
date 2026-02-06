#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+1;
int t,n,tot1,tot2,ans;
string s1,s2,t1,t2;
int p1[N],p2[N],h1[N],h2[N],hh1[N],hh2[N];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>s1>>s2>>t1>>t2;
		memset(p1,0,sizeof(p1));
		memset(p2,0,sizeof(p2));
		memset(h1,0,sizeof(h1));
		memset(h2,0,sizeof(h2));
		memset(hh1,0,sizeof(hh1));
		memset(hh2,0,sizeof(hh2));
		tot1=tot2=p1[0]=p2[0]=1;
		if(s1[0]=='1'){
			h1[p1[0]]++;
		}else{
			hh1[p1[0]]++;
		}
		if(s2[0]=='1'){
			h2[p2[0]]++;
		}else{
			hh2[p2[0]]++;
		}
		ans=0;
		for(int i=1;i<n;i++){
			if(t1[i-1]=='0'||t1[i]=='0'){
				p1[i]=++tot1;
			}else{
				p1[i]=tot1;
			}
			if(t2[i-1]=='0'||t2[i]=='0'){
				p2[i]=++tot2;
			}else{
				p2[i]=tot2;
			}
			if(s1[i]=='1'){
				h1[p1[i]]++;
			}else{
				hh1[p1[i]]++;
			}
			if(s2[i]=='1'){
				h2[p2[i]]++;
			}else{
				hh2[p2[i]]++;
			}
		}
		for(int i=0;i<n;i++){
			if(h1[p1[i]]&&h2[p2[i]]){
				ans++;
				h1[p1[i]]--;
				h2[p2[i]]--;
			}else if(hh1[p1[i]]&&hh2[p2[i]]){
				ans++;
				hh1[p1[i]]--;
				hh2[p2[i]]--;
			}else if(h1[p1[i]]){
				h1[p1[i]]--;
				hh2[p2[i]]--;
			}else{
				h2[p2[i]]--;
				hh1[p1[i]]--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

