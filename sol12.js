function solution(food) {
    let result = "";
    const len = food.length;
    
    for (let i = 1; i < len; i++){
        const half = Math.floor(food[i] / 2);
        for (let j = 0; j < half; j++)
            result += i;
    }

    const rev = result.split('').reverse().join('');
    result += 0;
    result += rev;

    return result;
}