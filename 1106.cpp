#include<bits/stdc++.h>
#define int long long
using namespace std;
string n;
int k; 
signed main(){
	cin>>n>>k;
	n+="0"; 
	for(int i=0;i<n.length();i++){
		if(n[i]<n[i+1]){
			cout<<n[i];
		}
	}
	return 0;
}

