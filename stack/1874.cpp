#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
  	vector<int> V;	//v에는 사용자가 입력한 수열
  	stack<int> S;
  	vector<char> result;	//+, -
  	int j =0;
    
  	cin >> N;
  
  	for (int i=0; i<N; i++) {
    	int tmp;
    	cin >> tmp;
    	V.push_back(tmp);
  	}
	
  	for (int i=1; i<=N; i++) {	//수열은 1부터
    	S.push(i);	// S에는 4
    	result.push_back('+');
    
    	while(!S.empty() && S.top() == V[j]){	//4까지 진입x, 진입할때는 1234
      		int tmp = V[j];	//tmp = 4
      		S.pop();	//S = 123
      		result.push_back('-');
      		j++;	//수열의 다음번째를 가리킴
    	}
  	}
  	if (!S.empty()) {
    	cout << "NO" << endl;
  	} else {
    	for (int i=0; i< result.size(); i++) {
      		cout << result[i] << "\n";
    	}
  	}

  	return 0;
}