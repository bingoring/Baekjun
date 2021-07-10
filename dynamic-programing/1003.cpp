#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[41]={ 0, 1, 1 };	//0, 1, 2는 기본값으로 줘야함
    for(int i=3; i<41; i++)   arr[i]=arr[i-1]+arr[i-2];	//피보나치(0, 1의 호출수는 피보나치와 동일)
    
	int N;
    cin >> N;
 
    for(int i=0; i < N; i++){
        int input;
        cin >> input;
        if (input == 0)  cout << "1 0\n";
        else if (input == 1) cout << "0 1\n";
        else cout << arr[input-1] << " " << arr[input] << '\n';
    }
}