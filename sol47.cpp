#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int len = citations.size();
    int h = 1;
    while(true){
        int cnt = 0;
        for (int i = 0; i < len; i++){
            if (citations[i] >= h)   cnt++;
        }
        if (cnt >= h)   answer = h++;
        else break;
    }
    return answer;
}