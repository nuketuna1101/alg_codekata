#include <string>
#include <vector>
#include <iostream>

using namespace std;

int transformCnt = 0;
int zeroCnt = 0;

string transformBin(string input){   
    int cnt = 0;
    for(auto& i : input){
        if(i == '1') cnt++;
        if(i == '0') zeroCnt++;
    }
    string binary = "";
    while(cnt > 0){
        binary = to_string(cnt % 2) + binary;
        cnt /= 2;
    }
    transformCnt++;
    return binary;
}


vector<int> solution(string s) {
    vector<int> answer;

    while(s != "1"){        
        s = transformBin(s);
    }
    answer.push_back(transformCnt);
    answer.push_back(zeroCnt);
    return answer;
}