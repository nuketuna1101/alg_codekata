#include <string>
#include <vector>
#include <iostream>

using namespace std;

int zero = 0;
int one = 0;

void dfs(vector<vector<int>>& arr, int x, int y, int n){
    // x,y 시작좌표, 길이 n 범위 탐색
    if (n == 1){
        if(arr[x][y] == 1) 
            one++;
        else 
            zero++;
        return;
    }
    // 범위 내 원소합으로 전부 0, 전부 1 인지 여부
    int sum = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            sum += arr[x + i][y + j];
    
    if (sum == 0){
        zero++;
        return;
    }
    else if (sum == n * n){
        one++;
        return;
    }
    else{
        dfs(arr, x, y, n / 2);
        dfs(arr, x, y + n / 2, n / 2);
        dfs(arr, x + n / 2, y, n / 2);
        dfs(arr, x + n / 2, y + n / 2, n / 2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    dfs(arr, 0, 0, arr.size());
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}