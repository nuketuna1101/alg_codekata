function solution(a, b, n) {
    let total = 0;      // 받는 콜라 카운트
    let cur = n;        // 현재 빈 병
    
    while(cur >= a){
        const coke = Math.floor(cur / a) * b;
        total += coke;
        cur = (cur % a) + coke;
    }
     
    return total;
}