#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isFirst = true;
    
    for(auto& ch : s){
        // 첫 문자에 대해
        if (isFirst && ch != ' '){
            if (isalpha(ch))    
                ch = toupper(ch);
            isFirst = false;
        }
        else if (ch == ' ')  
            isFirst = true;
        else
            ch = tolower(ch);
        
        answer += ch;
    }
    
    return answer;
}