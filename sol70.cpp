#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int start = 0, end = 0;
    int len = sequence.size();
    int sum = sequence[0];
    pair<int, int> result; 
    
    while (start <= end && end < sequence.size()) {
        if (sum < k) 
            sum += sequence[++end];
        else if (sum == k) {
            if (end - start < len) { 
                len = end - start;
                result = {start, end};
            } else if (end - start == len) {
                if (start < result.first) {
                    result = {start, end};
                }
            }       
            sum -= sequence[start++];
        } 
        else sum -= sequence[start++];
    }
    
    return {result.first, result.second};
}