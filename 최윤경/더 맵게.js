/*
[접근]

1. 최솟값 2개를 반복해서 꺼냄 → 최소 힙
2. 두 값을 섞은 후 다시 힙에 삽입
3. 최솟값이 K 이상이면 종료
4. 음식이 1개 남았는데 K 미만이면 -1
*/

function solution(scoville, K) {
  var answer = 0;

  const heap = [];

  // 삽입 (마지막 삽입 => 부모와 비교하며 위로 이동)
  function push(value) {
    heap.push(value);

    let index = heap.length - 1;

    while (index > 0) {
      const parent = Math.floor((index - 1) / 2);
      if (heap[parent] <= heap[index]) break;

      // 구조분해할당 방식 swap 변경
      [heap[parent], heap[index]] = [heap[index], heap[parent]];
      index = parent;
    }
  }

  // 삭제 (루트 제거 => 마지막 값 루트 + 자식과 비교하며 아래로 이동)
  function pop() {
    if (heap.length === 1) return heap.pop();

    const min = heap[0];
    heap[0] = heap.pop();

    let index = 0;

    while (true) {
      const left = index * 2 + 1;
      const right = index * 2 + 2;
      let smallest = index;

      if (left < heap.length && heap[left] < heap[smallest]) {
        smallest = left;
      }

      if (right < heap.length && heap[right] < heap[smallest]) {
        smallest = right;
      }

      if (smallest === index) break;

      [heap[index], heap[smallest]] = [heap[smallest], heap[index]];
      index = smallest;
    }

    return min;
  }

  for (const value of scoville) {
    push(value);
  }

  while (heap[0] < K) {
    if (heap.length < 2) return -1;

    const first = pop();
    const second = pop();

    push(first + second * 2);

    answer++;
  }

  return answer;
}
