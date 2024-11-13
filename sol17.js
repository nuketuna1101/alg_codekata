function solution(k, m, score) {
    let result = 0;
    const sorted = score.sort((a, b) => b - a);
    const len = score.length;
    const num = Math.floor(len / m);

    // for (let i = 0; i < num; i++){
    //     const tmp = sorted.splice(0, m);
    //     result += tmp[m - 1] * m;
    // }
    for (let i = 0; i < num; i++){
        const tmp = m * (i + 1) - 1;
        if (tmp < len)
            result += score[tmp] * m;
    }


    return result;
}