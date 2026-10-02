import java.util.*;

class Solution {
    int[] weights;
    Queue<Integer> q = new LinkedList<>();
    int[] result;
    List<List<Integer>> graph = new ArrayList<>();

    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        result = new int[sources.length];
        Arrays.fill(result, -1);

        for(int i=0; i<=n; i++) graph.add(new ArrayList<>());
        for(int[] road : roads) {
            graph.get(road[0]).add(road[1]);
            graph.get(road[1]).add(road[0]);
        }

        weights = new int[n+1];
        Arrays.fill(weights, Integer.MAX_VALUE);
        weights[destination] = 0;
        q.offer(destination);

        while(!q.isEmpty()) {
            int node = q.poll();

            for(int next : graph.get(node)) {
                if(weights[node] + 1 < weights[next]) {
                    q.offer(next);
                    weights[next] = weights[node] + 1;
                }
            }
        }

        for(int i=0; i<sources.length; i++) {
            result[i] = weights[sources[i]] == Integer.MAX_VALUE ? -1 : weights[sources[i]];
        }
        return result;

    }
}