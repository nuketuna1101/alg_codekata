#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int convertTime(string time)
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

int solution(vector<vector<string>> book_time)
{
    vector<pair<int, int>> reservations;
    // pq가 max heap 구현하므로
    priority_queue<int> pq;

    for (vector<string> s : book_time)
    {
        reservations.push_back({convertTime(s[0]), convertTime(s[1]) + 10});
    }
    sort(reservations.begin(), reservations.end());

    for (int i = 0; i < reservations.size(); i++)
    {
        if (!pq.empty() && -pq.top() <= reservations[i].first)
            pq.pop();
        pq.push(-reservations[i].second);
    }

    return pq.size();
}
