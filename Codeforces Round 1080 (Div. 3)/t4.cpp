#include<bits/stdc++.h>
using namespace std;
int t,n;
long double x[300005][2],c[300005][2];
long double p(int i,int j){
	if((i==j&&i==1)||(i==j&&i==n))return -((long double)n-2)/(2*(n-1));
	else if((i==1&&j==n)||(i==n&&j==1))return (long double)1/(2*(n-1));
	else if(abs(i-j)==1) return 0.5;
	else if(i==j&&2<=i&&i<=n-1)return -1;
	else return 0;
}
int main(){
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i][1];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=1;j++){
				c[i][j]=0;
				for(int k=1;k<=n;k++){
					c[i][j]+=p(i,k)*x[k][j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			cout<<round(c[i][1])<<" ";
		}
		cout<<endl;
	}
	return 0;
}

