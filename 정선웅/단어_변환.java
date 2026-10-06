import java.util.*;

class Solution {
    int min = Integer.MAX_VALUE;
    boolean[] visited;

    public boolean isOk(String str, String word) {
        char[] strArr = str.toCharArray();
        char[] wordArr = word.toCharArray();

        int time = 0;
        for(int i=0; i<strArr.length; i++) {
            if(strArr[i] != wordArr[i])
                time++;
        }
        return time == 1;
    }

    public void bfs(String str, String target, String[] words, int depth) {
        if(str.equals(target)){
            min = Math.min(min, depth);
            return;
        }

        for(int i=0; i<words.length; i++) {
            if(isOk(str, words[i]) && !visited[i]) {
                visited[i] = true;
                bfs(words[i], target, words, depth+1);
                visited[i] = false;
            }
        }
    }

    public int solution(String begin, String target, String[] words) {
        visited = new boolean[words.length];

        bfs(begin, target, words, 0);
        if(min == Integer.MAX_VALUE)
            return 0;
        return min;
    }
}