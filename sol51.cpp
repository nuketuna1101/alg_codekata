#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> myMap;

    for (vector<string> input : clothes) {
        myMap[input[1]]++;
    }

    for (auto& x : myMap) {
        answer *= (x.second + 1);
    }
    answer--;
    return answer;
}
