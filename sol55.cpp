#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int nums[20];
int ops[2] = {-1, 1};
int n, _target, rtn = 0;

void dfs(vector<int> numbers, int x, int sum){       
    if (x == n){
        if (sum == _target)     rtn++;
        return;
    }
        
    for (int i = 0; i < 2; i++){
        if (x < n){
            dfs(numbers, x + 1, sum + numbers[x] * ops[i]);
        }
    }    
}


int solution(vector<int> numbers, int target) {
    // inits
    n = numbers.size();
    _target = target;
    
    dfs(numbers, 0, 0);
    return rtn;
}