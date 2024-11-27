#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int w = ceil(sqrt(yellow));
    while(w <= yellow){
        if (4 + 2 * (w + yellow / w) == brown)
            break;
        w++;
    }
    answer.push_back(w + 2);
    answer.push_back(yellow / w + 2);
    
    return answer;
}