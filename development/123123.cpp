int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N * N; i++)
    {
        int student, prefers;
        cin >> student;

        //prefer list init
        for (int i = 0; i < 4; i++)
        {
            cin >> prefers;
            preferList[student].push_back(prefers);
        }

        //========================
        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                for (int num = 0; num < preferList[student].size(); num++)
                {
                    if (studentTable[i][j] != preferList[student][num])
                        continue;
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if (1 > nx || nx > N || 1 > ny || ny > N)
                            continue;
                        if (studentTable[nx][ny])
                            continue;
                        preferTable[nx][ny]++;
                    }
                }
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cnt = max(cnt, preferTable[i][j]);
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (cnt == preferTable[i][j] && !studentTable[i][j])
                {
                    possibleSeats.push_back({i, j});
                }
            }
        }

        //==============
        sort(possibleSeats.begin(), possibleSeats.end());
        vector<int> emptyCnt;
        int maxCnt = 0;
        for (auto c : possibleSeats)
        {
            int cnt = 0;
            for (int i = 0; i < 4; i++)
            {
                int nx = c.first + dx[i];
                int ny = c.second + dy[i];
                if (1 > nx || nx > N || 1 > ny || ny > N)
                    continue;
                if (studentTable[nx][ny])
                    continue;
                cnt++;
            }
            maxCnt = max(maxCnt, cnt);
            emptyCnt.push_back(cnt);
        }

        for (int i = 0; i < emptyCnt.size(); i++)
        {
            if (emptyCnt[i] == maxCnt)
            {
                studentTable[possibleSeats[i].first][possibleSeats[i].second] = student;
                break;
            }
        }
    }

    int sum;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int student = studentTable[i][j];
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (1 > nx || nx > N || 1 > ny || ny > N)
                    continue;
                for (int num = 0; num < preferList[student].size(); num++)
                {
                    if (preferList[student][num] != studentTable[nx][ny])
                        continue;
                    cnt++;
                }
            }
            sum += pow(10, cnt - 1);
        }
    }

    cout << sum;
}