class Solution {
    int[] dp1;
    int[] dp2;

    public int solution(int[] money) {
        int max = 0;

        dp1 = new int[money.length];
        dp2 = new int[money.length];

        dp1[0] = money[0];
        dp1[1] = money[1];
        dp1[2] = dp1[0] + money[2];

        for(int i=3; i<money.length-1; i++) {
            dp1[i] = money[i] + Math.max(dp1[i-2], dp1[i-3]);
        }

        dp2[0] = 0;
        dp2[1] = money[1];
        dp2[2] = dp2[0] + money[2];

        for(int i=3; i<money.length; i++) {
            dp2[i] = money[i] + Math.max(dp2[i-2], dp2[i-3]);
        }

        for(int i=0; i<dp1.length; i++) {
            max = Math.max(max,dp1[i]);
        }
        for(int i=0; i<dp1.length; i++) {
            max = Math.max(max,dp2[i]);
        }

        return max;
    }
}