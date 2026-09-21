/*
[접근]

1. 최단 거리 + 간선 가중치 동일 → BFS
2. 양방향 간선 → 인접 리스트 생성
3. 1번 노드부터 BFS → 미방문 노드에 이전 거리 + 1 기록
4. distance의 최댓값 = 가장 먼 거리
5. 최댓값을 가진 노드 개수 반환
*/

function solution(n, vertex) {
  let graph = Array.from({ length: n + 1 }, () => []);
  let distance = Array(n + 1).fill(-1); // 간선 여부, 방문 여부 구분 위해 -1로 초기화

  // 인접 리스트 생성
  for (const [a, b] of vertex) {
    graph[a].push(b);
    graph[b].push(a);
  }

  // BFS
  function BFS(start) {
    let queue = [start];
    let head = 0;

    distance[start] = 0;

    while (head < queue.length) {
      const vtx = queue[head++];

      for (const next of graph[vtx]) {
        if (distance[next] === -1) {
          distance[next] = distance[vtx] + 1; // 값 업데이트
          queue.push(next);
        }
      }
    }
  }

  // 1부터 BFS 시작
  BFS(1);

  const max = distance.reduce((max, dist) => Math.max(max, dist), 0);
  return distance.filter((dist) => dist == max).length;
}
