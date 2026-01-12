#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s1,s2;
string s;
int boder[20000000];
int main(){
	cin>>s1>>s2;
	s=s2+"#"+s1;
	int n=s.length(),m=s2.length();
	for(int i=1;i<n;i++){
		int j=boder[i-1];
		while(j>0&&s[i]!=s[j]) j=boder[j-1];
		if(s[i]==s[j]) boder[i]=j+1;
		if(boder[i]==m) cout<<i-m-m+1<<endl;
	}
	for(int i=0;i<m;i++){
		cout<<boder[i]<<" ";
	}
	return 0;
}

