#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    // 초기화
    int max = numeric_limits<int>::min();
    int min = numeric_limits<int>::max();
    while(true){
        // 공백없으면
        if (s.find(" ") == string::npos){
            int tmp = stoi(s);
            max = std::max(max, tmp);
            min = std::min(min, tmp);
            break;
        }      
        int tmp = stoi(s.substr(0, s.find(" ")));
        s = s.substr(s.find(" ") + 1, s.length());
        max = std::max(max, tmp);
        min = std::min(min, tmp);
    }
    
    answer += to_string(min) + " " + to_string(max);

    return answer;
}