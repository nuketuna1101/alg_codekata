
function solution(number, limit, power) {
    let answer = 0;
    for (let i = 1; i <= number; i++){
        let cnt = 0;        
        for (let j = 1; j <= Math.sqrt(i); j++){
            if (i % j == 0 && i / j === j) cnt++;
            else if (i % j == 0)    cnt += 2;
            
            if (cnt > limit){
                cnt = power;
                break;
            }
        }
        answer += cnt;
    }  
    return answer;
}