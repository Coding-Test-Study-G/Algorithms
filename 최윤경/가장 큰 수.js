/*
[접근]

1. 숫자를 문자열로 변환 → 이어 붙였을 때의 순서 비교
2. 두 수를 앞뒤로 붙여 비교 → (b + a) - (a + b)
3. 내림차순 정렬 후 문자열로 이어 붙임
4. 결과가 "0"으로 시작 → 모든 수가 0이므로 "0" 반환
*/

function solution(numbers) {
  var answer = numbers
    .map(String)
    .sort((a, b) => b + a - (a + b))
    .join("");

  return answer[0] === "0" ? "0" : answer;
}
