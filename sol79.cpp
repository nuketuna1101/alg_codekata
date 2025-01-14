#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int num = 5;

bool visit[5][5];

bool isValid(int y, int x) {
    return y >= 0 && x >= 0 && y < num && x < num; 
}

bool dfs(vector<string> &place, int y, int x, int count) {
    if(count >= 3) return true;

    if(count > 0 && place[y][x] == 'P') 
        return false;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(!isValid(ny, nx) || visit[ny][nx]) continue;
        if(place[ny][nx] == 'X') continue;
        
        visit[ny][nx] = true;
        if(!dfs(place, ny, nx, count+1)) return false; // 결과 거짓이면 바로 리턴, 참이면 계속 탐색
        visit[ny][nx] = false;    
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int k = 0; k < num; k++) {
        bool flag = true;
        for(int i = 0; i < num; i++) {
            for(int j = 0; j < num; j++) {
                // 첫 사람위치 시작
                if(places[k][i][j] == 'P') {
                    memset(visit, 0, sizeof(visit));
                    
                    visit[i][j] = true;
                    // 하나라도 위반 확인시
                    if(!dfs(places[k], i, j, 0)) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        
        answer.push_back(flag);
    }
    
    return answer;
}