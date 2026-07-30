"""
목표: 각 작업당 반환 시간의 평균의 정수 부분을 반환
- 반환 시간 = 작업 종료 시점 - 요청 시점
- jobs: [요청 시점, 소요 시간]을 담은 2차원 리스트


대기 큐: 해당 작업의 번호, 요청 시각, 소요 시간을 저장
- 처음에는 비어있음
디스크 컨트롤러: 하드디스크가 쉬고 있고 대기 큐가 비어있지 않을 때, 
               가장 우선순위가 높은 작업을 꺼내서 하드디스크에 해당 작업을 시킴
- 우선 순위: 1) 작업의 소요시간이 짧은 것, 2) 작업의 요청 시각이 빠른 것, 3) 작업의 번호가 작은 것
- 하드디스크는 한 번에 하나의 작업만 수행
- 작업이 끝나자마자 작업 요청이 들어오면 해당 작업을 대기 큐에 넣고 우선순위대로 작업 수행
- 작업을 마쳤을 때 요청이 없어도 대기 큐에서 작업 뽑아서 수행

- jobs: [작업이 요청되는 시점, 작업의 소요시간]을 담은 2차원 정수 배열

** 우선순위 디스크 컨트롤러가 이 작업을 처리했을 때 모든 요청 작업의 반환 시간의 평균의 정수부분을 return **
"""

import heapq as hq
def solution(jobs):
    answer = 0
    queue = []
    pushed = [False for _ in range(len(jobs))]
    
    hq.heapify(queue)
    jobs.sort()
    
    time = 0
    count = 0
    while True:
        # for문은 하나 작업 끝날 때마다 해서 요청 시각에 맞게 넣어줘야 함. 
        # 그렇지 않으면 아직 요청도 안 헀는데 소요 시간 더 짧은 애들이 뒤에 있어서 걔네 먼저 하면 로직이 꼬임
        for i, (start, work_time) in enumerate(jobs):
            if start <= time and not pushed[i]:
                hq.heappush(queue, (work_time, start, i))
                pushed[i] = True
        
        if not queue:
            time += 1
            continue
            
        work_t, start_t, job_num = hq.heappop(queue)
        
        time += work_t
        answer += time - start_t
        count += 1
        if count == len(jobs):
            break
        
    return answer // len(jobs)