import java.util.*;

class Solution {

    public int getMaxDp(int[][]dp, int i, int j) {
        if(j==i) {
            return dp[i-1][j-1];
        } else if(j==0) {
            return dp[i-1][j];
        } else {
            return Math.max(dp[i-1][j-1], dp[i-1][j]);
        }
    }

    public int solution(int[][] triangle) {
        int[][] dp = new int[triangle.length][triangle.length];
        dp[0][0] = triangle[0][0];

        int col = 0;
        for(int i=1; i<triangle.length; i++) {
            for(int j=0; j<triangle[i].length; j++) {
                dp[i][j] = getMaxDp(dp, i,j)+ triangle[i][j];
            }
        }

        int result = 0;
        for(int i=0; i<dp[dp.length-1].length; i++){
            result = Math.max(result, dp[dp.length-1][i]);
        }

        return result;
    }
}