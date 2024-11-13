function solution(cards1, cards2, goal) {   
    while(true){
        if (goal.length === 0) break;
        
        const tmp = goal.shift();
        
        if (cards1[0] == tmp)
            cards1.shift();
        else if (cards2[0] == tmp)
            cards2.shift();
        else
            return "No";
    }
    
    return "Yes";
}