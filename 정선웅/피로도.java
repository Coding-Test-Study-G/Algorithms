import java.util.*;

class Solution {
    boolean[] visited;
    int maxDepth = 0;
    public void dfs(int leftFatigue, int[][] dungeons, int depth) {
        maxDepth = Math.max(maxDepth, depth);

        for(int i=0; i<dungeons.length; i++) {
            if(!visited[i] && leftFatigue >= dungeons[i][0]){
                visited[i] = true;
                dfs(leftFatigue - dungeons[i][1], dungeons, depth + 1);
                visited[i] = false;
            }
        }
        return;
    }

    public int solution(int k, int[][] dungeons) {
        visited = new boolean[dungeons.length];
        dfs(k, dungeons, 0);
        return maxDepth;
    }
}