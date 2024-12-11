#include <string>
#include <vector>

using namespace std;

int cnt = -1;
int answer = 0;
string target = "";
string alphabet = "AEIOU";

void dfs(string word) {
    cnt++;
    
    if (word == target) {
        answer = cnt;
        return;
    }
    
    if (word.length() >= 5) return;
    
    for(char c : alphabet){
        dfs(word + c);
    }
}

int solution(string word) {   
    target = word;
    dfs("");
    
    return answer;
}