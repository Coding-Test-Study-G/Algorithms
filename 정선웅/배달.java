import java.util.*;

class Solution {
    PriorityQueue<Integer> pq = new PriorityQueue<>();
    int[] weights;

    public int solution(int N, int[][] road, int K) {
        weights = new int[N+1];
        Arrays.fill(weights, Integer.MAX_VALUE);

        pq.offer(1);
        weights[1] = 0;

        while(!pq.isEmpty()) {
            int node = pq.poll();
            for(int[] r : road) {
                if(r[0] == node) {
                    if(weights[r[0]] + r[2] < weights[r[1]]) {
                        pq.offer(r[1]);
                        weights[r[1]] = weights[r[0]] + r[2];
                    } else {
                        weights[r[1]] = weights[r[1]];
                    }
                }
                if(r[1] == node) {
                    if(weights[r[1]] + r[2] < weights[r[0]]) {
                        pq.offer(r[0]);
                        weights[r[0]] = weights[r[1]] + r[2];
                    } else {
                        weights[r[0]] = weights[r[0]];
                    }
                }
            }
        }

        int count = 0;
        for(int weight : weights) {
            if(weight <= K)
                count++;
        }
        return count;
    }
}