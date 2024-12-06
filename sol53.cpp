#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> pq;
queue<pair<int,int>> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    for(int i = 0;i < priorities.size(); i++){
        q.push({i,priorities[i]});
        pq.push(priorities[i]);
    }  
    int cnt = 1;
    while(true) {      
        pair<int,int> qfront= q.front();
        q.pop();
     
        if (qfront.second == pq.top()){
            if (qfront.first == location){
                answer = cnt;
                break;
            }
            else {
                pq.pop();
                cnt++;         
            }            
        }
        else if(qfront.second != pq.top()){
            q.push({qfront.first,qfront.second});         
        }
    }
    return answer;
}