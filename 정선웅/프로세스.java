import java.util.*;

class Solution {
    public void makePriorityQueue(PriorityQueue<Integer> pq, int[] priorities) {
        for(int pr: priorities) {
            pq.add(pr);
        }
    }

    public int solution(int[] priorities, int location) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        // 우선순위 순으로 정렬
        makePriorityQueue(pq, priorities);

        int num = 0;
        while(!pq.isEmpty()) {
            for(int i=0; i<priorities.length; i++) {
                if(pq.peek() == priorities[i]){
                    pq.poll();
                    num++;
                    if(i == location)
                    {
                        return num;
                    }
                }
            }
        }
        return num;
    }
}