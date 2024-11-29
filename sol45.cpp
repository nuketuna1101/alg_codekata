#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;

    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        stack<char> stk;
        bool flag = true;

        for (int j = i; j < i + len; j++)
        {
            int tmp = s[j % len];

            if (tmp == '[' || tmp == '{' || tmp == '(')
            {
                stk.push(tmp);
            }
            else
            {
                if (stk.empty() 
                    || (tmp == ']' && stk.top() != '[') 
                    || (tmp == '}' && stk.top() != '{') 
                    || (tmp == ')' && stk.top() != '('))
                {
                    flag = false;
                    break;
                }
                stk.pop();
            }
        }
        if (flag && stk.empty())
            answer++;
    }
    return answer;
}