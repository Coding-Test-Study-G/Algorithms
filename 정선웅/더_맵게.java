import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> scovillePriorities = new PriorityQueue<>();
        int times = 0;

        for(int scovilleNum : scoville) {
            scovillePriorities.offer(scovilleNum);
        }

        while(scovillePriorities.peek() < K) {
            times++;

            if(scovillePriorities.size() <2) {
                return -1;
            }

            int firstNotSpicy = scovillePriorities.poll();
            int secondNotSpicy = scovillePriorities.poll();
            firstNotSpicy += 2*secondNotSpicy;
            scovillePriorities.offer(firstNotSpicy);
        }
        return times;
    }
}