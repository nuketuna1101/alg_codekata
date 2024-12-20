#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int len = number.size();
    int index = 0;
    for (int i = 0; i < len - k; ++i)
    {
        char biggest = number[index];
        int maxIndex = index;
        for (int j = index; j <= k + i; j++)
        {
            if (biggest < number[j])
            {
                biggest = number[j];
                maxIndex = j;
            }
        }
        index = maxIndex + 1;
        answer += biggest;
    }

    return answer;
}