#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	
	
	while(n--){
		list<char> L;
		list<char>::iterator cur = L.end();
		string s;
		cin >> s;
		
		for(int i = 0; i < s.length(); i++){
			char c = s.at(i);
			
			if(c == '<'){
				if(cur != L.begin()) cur--;
			}else if(c == '>'){
				if(cur != L.end()) cur++;
			}else if(c == '-'){
				if(cur != L.begin()){
					cur = L.erase(--cur);
				}
			}else{
				L.insert(cur, c);
			}
		}
		
		for(list<char>::iterator itr = L.begin(); itr != L.end(); itr++)
			cout << *itr;
		
		cout << '\n';
	}
	return 0;
}