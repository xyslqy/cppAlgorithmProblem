#include<bits/stdc++.h>
using namespace std;
int t,n;
vector<int> vec;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		vec.clear();
		vec.push_back(1);
		bool ans=false;
		for(int i=1;i<=n;i++){
			int x,siz=vec.size();
			cin>>x;
			if(x!=0&&!ans) for(int i=0;i<siz;i++){
				if(x*vec[i]<=67){
					vec.push_back(x*vec[i]);
					if(x*vec[i]==67){
						ans=true;
						break;
					}
				}
			}
		}
		if(ans){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	return 0;
}

