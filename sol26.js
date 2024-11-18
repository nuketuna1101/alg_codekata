function solution(s) {
    let answer = 0;
    let stk = [];
    let cnt = 0;
    for(let i = 0; i < s.length; i++){
        const cur = s[i];
        stk.push(cur);
        (cur === stk[0] ? cnt++ : cnt--);
        
        if (cnt === 0){
            answer++;
            stk = [];
        }
    }
    if (stk.length > 0) answer++;
    
    
    return answer;
}