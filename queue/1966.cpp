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
        
        cin >> docnum >> targetnum; //개수, 순서를 알고자하는 문서 위치
        
        for(int j = 0; j < docnum; j++){
            int priority;
            cin >> priority;
            Q.push({j, priority});  //
            pq.push(priority);
        }
        
        while(!Q.empty()){
            int curidx = Q.front().first;
            int curpri = Q.front().second;
            Q.pop();    //일단 없앤 후에 뒤에서 
            
            if(curpri == pq.top()){ //우선순위가 가장 높을경우
                pq.pop();   //우선순위 높은거 출력했으므로 삭제
                cnt++;      //출력되면 카운트+
                if(curidx == targetnum){
                    cout << cnt << '\n';
                    break;
                }
            }
            else{   //우선순위 가장 높지않아면
                Q.push({curidx, curpri});
            }
        }
    }
    return 0;
}