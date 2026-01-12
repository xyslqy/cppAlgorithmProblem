#include<bits/stdc++.h>
using namespace std;
int n,k;
struct score{
	bool b=false;
	int cnt=0;
	string xh;
}s[1000]; 
int main(){
	cin>>n>>k;
	double cj;
	string xh;
	for(int i=0;i<n;i++){
		cin>>xh>>cj;
		int _cj=cj*10;
		if(!s[_cj].b){
			s[_cj].b=true;
			s[_cj].xh=xh;
		}
		s[_cj].cnt++;
	}
	int cnt=0;
	for(int i=1000;i>=0;i--){
		cnt+=s[i].cnt;
		if(cnt>=k){
			cout<<s[i].xh<<' '<<(double)i/10.0;
			break;
		}
	}
	return 0;
}

