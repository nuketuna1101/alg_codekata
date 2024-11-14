function isPrime(num){
    if (num == 1)   return false;
    for (let i = 2; i < num; i++) {
        if (num % i === 0) return false;
      }
      return true;
}

function solution(nums) {
    let answer = 0; 
    const len = nums.length;
    for (let i = 0; i < len; i++) {
        for (let j = i + 1; j < len; j++) {
            for (let k = j + 1; k < len; k++) {
                let sum = nums[i] + nums[j] + nums[k];
                if (isPrime(sum)) answer++;
            }
        }
    }
    return answer;
}
  
