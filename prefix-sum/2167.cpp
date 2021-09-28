#include<bits/stdc++.h>

using namespace std; 

#define MAX 301

int arr[MAX][MAX];

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); 
	
	int N, M;
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) { 
		for(int j = 1; j <= M; j++){
			int a;
			cin >> a;
			arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + a;
		}
	}
	
	int a;
	cin >> a;
	while(a--){
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << arr[x][y] - arr[x][j-1] - arr[i-1][y] + arr[i-1][j-1] << '\n';
	}
	
	return 0; 
}
