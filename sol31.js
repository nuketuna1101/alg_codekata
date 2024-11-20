function solution(wallpaper) {
    let answer = [];
    const lenX = wallpaper.length;
    const lenY = wallpaper[0].length;
    
    let minX = lenX, minY = lenY, maxX = 0, maxY = 0;
    
    for(let i = 0; i < lenX; i++){
        for (let j = 0; j < lenY; j++){
            if (wallpaper[i][j] === '#'){
                minX = Math.min(minX, i);
                minY = Math.min(minY, j);
                maxX = Math.max(maxX, i);
                maxY = Math.max(maxY, j);
            }
        }
    }
    answer.push(minX);
    answer.push(minY);
    answer.push(maxX + 1);
    answer.push(maxY + 1);
    return answer;
}