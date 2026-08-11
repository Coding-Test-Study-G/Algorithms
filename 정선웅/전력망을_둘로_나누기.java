import java.util.*;

class Solution {
    boolean[] visited;

    public int dfs(int node, List<Integer>[] graph) {
        visited[node] = true;
        int count = 1;

        for(int next : graph[node]) {
            if(!visited[next]){
                count += dfs(next, graph);
            }
        }
        return count;
    }

    public int solution(int n, int[][] wires) {
        List<Integer>[] graph = new List[n+1];
        visited = new boolean[n];

        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for(int i=0; i<wires.length; i++) {
            graph[wires[i][1]].add(wires[i][0]);
            graph[wires[i][0]].add(wires[i][1]);
        }

        int result = Integer.MAX_VALUE;

        for(int i=0; i<wires.length; i++) {
            int n1 = wires[i][0];
            int n2 = wires[i][1];

            graph[n1].remove(Integer.valueOf(n2));
            graph[n2].remove(Integer.valueOf(n1));

            visited = new boolean[n+1];

            int leftCount = dfs(n1, graph);
            int rightCount = n-leftCount;
            result = Math.min(result, Math.abs(leftCount - rightCount));

            graph[n1].add(n2);
            graph[n2].add(n1);
        }
        return result;
    }
}