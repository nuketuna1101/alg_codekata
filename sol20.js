function solution(n, m, section) {
    let answer = 0;
    let lastPainted = 0;
    for (let target of section){
        if (lastPainted < target){
            answer++;
            lastPainted = target + m - 1;
        }
    }
    console.log(section);
    return answer;
}