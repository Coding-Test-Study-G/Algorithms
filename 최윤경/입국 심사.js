/*
[접근]

1. 정답을 시간으로 설정 → 이분탐색
2. 특정 시간(mid) 동안 각 심사관이 처리할 수 있는 사람 수 계산
3. 전체 처리 가능 인원이 n명 이상인지 확인
4. 가능하면 더 짧은 시간 탐색, 불가능하면 더 긴 시간 탐색
5. 최종적으로 최소 가능한 시간(start) 반환
*/

function solution(n, times) {
  let start = 0;
  let end = Math.max(...times) * n;

  while (start <= end) {
    let mid = Math.floor((start + end) / 2);

    let count = times.reduce((acc, time) => acc + Math.floor(mid / time), 0);

    if (count >= n) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return start;
}
