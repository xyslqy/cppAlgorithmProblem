#include<bits/stdc++.h>
#define ll long long
using namespace std;
stack <ll> s;
string str="",ans,ss;
ll p[130],k,len;
int cal(){
	p['+']=1;
	p['-']=1;
	p['*']=2;
	p['/']=2;
	p['^']=3;
	str='(' + str + ')';
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='(')  s.push(i);
		else if(str[i]==')')
		{
			if(s.empty())
			{
				str.erase(i,1);
				i--;
			}
			else s.pop();
		}
	}
	while(!s.empty())
	{
		str.erase(s.top(),1);
		s.pop();
	}
	for(int i=0;i<str.length();i++)
	    if(str[i]=='('&&str[i+1]=='-')  str.insert(i+1,"0");
	for(int i=0;i<str.length();i++)
	{
		if(str[i]<='9'&&str[i]>='0') 
		{
			ans+=str[i];
			if(!(str[i+1]<='9' && str[i+1]>='0'))  ans+='.';
		}
		else if(str[i]=='(' )  s.push('(');
		else if(str[i]==')' )
		{
			while(s.top() != '(')
			{
				ans+=s.top();
				s.pop();
			}
			s.pop();
		}
		else
		{
			while(!s.empty()&&p[s.top()]>=p[str[i]])
			{
			    ans+=s.top();
				s.pop();
			}
			s.push(str[i]); 
		} 
	} 
	while(!s.empty())
	{
		ans+=s.top();
		s.pop();
    }
	str=ans;
	for( int i=0;i<str.length();i++)
	{
		if(str[i]>='0' && str[i]<='9')  k=k*10+str[i]-'0';
		else if(str[i]=='.')
		{
			s.push(k);
			k=0;
		}
		else
		{
			ll a,b;
			b=s.top();s.pop();a=s.top();s.pop();
			if(str[i] == '+')  s.push(a+b);
			if(str[i] == '-')  s.push(a-b);
			if(str[i] == '*')  s.push(a*b);
			if(str[i] == '/')  s.push(a/b); 
			if(str[i] == '^')  s.push(pow(a,b));
		} 
	} 
	return s.top();
}
string s1,t,n;
int main(){
	cin>>s1>>t;
	cin>>n;
	string a="";
	for(int i=0;i<s1.length();i++){
		if(s1[i]=='x'){
			a+=t;
		}else{
			a+=s1[i];
		}
	}
	for(int i=0;i<a.length();i++){
		if(a[i]=='x'){
			str+=n;
		}else{
			str+=a[i];
		}
	}
	cout<<str<<endl;
	cout<<cal();
	return 0;
}

