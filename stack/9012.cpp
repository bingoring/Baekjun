#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int R;
	cin >> R;
	
	while(R--){
		string input;
		cin >> input;
		stack<char> S;
		bool result = true;;
		for(int i = 0; i < input.length(); i++){
			if(input[i] == '('){
				S.push(input[i]);
			}else{	//닫힘괄호일 경우
				if(S.empty()){	//스택에 ( 존재
					result = false;
				}else{//스택에 ( 존재 x
					S.pop();
				}	
			}
		}
		if(!S.empty()) result = false;
		
		if(result){
				cout << "YES" << '\n';
			}else{
				cout << "NO" << '\n';
		}
	}
    return 0;
}