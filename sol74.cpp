#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int bfs(vector<vector<int>> v)
{
    vector<int> visited(v.size());
    queue<int> q;

    q.push(1);
    int cnt = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (visited[cur] == 1)
            continue;
        visited[cur] = 1;
        cnt++;
        for (int i = 0; i < v[cur].size(); i++)
        {
            q.push(v[cur][i]);
        }
    }
    int tmp = v.size() - 1 - cnt;
    return abs(cnt - tmp);
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = 1000;
    int len = wires.size();
    for (int i = 0; i < len; i++)
    {
        vector<vector<int>> v(n + 1);
        for (int j = 0; j < len; j++)
        {
            if (i == j)
                continue;
            int s = wires[j][0];
            int e = wires[j][1];
            v[s].push_back(e);
            v[e].push_back(s);
        }
        answer = min(answer, bfs(v));
        v.clear();
    }
    return answer;
}