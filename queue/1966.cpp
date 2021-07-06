#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int R;
    
    cin >> R;
    
    for(int i = 0; i < R; i++){
        int docnum, targetnum, cnt = 0;
        queue<pair<int, int>> Q;
        priority_queue<int> pq;
        
        cin >> docnum >> targetnum;
        
        for(int j = 0; j < docnum; j++){
            int priority;
            cin >> priority;
            Q.push({j, priority});
            pq.push(priority);
        }
        
        while(!Q.empty()){
            int curidx = Q.front().first;
            int curpri = Q.front().second;
            Q.pop();
            
            if(curpri == pq.top()){
                pq.pop();
                cnt++;
                if(curidx == targetnum){
                    cout << cnt << '\n';
                    break;	//이거안하면 계속 뒤로보냄
                }
            }
            else{
                Q.push({curidx, curpri});
            }
        }
    }
    return 0;
}