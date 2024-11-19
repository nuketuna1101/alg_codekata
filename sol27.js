function solution(keymap, targets) {
    let answer = [];
    let map = {}
    for (const items of keymap) {
        items.split('').map((item, index) => 
                            map[item] = (map[item] < index + 1 ? map[item] : index + 1))
    }
    for (const items of targets) {
        answer.push(items.split('').reduce((cur, item) => cur += map[item], 0) || -1)
    }
    return answer;
}