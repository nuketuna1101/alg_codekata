#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool visited[8] = { 0, };

void dfs(vector<vector<int>> &dungeons,int k, int cnt) {
    if (cnt > answer) answer = cnt;
    
    for (int i = 0; i< dungeons.size(); i++) {
        if (!visited[i] && dungeons[i][0] <= k) {
            visited[i] = true;
            dfs(dungeons, k - dungeons[i][1], cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(dungeons, k, 0);
    
    return answer;
}