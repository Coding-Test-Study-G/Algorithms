/*
[접근]

1. 항공권 전부 사용 → DFS + 백트래킹
2. tickets 정렬 → 처음 찾은 경로가 정답
3. 중복 항공권 존재 → 인덱스로 사용 체크
4. 항공권 사용 후 재귀, 실패 시 되돌리기
5. 경로 길이가 항공권 수 + 1이면 종료
*/

function solution(tickets) {
  tickets.sort();

  const used = Array(tickets.length).fill(false);
  const path = ['ICN'];

  function dfs(cur) {
    if (path.length === tickets.length + 1) return true;

    for (let i = 0; i < tickets.length; i++) {
      const [a, b] = tickets[i];

      if (path.at(-1) === a && !used[i]) {
        used[i] = true;
        path.push(b);

        if (dfs(b)) return true;

        used[i] = false;
        path.pop();
      }
    }
    return false;
  }

  dfs('ICN');
  return path;
}
