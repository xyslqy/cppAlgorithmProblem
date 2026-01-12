#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a,b,c,d,dx,dy;
int x=0,y=0;
signed main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c>>d>>dx>>dy;
		if(a>b) swap(a,b);
		if(c>d) swap(c,d);
		if(x>a&&x<b&&y>c&&y<d){
			int kx=0x3f3f3f3f,ky=0x3f3f3f3f;
			if(dx>0) kx=(b-x)/dx+((b-x)%dx==0?0:1);
			if(dx<0) kx=(a-x)/dx+((a-x)%dx==0?0:1);
			if(dy>0) ky=(d-y)/dy+((d-y)%dy==0?0:1);
			if(dy<0) ky=(c-y)/dy+((c-y)%dy==0?0:1);
			int k=min(kx,ky);
			x=x+dx*k;
			y=y+dy*k;
		}
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}

