function solution(numbers) {
    let result = [];
    const len = numbers.length;
    for (let i = 0; i < len; i++){
        for (let j = i + 1; j < len; j++){
            const sum = numbers[i] + numbers[j];
            
            if (result.includes(sum))   continue;
            result.push(sum);
        }
    }
    result.sort((a, b) => a - b);
    
    return result;
}