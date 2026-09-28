/*
[접근]

1. 1번 마을에서 모든 마을까지의 누적 최단거리 필요 → 다익스트라
2. 가장 가까운 마을부터 방문하며 연결된 마을의 누적거리 갱신
3. 기존 거리보다 짧은 경로를 발견하면 최단거리 갱신
4. 최종 최단거리 중 K 이하인 마을의 개수 반환
*/

function solution(N, road, K) {
  const dist = Array(N + 1).fill(Infinity);
  const graph = Array.from({ length: N + 1 }, () => []);
  const visited = Array(N + 1).fill(false);

  // 양방향 그래프
  road.forEach(([from, to, time]) => {
    graph[from].push([to, time]);
    graph[to].push([from, time]);
  });

  dist[1] = 0;

  for (let count = 1; count <= N; count++) {
    let current = -1;
    let minDist = Infinity;

    // 방문하지 않은 마을 중 가장 가까운 마을 선택
    for (let i = 1; i <= N; i++) {
      if (!visited[i] && dist[i] < minDist) {
        current = i;
        minDist = dist[i];
      }
    }

    visited[current] = true;

    // 현재 마을과 연결된 마을들의 누적거리 갱신
    graph[current].forEach(([next, time]) => {
      const newDist = dist[current] + time;

      if (newDist < dist[next]) {
        dist[next] = newDist;
      }
    });
  }

  return dist.filter((d) => d <= K).length;
}
