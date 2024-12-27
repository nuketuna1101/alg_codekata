#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool visited[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(vector<string>& maps, int x, int y, vector<int>& answer) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int tmp = 0;
    
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        tmp += maps[a][b] - '0';
        q.pop();
        
        // 전방향 탐색
        for (int i = 0; i < 4; i++){
            int nx = a + dx[i];
            int ny = b + dy[i];
            // 경계 조건 확인
            if (nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size() || visited[nx][ny])
                continue;
            
            if (maps[nx][ny] != 'X') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        
    }
    answer.push_back(tmp);
}

vector<int> solution(vector<string> maps) {
    fill(&visited[0][0], &visited[0][0] + sizeof(visited), false); // visited 배열 초기화
    vector<int> answer;
    
    for(int i = 0; i< maps.size(); i++) {
        for(int j = 0; j< maps[0].size(); j++) {
            if(maps[i][j] != 'X' && !visited[i][j]) {
                bfs(maps, i, j, answer);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if(answer.empty()) 
        answer.push_back(-1);
    return answer;
}

