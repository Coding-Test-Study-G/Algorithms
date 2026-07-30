import java.util.*;

class Solution {
    class Job {
        private int processNum;
        private int requestedMs;
        private int wrokingMs;
        private int turnaroundMs;

        public int getRequestedMs() {
            return requestedMs;
        }

        public int getWrokingMs() {
            return wrokingMs;
        }

        public int getProcessNum() {
            return processNum;
        }

        public int getTurnaroundMs() {
            return turnaroundMs;
        }

        public void setTurnaroundMs(int turnaroundMs) {
            this.turnaroundMs = turnaroundMs;
        }

        public Job(int processNum, int requestedMs, int wrokingMs) {
            this.processNum = processNum;
            this.requestedMs = requestedMs;
            this.wrokingMs = wrokingMs;
        }
    }

    public int solution(int[][] jobs) {
        //대기 큐 생성
        PriorityQueue<Job> waitQueue = new PriorityQueue<>(
                Comparator.<Job>comparingInt(j -> j.getWrokingMs())
                        .thenComparing(j -> j.getRequestedMs())
                        .thenComparing(j -> j.getProcessNum())
        );

        //일 순서대로 가지고 있는 큐 생성
        PriorityQueue<Job> jobQueue = new PriorityQueue<>(
                Comparator.<Job>comparingInt(j -> j.getRequestedMs()));
        for(int i=0; i<jobs.length; i++) {
            jobQueue.offer(new Job(i, jobs[i][0], jobs[i][1]));
        }

        int time = 0;
        int workingRemainTime = 0;
        int turnaroundMsSum =0;
        while(!jobQueue.isEmpty() || !waitQueue.isEmpty() || workingRemainTime>0)         {
            //현재 시간과 일이 요청된 시간이 같다면 대기 큐에 추가.
            while(!jobQueue.isEmpty() && jobQueue.peek().getRequestedMs() == time) {
                Job job = jobQueue.poll();
                waitQueue.offer(job);
            }

            //현재 실행 중인 일이 없다면 대기 큐에서 뽑아와 실행
            if(workingRemainTime == 0) {
                if(!waitQueue.isEmpty()){
                    Job job = waitQueue.poll();
                    job.setTurnaroundMs(time+job.getWrokingMs()-job.getRequestedMs());
                    turnaroundMsSum += time+job.getWrokingMs()-job.getRequestedMs();
                    workingRemainTime = job.getWrokingMs();
                } else {
                    time++;
                    continue;
                }
            }

            workingRemainTime--;
            time++;
        }


        return turnaroundMsSum/jobs.length;
    }
}