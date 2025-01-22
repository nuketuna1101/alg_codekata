#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int column;

bool cmp(vector<int>& v1, vector<int>& v2) {
    if(v1[column] == v2[column]) {
        return v1[0] > v2[0];
    } else {
        return v1[column] < v2[column];
    }
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    column = col - 1;

    sort(data.begin(), data.end(), cmp);

    int len = data[0].size();
    for(int i = row_begin; i <= row_end; ++i) {
        int totalSum = 0;
        for(int j = 0; j < len; ++j) {
            totalSum += (data[i - 1][j] % i);
        }
        // xor
        answer ^= totalSum;
    }
    
    return answer;
}
