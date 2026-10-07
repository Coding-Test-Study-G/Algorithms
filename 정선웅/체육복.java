import java.util.*;
import java.util.stream.*;

class Solution {
    boolean[] visited;
    public int solution(int n, int[] lost, int[] reserve) {
        visited = new boolean[n+1];
        Arrays.sort(lost);
        Arrays.sort(reserve);

        List<Integer> reserve2 = Arrays.stream(reserve).boxed().collect(Collectors.toList());
        List<Integer> lost2 = Arrays.stream(lost).boxed().collect(Collectors.toList());

        for(int r: reserve) {
            boolean flag=false;
            for(int l : lost) {
                if(r==l){
                    flag=true;
                }
            }
            if(flag) {
                reserve2.remove(Integer.valueOf(r));
                lost2.remove(Integer.valueOf(r));
            }

        }
        int result = n - lost2.size();

        for(int l : lost2) {
            for(int r : reserve2) {
                if ((r-1 == l || r+1 == l) && !visited[r]) {
                    visited[r] = true;
                    result++;
                    break;
                }
            }
        }
        return result;
    }
}