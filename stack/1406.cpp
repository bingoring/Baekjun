#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<char> L, R;
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		L.push(s[i]);
	}
	int count;
	cin >> count;
	
	while(count--){
		char com;
		cin >> com;
		if (com == 'L') {
			if (!L.empty()) {
				R.push(L.top());
				L.pop();
			}
		}
		if (com == 'D') {
			if (!R.empty()) {
				L.push(R.top());
				R.pop();
			}
		}
		if (com == 'B') {
			if (!L.empty()) {
				L.pop();
			}
		}
		if (com == 'P') {
			char c;
			cin >> c;
			L.push(c);
		}
	}
	while(!L.empty()){
		R.push(L.top());
		L.pop();
	}
	while(!R.empty()){
		cout << R.top();
		R.pop();
	}
	return 0;
}