

function solution(X, Y) {
    let answer = '';
    let arr1 = X.split('');
    let arr2 = Y.split('');
    
    for (let i = 9; i >= 0; i--){
        const cnt1 = arr1.filter(a => a == i).length;
        const cnt2 = arr2.filter(a => a == i).length;
        answer += String(i).repeat(Math.min(cnt1, cnt2));
    }
    
    if (answer == '')   return '-1';
    if (Number(answer) === 0)   return '0';
    
    
    return answer;
}