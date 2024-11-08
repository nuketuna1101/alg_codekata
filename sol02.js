// 프로그래머스: 이상한 문자 만들기

function convertWord(word){
    let result = "";
    for(let i = 0; i < word.length; i++){
        if (i % 2 == 0)
            result += word[i].toUpperCase();
        else
            result += word[i].toLowerCase();
    } 
    return result;
}

function solution(s) {
    let result = "";
    const words = s.split(" ");
    console.log(words);
    for(let i = 0; i < words.length; i++){
        result += convertWord(words[i]) + (i != words.length - 1 ? " " : "");
    }
    
    return result;
}