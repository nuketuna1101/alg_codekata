#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping)
{
    int answer = 0;
    map<int, int> first;
    map<int, int> second;

    for (int i = 0; i < topping.size(); i++)
    {
        second[topping[i]]++;
    }

    for (int i = 0; i < topping.size(); i++)
    {
        int tmp = topping[i];
        if (second.find(tmp) != second.end())
        {
            first[tmp]++;
            second[tmp]--;
            if (second[tmp] == 0)
            {
                second.erase(tmp);
            }
        }
        if (first.size() == second.size())
            answer++;
    }
    return answer;
}