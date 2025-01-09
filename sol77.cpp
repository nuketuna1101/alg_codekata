#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    // 수식: x^2 + (b*k)^2 <= d^2
    // 오버플로우 방지위해 long long 타입
    for (int i = 0; i <= d / k; i++) {
        int x = i * k;
        long long max_b = sqrt((long long)d * d - (long long)x * x) / k;
        answer += max_b + 1;
    }

    return answer;
}
