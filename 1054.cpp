#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
void init(string &s) {
	int l = 0, r = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') l++;
		else if (s[i] == ')') r++;
		if (l < r) {
			s.erase(i, 1);
			r--;
		}
	}
	s += '@';
}
int gety(char op) {
	switch (op) {
		case '+' : return 1; break;
		case '-' : return 2; break;
		case '*' : return 3; break;
		case '^' : return 4; break;
	}
	return -1;
}
stack <ll> ans;
stack <char> st;
ll pow(ll a, ll b) {
	ll p = 1;
	for (int i = 1; i <= b; i++) {
		p = (p * a) % mod;
	}
	return p;
}
void cz(char op) {
	if (op == '(') {
		return;
	}
	ll n2 = ans.top();
	ans.pop();
	ll n1 = ans.top();
	ans.pop();
	switch (op) {
		case '+' : ans.push(((n1 + n2) + mod) % mod); break;
		case '-' : ans.push(((n1 - n2) + mod) % mod); break;
		case '*' : ans.push(((n1 * n2) + mod) % mod); break;
		case '^' : ans.push((((ll)pow(n1, n2)) + mod) % mod); break;
	}
}
ll calc(string s) {
	init(s);
	bool flag = 0;
	ll sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-' && (s[i - 1] == '(' || i == 0)) {
			flag = 1;
		} else if (s[i] == 'a') {
			sum = 1145;
			if (flag == 1) sum = -sum;
			ans.push(sum);
			flag = 0;
			sum = 0;
		} else if (s[i] >= '0' && s[i] <= '9') {
			sum = sum * 10 + s[i] - '0';
		} else if (s[i - 1] >= '0' && s[i - 1] <= '9'){
			if (flag == 1) sum = -sum;
			ans.push(sum);
			flag = 0;
			sum = 0;
		}
		if (s[i] == ')') {
			while (st.top() != '(') {
				cz(st.top());
				st.pop();
			}
			st.pop();
		} else if (s[i] == '+' || (s[i] == '-' && s[i - 1] != '(' && i != 0) || s[i] == '*' || s[i] == '^') {
			if (st.size() != 0) {
				while (gety(st.top()) >= gety(s[i])) { 
					cz(st.top());
					st.pop();
					if (st.size() == 0) {
						break;
					}
				}
			}
			st.push(s[i]);
		} else if (s[i] == '(') {
			st.push(s[i]);
		}
	}
	while (st.size() != 0) {
		cz(st.top());
		st.pop();
	}
	return ans.top() % mod;
}
int main() {
	string s;
	int n;
	char c = getchar();
	while (c != '\n' && c != '\r') {
		if (c != ' ') {
			s += c;
		}
		c = getchar();
	}
	ll p = calc(s);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		s = "";
		c = getchar();
		while (c == '\n' || c == '\r') {
			c = getchar();
		}
		while (c != '\n' && c != '\r') {
			if (c != ' ') {
				s += c;
			}
			c = getchar();
		}
		if (calc(s) == p) {
			cout << char('A' + i - 1);
		}
	}
	return 0;
}

