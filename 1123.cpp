#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[10][10],ans=0;
int dx[9]={-1,-1,-1,0,0,0,1,1,1};
int dy[9]={1,-1,0,1,-1,0,1,-1,0};
int b[10][10];
int dfs(int x,int y){
	if(x==n&&y==m+1) return ans;
	if(y==m+1){
		y=0;
		x++;
	}
	int mx=ans;
	for(;x!=n||y!=m+1;y++){
		if(y==m+1){
			y=0;
			x++;
		}
		if(b[x][y]==0){
			for(int k=0;k<9;k++){
				b[x+dx[k]][y+dy[k]]++;
			}
			ans+=a[x][y];
			int q=dfs(x,y+1);
			if(q>mx) mx=q;
			ans-=a[x][y];
			for(int k=0;k<9;k++){
				b[x+dx[k]][y+dy[k]]--;
			}
		} 
	}
	return mx;
}
int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		cout<<dfs(1,1)<<endl;
	}
	return 0;
}

