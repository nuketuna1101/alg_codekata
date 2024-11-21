function solution(players, callings) {   
    let answer = players;

    const order = new Map();
    players.forEach((player, index) => {
        order.set(player, index);
    });
    callings.forEach(calling => {
        let index = order.get(calling);
        let prevPlayer = answer[index - 1];
        answer[index - 1] = answer[index];
        answer[index] = prevPlayer;

        order.set(answer[index], index);
        order.set(answer[index - 1], index - 1);
    });
    
    return answer;
}
