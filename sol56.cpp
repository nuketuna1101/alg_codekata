#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

// 소수 판별
 bool isPrime(long long num) {
    if(num == 1) return false;
        
    for(int i = 2; i<=sqrt(num); ++i) {
        if(num % i == 0) return false;
    }
    return true;
}

string convertNum(int n, int k) {
    // 10진수 n을 k진수로 바꾼 결과
    string result = "";
    while(n > 0){
        string remainer = to_string(n % k);
        result = remainer + result;
        n /= k;
    }
    return result;
}

int solution(int n, int k) {
    int answer = 0;
    string converted = convertNum(n, k);
    cout << converted << "\n";
    
    string tmp = "";
    for (char c : converted) {
        if (c != '0')
            tmp += c;
        else {
            if (tmp != "" && isPrime(stoll(tmp))) answer++;
            tmp = "";
        }
    }
    if (tmp != "" && isPrime(stoll(tmp))) answer++;
    tmp = "";
    return answer;
}