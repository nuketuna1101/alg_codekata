#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    int len = numbers.size();
    
    // 
    for (int i = 0; i < len; i++){
        long long tmp = numbers[i];
        // 비트 
        if (tmp % 2 == 0)
            answer.push_back(tmp + 1);
        else
        {
            long long zero = (tmp + 1) & (tmp * (-1));
            // bit compare
            long long cmp = (tmp | zero);
            // bit shift
            long long cmp2 = zero >> 1;
            answer.push_back(cmp & ~cmp2);
        }
    }
    
    return answer;
}