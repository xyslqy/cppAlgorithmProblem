#include<bits/stdc++.h>
#define ll long long
using namespace std;
char s1[1000005],s2[1000005];
int nxt[1000005];
int main(){
	cin>>s1+1>>s2+1;
	int n=strlen(s2+1),m=strlen(s1+1);
	int j=0;
	for(int i=2;i<=n;i++){
		while(j!=0&&s2[j+1]!=s2[i]) j=nxt[j];
		if(s2[j+1]==s2[i]) j++;
		nxt[i]=j;
	}
	j=0;
	for(int i=1;i<=m;i++){
		while(j!=0&&s2[j+1]!=s1[i]) j=nxt[j];
		if(s2[j+1]==s1[i]) j++;
		if(j==n){
			cout<<i-n+1<<"\n";
			j=nxt[j];
		}
	}
	for(int i=1;i<=n;i++){
		cout<<nxt[i]<<" ";
	}
	return 0;
}

