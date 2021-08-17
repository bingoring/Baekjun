#include <bits/stdc++.h>
using namespace std;

int N, M;
int init[100][100] = { 0 };
bool vis[100][100];
int cnt[100][100] = { 0 };

int dx[] = { 0, 1, 0, -1 };//12시부터 시계방향
int dy[] = { -1, 0, 1, 0 };

void bfs(int x, int y) {
	vis[x][y] = true;
	cnt[x][y]++;
	queue<pair<int, int>> q;
	q.push({ x, y });
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			//범위를 넘지 않고 방문하지 않았고 길이 존재한다면
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !vis[nx][ny] && init[nx][ny] == 1) {
				vis[nx][ny] = true;
				q.push({ nx, ny });
				cnt[nx][ny] = cnt[xx][yy]+1;	//이전 자리까지의 방문 수 +1
			}
		}
	}
}
int main(void) {
    //ios::sync_with_stdio(0);
	//cin.tie(0); //cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &init[i][j]);
			//cin >> mm[i][j];	101111이게 한번에 들어감
		}
	}

	bfs(0, 0);

	cout << cnt[N - 1][M - 1];
	
	return 0;
}