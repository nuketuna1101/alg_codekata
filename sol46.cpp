#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int len = elements.size();
    set<int> mySet;
    
    for (int i = 0; i < len; i++){
        int tmp = 0;
        for (int j = i; j < i + len; j++){
            int index = j % len;
            tmp += elements[index];
            mySet.insert(tmp);
        }
    }
    return mySet.size();
}