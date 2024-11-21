function solution(today, terms, privacies) {
    let answer = [];
    let results = [];

    // 약관 맵으로 초기화
    const termMap = new Map();
    terms.forEach(term => {
        const [key, value] = term.split(" ");
        termMap.set(key, parseInt(value, 10));
    });

    // 오늘 날짜 처리
    const [todayYear, todayMonth, todayDay] = today.split(".").map(Number);
    const todayDate = new Date(todayYear, todayMonth - 1, todayDay);

    privacies.forEach(privacy => {
        const [date, term] = privacy.split(" ");
        const [year, month, day] = date.split(".").map(Number);
        const addTerm = termMap.get(term);

        // 기간을 더한 만료 날짜 계산
        let expiryDate = new Date(year, month - 1, day);
        expiryDate.setMonth(expiryDate.getMonth() + addTerm);

        if (day === 1)
            expiryDate.setDate(0);  // 마지막 날짜
        else 
            expiryDate.setDate(day - 1);
        

        // 결과 배열에 추가
        results.push(expiryDate);
    });

    for (let i = 0; i < results.length; i++) {
        const expiryDate = results[i];

        // 만료 날짜가 오늘 날짜보다 이전이면 answer에 추가
        if (expiryDate < todayDate) {
            answer.push(i + 1);  // 1부터 시작하는 인덱스
        }
    }

    return answer;
}
