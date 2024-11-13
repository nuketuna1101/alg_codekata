function solution(k, score) {
    const len = score.length;
    let ranking = [];
    let result = [];
    for(let i = 0; i < len; i++){
        ranking.push(score[i]);
        ranking.sort((a, b) => b - a);
        ranking = ranking.slice(0, k);
        const min = ranking[ranking.length - 1];
        result.push(min);
    }
       
    return result;
}