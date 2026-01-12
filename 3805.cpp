#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
char s[22000005],ss[22000005];
int r[22000005];
int main(){
	cin>>ss;
	n=strlen(ss);
	int idx=0;
	for(int i=0;i<n;i++){
		s[++idx]='#';
		s[++idx]=ss[i];
	}
	s[++idx]='#';
	n=idx;
	int piv=2;
	int ans=0;
	for(int i=2;i<=n;i++){
		if(piv+r[piv]<i)piv=i;
		int j=piv-i+piv;
		if(j-r[j]>=piv-r[piv]){
			r[i]=r[j];
			if(j-r[j]==piv-r[piv]) for(int k=i+r[i]+1;k<=n;k++){
				if(i-k+i<=0) break;
				if(s[k]==s[i-k+i]){
					r[i]++;
				}else break;
			}
		}else{
			r[i]=j-piv+r[piv];
		}
		ans=max(ans,r[i]/2+r[i]/2+(s[i]!='#'));
		if(r[i]+i>=r[piv]+piv) piv=i;
	}
	cout<<ans;
	return 0;
}

