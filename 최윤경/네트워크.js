/*
[접근]

1. 연결된 컴퓨터들을 하나의 네트워크로 판단 → DFS/BFS
2. visited로 미방문 컴퓨터 확인 → answer + 1
3. DFS로 연결된 컴퓨터들을 모두 방문 처리
4. 최종 answer 반환
*/

function solution(n, computers) {
  let answer = 0;
  let visited = Array(n).fill(false);

  function dfs(computer) {
    visited[computer] = true;

    for (let i = 0; i < n; i++) {
      if (computers[computer][i] === 1 && !visited[i]) {
        dfs(i);
      }
    }
  }

  for (let i = 0; i < n; i++) {
    if (!visited[i]) {
      answer++;
      dfs(i);
    }
  }

  return answer;
}
