function convertChar(char, num){
    const charASCII = char.charCodeAt(0);
    const aASCII = 'a'.charCodeAt(0);
    const zASCII = 'z'.charCodeAt(0);
    const AASCII = 'A'.charCodeAt(0);
    const ZASCII = 'Z'.charCodeAt(0);
    let result = '';
    
    if (char == " ")    return char;
    
    if (charASCII >= aASCII && charASCII <= zASCII){
        result = (charASCII - aASCII + num) % 26 + aASCII; 
    }
    if (charASCII >= AASCII && charASCII <= ZASCII){
        result = (charASCII - AASCII + num) % 26 + AASCII; 
    }
    return String.fromCharCode(result);
}

function solution(s, n) {
    let answer = '';
    for (let i = 0 ; i < s.length; i++){
        answer += convertChar(s[i], n);
    }
    return answer;
}