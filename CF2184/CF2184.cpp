#include<bits/stdc++.h>
using namespace std;
int t;
int n,now;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		if(n%4==0){
			cout<<0<<endl;
		}else if(n%4==2&&n>2){
			cout<<0<<endl;
		}else if(n%4==1){
			cout<<1<<endl;
		}else if(n%4==3&&n>3){
			cout<<1<<endl;
		}else if(n==2){
			cout<<2<<endl;
		}else cout<<3<<endl;
	}
	return 0;
}

