/*
[접근]

1. 바위를 n개씩 직접 제거? 경우의 수 너무 많음
2. 특정 거리를 최소거리라고 가정하고 확인 
3. 바위 너무 많이 제거 ? 거리 줄임 : 거리 늘리기 => 이분탐색
*/

function solution(distance, rocks, n) {
  rocks.sort((a, b) => a - b);

  let left = 1;
  let right = distance;
  let answer = 0;

  while (left <= right) {
    const mid = Math.floor((left + right) / 2);

    let count = 0;
    let prev = 0;

    for (const rock of rocks) {
      if (rock - prev < mid) count++;
      else prev = rock; // 제거 X => 이전 바위 위치 갱신
    }

    if (distance - prev < mid) count++; // 마지막 바위 검사

    // 제거 바위 수 검사
    if (count > n) {
      right = mid - 1;
    } else {
      answer = mid;
      left = mid + 1;
    }
  }

  return answer;
}
