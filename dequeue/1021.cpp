#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	int n;
	int find_count;
	cin >> n;
	cin >> find_count;
	
	int num;
	int index;
	int count = 0;
	deque<int> d;
 
	//순열 채우기
	for (int i = 1; i <= n; ++i) {
		d.push_back(i);
	}
 
	while (find_count--){
		cin >> num;
 
		//찾는 숫자 표시
		for (int i = 0; i < d.size(); ++i) {
			if (d[i] == num) {
				index = i;
				break;
			}
		}
 
		
		if (index < d.size() - index) {	//2번연산
			while (1) {
				if (d.front() == num) {	//프론트에 있으면 count 증가x
					d.pop_front();
					break;
				}
				++count;
				d.push_back(d.front());
				d.pop_front();
			}
		}
		else {	//3번연산
			while (1) {
				if (d.front() == num) {
					d.pop_front();
					break;
				}
				++count;
				d.push_front(d.back());
				d.pop_back();
			}
		}
	}
	cout << count << '\n';
	
	return 0;
}