#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 1e9;

vector<pair<int, int>> adj[51]; // 인접 리스트
int dp[51];

void dijkstra(int N){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> pq;
    pq.push({0, 1});
    fill(dp, dp + 51, INF); 
    dp[1] = 0;

    while(!pq.empty()){
        int currTime = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        if(currTime > dp[currNode]) continue;

        for (auto &p : adj[currNode]){
            int nextNode = p.first;
            int nextTime = currTime + p.second;
            if(nextTime < dp[nextNode]){
                dp[nextNode] = nextTime;
                pq.push({nextTime, nextNode});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    // adj 배열 초기화
    for(int i = 0; i <= 50; i++) {
        adj[i].clear();
    }

    for (int i = 0; i < road.size(); i++){
        int src = road[i][0], dest = road[i][1], cost = road[i][2];
        adj[src].emplace_back(dest, cost);
        adj[dest].emplace_back(src, cost);
    }

    dijkstra(N);

    for (int i = 1; i <= N; i++){
        if(dp[i] <= K) answer++;
    }

    return answer;
}
