function rank(cnt){
    switch(cnt){
        case 6:
            return 1;
        case 5:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
        case 2:
            return 5;
        default:
            return 6;
    }
}

function solution(lottos, win_nums) {
    var answer = [];
    // 0은 dont care로 취급
    // 0을 제외한 것에 대한 일치 비교
    const len = lottos.length;
    let zeros = 0;
    let matchedCnt = 0;
    for(let i = 0; i < len; i++){
        const num = lottos[i];
        if (num == 0) {
            zeros++;
            continue;
        }
        if (win_nums.includes(num))     matchedCnt++;
    }
    
    const minCnt = matchedCnt;
    const maxCnt = matchedCnt + zeros;
    console.log(zeros + " , " + matchedCnt);
    console.log(maxCnt + " , " + minCnt);
    answer.push(rank(maxCnt));
    answer.push(rank(minCnt));
    return answer;
}