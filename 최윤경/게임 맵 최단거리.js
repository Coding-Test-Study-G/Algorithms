/*
[접근]
1. 최단 거리 + 이동 비용 동일 → BFS
2. 상하좌우 탐색 → 방문 X 칸에 거리 기록 후 queue 추가
3. maps에 거리 기록 → visited 배열 대체
4. 도착점 거리 반환 or -1
*/

function solution(maps) {
  const N = maps.length;
  const M = maps[0].length;

  const dx = [-1, 1, 0, 0];
  const dy = [0, 0, -1, 1];

  const queue = [[0, 0]];
  let head = 0;

  while (head < queue.length) {
    const [x, y] = queue[head++];

    for (let d = 0; d < 4; d++) {
      const nx = x + dx[d];
      const ny = y + dy[d];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (maps[nx][ny] === 0) continue;
      // 첫 방문: 거리 기록 + 큐에 추가
      if (maps[nx][ny] === 1) {
        maps[nx][ny] = maps[x][y] + 1;
        queue.push([nx, ny]);
      }
    }
  }

  const distance = maps[N - 1][M - 1];
  return distance === 1 ? -1 : distance;
}
