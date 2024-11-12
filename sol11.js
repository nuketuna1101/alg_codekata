function solution(s) {
    let result = [];
    const len = s.length;
    const alphabet = new Map(); 
    for (let charCode = 97; charCode <= 122; charCode++) {
        const char = String.fromCharCode(charCode); 
        alphabet.set(char, -1); 
    }
    for (let i = 0; i < len; i++){

        const char = s[i];
        if (alphabet.get(char) === -1){
            result.push(-1);
        }
        else{
            result.push(i - alphabet.get(char));
        }
        alphabet.set(char, i); 
        
    }
    console.log(result);
    return result;
}