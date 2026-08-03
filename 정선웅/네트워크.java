import java.util.*;

class Solution {

    boolean[] visited;
    int count = 0;

    public void dfs(int node, int[][] computers) {
        visited[node] = true;
        for(int i=0; i<computers[node].length; i++){
            if(computers[node][i] == 1 && !visited[i]){
                dfs(i, computers);
            }
        }
    }

    public int solution(int n, int[][] computers) {
        visited = new boolean[computers.length];

        for(int i=0; i<computers.length; i++) {
            if(!visited[i]) {
                dfs(i, computers);
                count++;
            }
        }
        return count;
    }
}