#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int index = 0;
    int sum = 0;
    queue<int> myQueue;
    // bridge passing with queue
    
    // weight constraint checking
    
    while(true){
        // escape cond
        int cur = truck_weights[index];
        
        // 막차 탈출조건
        if (index == truck_weights.size()){
            answer += bridge_length;
            break;
        }
        
        if (myQueue.size() == bridge_length){
            sum -= myQueue.front();
            myQueue.pop();
        }
        
        if (sum + cur <= weight){
            sum += cur;
            myQueue.push(cur);
            index++;
        }
        else
            myQueue.push(0);
        
        answer++;
    }
    
    return answer;
}