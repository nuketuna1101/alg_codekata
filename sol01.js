// 프로그래머스 : 3진법 뒤집기

function solution(n) {
    let num = n;
    let arr = [];
    let result = 0;
    while(true){
        if(num < 3){
            arr.push(num);
            break;
        }
        
        let tmp = num % 3;
        num = Math.floor(num / 3);
        arr.push(tmp);
    }
    for(let i = 0; i < arr.length; i++){
        result += arr[i] * Math.pow(3, arr.length - 1 - i);
    }
    console.log(arr);
    return result;
}