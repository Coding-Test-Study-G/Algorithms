import java.util.*;

class Solution {

    public int solution(int[][] routes) {
        Arrays.sort(routes, (a,b) -> a[1] - b[1]);

        int[] pre= routes[0];
        int count = 1;

        for(int i=1; i<routes.length; i++) {
            int[] cur = routes[i];

            if(pre[1] >= cur[0]) {
                continue;
            }else{
                pre=cur;
            }

            count++;
        }

        return count;
    }
}