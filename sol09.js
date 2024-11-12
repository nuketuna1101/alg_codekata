function solution(array, commands) {
    const len = commands.length;
    let result = [];
    for(let i = 0; i < len; i++){
        const command = commands[i];
        let tmp = array.slice(command[0] - 1, command[1]);
        // sort는 문자열 비교함수이므로 숫자 배열 정렬을 위한 기준 중요!!
        tmp.sort((a, b) => a - b);
        const target = tmp[command[2] - 1];
        result.push(target);
    }    
    return result;
}