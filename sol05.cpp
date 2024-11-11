#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxA, maxB = 0;
    for(int i = 0; i < sizes.size(); i++){
        auto a = max(sizes[i][0], sizes[i][1]);
        auto b = min(sizes[i][0], sizes[i][1]);
           
        maxA = max(maxA, a);
        maxB = max(maxB, b);
    }
    answer = maxA * maxB;
    return answer;
}