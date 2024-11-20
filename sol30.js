function solution(survey, choices) {
    const types = [
      ["R", "T"],
      ["C", "F"],
      ["J", "M"],
      ["A", "N"],
    ];
  
    const cnts = { R: 0, T: 0, C: 0, F: 0, J: 0, M: 0, A: 0, N: 0 };
  
    survey.forEach((n, index) => {
      const type = n.split("");
      if (choices[index] > 4) 
        cnts[type[1]] += choices[index] - 4;
      else if (choices[index] < 4) 
        cnts[type[0]] += 4 - choices[index];
      
    });
  

    return types
      .map((n) => {
        if (cnts[n[0]] < cnts[n[1]]) {
          return n[1];
        }
        return n[0];
      })
      .join(""); 
  }