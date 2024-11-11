function solution(t, p) {
    let answer = 0;
    const tLen = t.length;
    const pLen = p.length;

    for (let i = 0; i <= tLen - pLen; i++){
        let tmp = t.slice(i, i + pLen);
        console.log("tmp : " + tmp);
        const num = parseInt(tmp, 10);
        if (tmp <= p)   answer++;
    }
    return answer;
}