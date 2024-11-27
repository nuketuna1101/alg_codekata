#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int gcd(int a, int b)
{
    int x = max(a, b);
    int y = min(a, b);

    while (x % y != 0)
    {
        int r = x % y;
        x = y;
        y = r;
    }
    return y;
}

int solution(vector<int> arr)
{
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++)

    {
        int tmp = gcd(answer, arr[i]);
        answer = answer * arr[i] / tmp;
    }
    return answer;
}