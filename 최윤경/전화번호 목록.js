/*
[접근]

1. 전화번호를 오름차순 정렬
2. 인접한 번호끼리 접두어 관계인지 확인
3. 접두어가 있으면 false, 없으면 true 반환
*/

function solution(phone_book) {
  var answer = true;

  phone_book.sort();

  for (let i = 0; i < phone_book.length - 1; i++) {
    if (phone_book[i + 1].startsWith(phone_book[i])) {
      return false;
    }
  }

  return true;
}
