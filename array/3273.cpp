#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[1000000];
	
	int num;
	cin >> num;

	for(int i = 0; i < num; i++){
		int j;
		cin >> j;
		arr[i] = j;
	}
	
	int m;
	cin >> m;
	
	int _arr[1000000];
	int count;
	for(int i = 0; i < num; i++){
		if(_arr[m - arr[i]] == 1) count++;
		_arr[arr[i]] = 1;
	}
	cout << count;
	return 0;
}