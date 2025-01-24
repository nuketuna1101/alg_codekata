#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {

    // 인접 리스트
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < m ; i++)
    {
        int src = edge_list[i][0];
        int dest = edge_list[i][1];

        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    vector<vector<int>> dp(k, vector<int>(n + 1, INF));
    dp[0][gps_log[0]] = 0;


    for (int i = 1; i < k; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j]);
            for (int adj : adj[j])
            {
                dp[i][j] = min(dp[i - 1][adj], dp[i][j]);
            }

            if (gps_log[i] != j)
                dp[i][j]++;
        }
    }


    int result = dp[k - 1][gps_log[k - 1]];
    return result >= INF ? -1 : result;
}
