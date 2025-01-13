#include <string>
#include <vector>

using namespace std;

void recur(int n, int *answer)
{
    if (n == 0) return;    
    
    int cur = n % 10;
    if (cur > 5 || (cur == 5 && (n % 100) / 10 >= 5))
    {
        *answer += 10 - cur;
        n += 10;
    }
    else 
        *answer += cur;
    
    recur(n / 10, answer);

}

int solution(int storey)
{
    int answer = 0;
    recur(storey, &answer);
    return answer;
}