#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> myMap;

bool check(map<string, int> m)
{
    for (auto u : myMap)
    {
        if (m.find(u.first) == m.end())
            return false;
        else if (m[u.first] != u.second)
            return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    int len = want.size();

    for (int i = 0; i < len; i++)
    {
        myMap[want[i]] = number[i];
    }

    for (int i = 0; i <= discount.size() - 10; i++)
    {
        map<string, int> m;
        for (int j = i; j < i + 10; j++)
        {
            m[discount[j]]++;
        }
        answer += check(m);
        m.clear();
    }
    return answer;
}