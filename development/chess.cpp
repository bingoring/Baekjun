#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; 
	cin >> N >> M;
	vector<vector<char>> chessBoard(N,vector <char>(M));

	string W = "WBWBWBWB";
	string B = "BWBWBWBW";
	vector<string> chessBoard_W;
	vector<string> chessBoard_B;

	for(int i = 0; i < 8; i++){
		if(i % 2 == 0){
			chessBoard_W.push_back(W);
			chessBoard_B.push_back(B);
		}else{
			chessBoard_W.push_back(B);
			chessBoard_B.push_back(W);
		}
	}
	for(int i = 0; i < 8; i++){
		cout << chessBoard_B[i] << '\n';
	}
	//vector<vector<char>> result(N,vector <char>(N,'.'));

	int count = 100000;
	for(int i = 0; i <= N-8; i++){	//x
		for(int j = 0; j <= M-8; j++){	//y
			int tmp_W = 0;
			int tmp_B = 0;

			cout << "here" << '\n';
			for(int a = 0; a < 8; a++){	//현재 위치에서 세로로 8칸
				for(int b = 0; b < 8; b++){	//현재 위치에서 가로로 8칸
					if(chessBoard[i+a][j+b] != chessBoard_W[a][b])	tmp_W++;
					if(chessBoard[i+a][j+b] != chessBoard_B[a][b])	tmp_B++;
				}
			}
			cout << "W" << tmp_W << "B" << tmp_B << '\n';
			count = min(min(tmp_B, tmp_W), count);
		}
	}
	cout << count;
    return 0;
}