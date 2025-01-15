#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int x, int y){
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int gcd(vector<int> array){
    int cur = array[0];
    for (int i = 1; i < array.size(); i++){
        cur = gcd(cur, array[i]);
        if(cur == 1) break;
    }
    return cur;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());

    int gcdA = gcd(arrayA);
    int gcdB = gcd(arrayB);
    
    int tmpA = gcdA;
    int tmpB = gcdB;

    for (int i = 0; i < arrayB.size(); i++){
        int remain = arrayB[i] % gcdA;
        if (remain == 0){
            tmpA = 0;
            break;
        }
    }
    for (int i = 0; i < arrayA.size(); i++){
        int remain = arrayA[i] % gcdB;
        if (remain == 0){
            tmpB = 0;
            break;
        }
    }
    return max(tmpA, tmpB);
}