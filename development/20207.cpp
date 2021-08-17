#include<bits/stdc++.h>

using namespace std;

int N;
int cal[369] = {0,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
	cin >> N;

    while(N--){
		int a, b;
		cin >> a >> b;
		for(int i = a; i <= b; i++){
			cal[i]++;
		}
	}

	int height = 0;
	int width = 0;
	int result = 0;
	
	for(int i = 1; i <= 366; i++){
		if(cal[i] == 0){
			if(width == 0){
				continue;
			}else{
				result += width * height;
				width = 0; height = 0;
			}
		}else{
			if(width == 0){
				width = 1;
				height = cal[i];
			}else{
				width++;
				height = max(height, cal[i]);
			}
		}
	}
	cout << result;
	
    return 0;
}