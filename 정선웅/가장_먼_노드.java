import java.util.*;

class Solution {
    Queue<Integer> pq = new LinkedList<>();
    int[] weights;
    int count = 0;
    int max = 0;


    public int solution(int n, int[][] edge) {
        weights = new int[n+1];
        Arrays.fill(weights, Integer.MAX_VALUE);

        pq.offer(1);
        weights[0] = 0;
        weights[1] = 0;

        while(!pq.isEmpty()) {
            int node = pq.poll();
            for(int[] e : edge) {
                if(e[0] == node) {
                    if(weights[e[1]] > weights[e[0]]+1) {
                        pq.offer(e[1]);
                        weights[e[1]] = weights[e[0]]+1;
                    }
                }

                if(e[1] == node) {
                    if(weights[e[0]] > weights[e[1]]+1){
                        pq.offer(e[0]);
                        weights[e[0]] = weights[e[1]]+1;
                    }
                }
            }
        }

        for(int w : weights) {
            if(w > max) {
                max = w;
                count = 1;
            } else if (w == max) {
                count++;
            }
        }

        return count;
    }

}