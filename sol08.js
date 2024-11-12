function solution(strings, n) {
    let len = strings.length;
    for (let i = 0; i < len; i++){
        strings[i] = strings[i][n] + strings[i];
    }
    strings.sort();

    for(let j = 0; j < len; j++) {
      strings[j] = strings[j].replace(strings[j][0],"");
    }
    
    return strings;
}