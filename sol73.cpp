#include <string>
#include <vector>
#include <algorithm>
#include <climits> 

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    int board[104][104];
    int cnt = 1;

    // 초기화, 인덱스는 1,1 시작으로 튜닝
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            board[i][j] = cnt++;
        }
    }

    //
    for (int i = 0; i < queries.size(); i++)
    {
        vector<int> tmp;
        vector<pair<int, int>> xy;
        int minValue = INT_MAX;
        int sy = queries[i][0];
        int sx = queries[i][1];
        int dy = queries[i][2];
        int dx = queries[i][3];

        for (int i = sx; i <= dx; i++)
        {
            tmp.push_back(board[sy][i]);
            minValue = min(minValue, board[sy][i]);
            xy.push_back({sy, i});
        }

        for (int i = sy + 1; i <= dy; i++)
        {
            tmp.push_back(board[i][dx]);
            minValue = min(minValue, board[i][dx]);
            xy.push_back({i, dx});
        }

        for (int i = dx - 1; i >= sx; i--)
        {
            tmp.push_back(board[dy][i]);
            minValue = min(minValue, board[dy][i]);
            xy.push_back({dy, i});
        }

        for (int i = dy - 1; i >= sy + 1; i--)
        {
            tmp.push_back(board[i][sx]);
            minValue = min(minValue, board[i][sx]);
            xy.push_back({i, sx});
        }

        rotate(tmp.rbegin(), tmp.rbegin() + 1, tmp.rend());

        for (int i = 0; i < xy.size(); i++)
        {
            board[xy[i].first][xy[i].second] = tmp[i];
        }

        answer.push_back(minValue);
    }

    return answer;
}