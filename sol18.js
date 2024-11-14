function solution(answers) {
    const pattern1 = [1, 2, 3, 4, 5];                       // 5개
    const pattern2 = [2, 1, 2, 3, 2, 4, 2, 5];              // 8개
    const pattern3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];        // 10개
    let score1 = 0, score2 = 0, score3 = 0;
    for(let i = 0; i < answers.length; i++){
        score1 += (answers[i] == pattern1[i % 5] ? 1 : 0);
        score2 += (answers[i] == pattern2[i % 8] ? 1 : 0);
        score3 += (answers[i] == pattern3[i % 10] ? 1 : 0);
    }
    const max = Math.max(score1, score2, score3);
    console.log(score1 + " , " + score2 + " , " + score3 + " , " + max + " , ");
    let answer = [];
    if (score1 == max)
        answer.push(1);
    if (score2 == max)
        answer.push(2);
    if (score3 == max)
        answer.push(3);
    
    return answer;
}