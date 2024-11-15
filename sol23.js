function solution(babbling) {
    const words = ['aya','ye','woo','ma'];
    let cnt = 0;
    
    for(let i = 0; i < babbling.length; i++){
        let input = babbling[i];
        
        for(let j = 0; j < 4; j++){
            if(input.includes(words[j].repeat(2)))             break;
                   
            input = input.split(words[j]).join(" ");
        }
        if(input.split(" ").join("").length == 0){
            cnt++;
        }
    }
    
    return cnt;
}