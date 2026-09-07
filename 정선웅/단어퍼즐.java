import java.util.*;

class Solution {
    public int solution(String[] strs, String t) {
        int[] dp = new int[t.length() + 1];

        for(int i=0; i<dp.length; i++) {
            dp[i] = Integer.MAX_VALUE;
        }
        dp[0] = 0;

        for(int i=0; i<t.length(); i++) {
            if(dp[i] != Integer.MAX_VALUE) {
                for(String str : strs) {
                    if(t.startsWith(str,i)) {
                        int index = i + str.length();
                        dp[index] = Math.min(dp[i]+1, dp[index]);
                    }
                }
            }
        }

        if(dp[t.length()] == Integer.MAX_VALUE){
            return -1;
        }
        return dp[t.length()];
    }
}