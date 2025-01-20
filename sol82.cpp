#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    // 중복 제거위해 map 이용
    map<long long, long long> myMap;
    // 초기화
    for (long long n : weights)
        ++myMap[n];

    for (const auto& [weight, cnt] : myMap) {
        // 중복 값을 위한 처리
        if (cnt > 1) 
            answer += cnt * (cnt - 1) / 2;
        

        // 가능한 쌍 관계
        vector<pair<long long, long long>> relationships = {
            {3, 2}, {4, 2}, {4, 3}
        };

        for (const auto& [num, denom] : relationships) {
            if (weight * num % denom == 0) {
                long long relatedWeight = weight * num / denom;
                if (myMap.find(relatedWeight) != myMap.end()) {
                    answer += myMap[relatedWeight] * cnt;
                }
            }
        }
    }
    
    return answer;
}


// #include <string>
// #include <iostream>
// #include <vector>
// #include <map>

// using namespace std;

// long long solution(vector<int> weights) {
//     long long answer = 0;
//     // 중복 제거위해 map 이용
//     map<long long, long long> myMap;
//     // 초기화
//     for (long long n : weights)
//         ++myMap[n];

//     for (pair<long long, long long> p : myMap){
//         long long weight = p.first;
//         long long cnt = p.second;

//         // 동일 무게 중복 존재 시
//         if (cnt > 1)
//             answer += cnt * (cnt - 1) / 2;

//         long long tmp = weight * 3 / 2;
//         if (weight * 3 % 2 == 0 && myMap.find(tmp) != myMap.end())
//             answer += myMap[tmp] * cnt;

//         tmp = weight * 4 / 2;
//         if (weight * 4 % 2 == 0 && myMap.find(tmp) != myMap.end())
//             answer += myMap[tmp] * cnt;

//         tmp = weight * 4 / 3;
//         if (weight * 4 % 3 == 0 && myMap.find(tmp) != myMap.end())
//             answer += myMap[tmp] * cnt;
        
//     }
    
    
//     return answer;
// }