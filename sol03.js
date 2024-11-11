const nums = [];
const used = [];
let answer = 0;

function func(number, start, depth){
    // depth 3이면 체킹
    if (depth == 3) {
        const totalSum = nums.reduce((acc, cur) => acc + cur, 0);
        if (totalSum == 0) answer++;
        return;
    }
    
    for (let i = start; i <= number.length; i++){
        if (!used[i]){
            nums.push(number[i - 1]);
            used[i] = true;
            func(number, i + 1, depth + 1);     // recursive하게
            nums.pop();
            used[i] = false;
        }
    }
}


function solution(number) {
    
    func(number, 1, 0);
    
    return answer;
}