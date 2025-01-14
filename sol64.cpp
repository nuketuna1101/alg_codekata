#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers){
    string answer = "";
    // 문자열 벡터로 변환
    vector<string> tmp;
    for (auto num : numbers)
        tmp.push_back(to_string(num));
    sort(tmp.begin(), tmp.end(), cmp);
    if (tmp.at(0) == "0")
        return "0";
    for (auto num : tmp)
        answer += num;
    return answer;
}