#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> result;
    // 신고자, 피신고자
    map<string, set<string>> reportMap;
    // 피신고자의 신고횟수
    map<string, int> reportCnt;
    
    
    for(const auto& r : report){
        auto reporter = r.substr(0, r.find(" "));
        auto reported = r.substr(r.find(" ") + 1, r.length());
        // 중복 없이 새로 신고될 때만 카운트
        if(reportMap[reporter].insert(reported).second) 
            reportCnt[reported]++;    
    }
    
    // 피신고자의 신고횟수
    for (const auto& mapE : reportMap){ 
        cout << mapE.first << "\n";
        int cnt = 0;
        for (const auto& reported : mapE.second) { 
            // cout << reported << " "; 
            if (reportCnt[reported] >= k) cnt++;
        } 
        cout << cnt << "\n";
        result[mapE.first] = cnt;
    }
    
    for(const auto& r : id_list){
        answer.push_back(result[r]);
    }
    
    return answer;
}