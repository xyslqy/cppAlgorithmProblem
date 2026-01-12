#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,k,q;
int l[100005];
vector<int> s[100005];
int f[105][200005];
void collect(int r,int x,int y){
	for(int i=1;i<k&&(y+i<l[x]);i++){
		if(f[r+1][s[x][y+i]]==-1) f[r+1][s[x][y+i]]=x;
		else if(f[r+1][s[x][y+i]]!=x) f[r+1][s[x][y+i]]=0;
	}
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			s[i].clear();
			cin>>l[i];
			for(int j=0;j<l[i];j++){
				int tmp;
				cin>>tmp;
				s[i].push_back(tmp);
			}
		}
		memset(f,-1,sizeof(f));
		f[1][1]=0;
		for(int i=1;i<=101;i++){
			for(int j=1;j<=n;j++){
				int cnt=0;
				for(int x=0;x<l[j];x++){
					if(cnt>0){
						cnt--;
						if(f[i+1][s[j][x]]==-1)f[i+1][s[j][x]]=j;
						else if(f[i+1][s[j][x]]!=j) f[i+1][s[j][x]]=0;
					}
					if(f[i][s[j][x]]!=-1&&f[i][s[j][x]]!=j){
						cnt=k-1;
					}
				}
			}
		}
		for(int i=0;i<q;i++){
			int r,c;
			cin>>r>>c;
			if(f[r+1][c]!=-1)cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}

