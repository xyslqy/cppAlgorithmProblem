#include<bits/stdc++.h>
using namespace std;
int n,q;
bool b;
vector<int> prime;
signed main(){
	std::ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		b=0;
		for(int p:prime){
			if(i%p==0){
				b=1;
				break;
			}
		}
		if(!b){
			prime.push_back(i);
		}
	}
	int k;
	for(int i=0;i<q;i++){
		cin>>k;
		cout<<prime[k-1]<<'\n';
	}
	return 0;
}

