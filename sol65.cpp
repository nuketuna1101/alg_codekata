#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool isPrime(int num){
    if (num == 0 || num == 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++){
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    unordered_set<int> uos;
    
    sort(numbers.begin(), numbers.end());
    do {
        for(int i = 1; i <= numbers.size(); i++){
            int tmp = stoi(numbers.substr(0, i));
            if (isPrime(tmp))
                uos.insert(tmp);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    return uos.size();
}