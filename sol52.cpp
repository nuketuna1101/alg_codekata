#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int size = progresses.size();
    queue<int> q;
    vector<int> result;
    int cnt;

    for (int i = 0; i < size; i++) {
        int a = (100 - progresses[i]);
        int b = speeds[i];
        int tmp = a / b + ((a % b == 0) ? 0 : 1);
        q.push(tmp);
    }

    while (!q.empty()) {
        cnt = 0;
        int pivot = q.front();
        while (!q.empty() && q.front() <= pivot) {
            q.pop();
            cnt++;
        }
        result.push_back(cnt);
    }
    return result;
}