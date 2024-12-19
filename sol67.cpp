#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> assist;
    
    for (int i=1; i<=order.size(); i++) {
        assist.push(i);
        
        while (!assist.empty() 
               && assist.top() == order[answer]) {
            assist.pop();
            answer++;
        }
    }
    
    return answer;
}