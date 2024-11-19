function solution(s, skip, index) {
    let answer = "";
    let arr = s.split("");
    arr.map((item) => {
      let a = item.charCodeAt();
      for (let i = 0; i < index; i++) {
        a++; 
        if (a > 122)        a = 97;
        while (skip.includes(String.fromCodePoint(a))) {
          a++;
          if (a > 122)          a = 97;
        }
      }
      answer += String.fromCodePoint(a);
    });
    return answer;
  }
  