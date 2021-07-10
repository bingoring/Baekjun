#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> V;
bool visited[101] = {false, };
int result;
void dfs(int a){
	visited[a] = true;
	
	for(int i = 0; i < V[a].size(); i++){
		if(visited[V[a][i]] == false){
			dfs(V[a][i]);
			result++;
		}
	}
}
int main(int argc, char *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, C;
	
	cin >> N >> C;
	
	V.resize(N+1);
	
	int x, y;
	while(C--){
		cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);
		
	}
	dfs(1);
	cout << result;

  	return 0;
}