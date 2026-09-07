class Solution {
    public void getDp(boolean[][] puddleMap, int[][] dp, int row, int col) {
        if(puddleMap[row][col])
            return;
        if(!puddleMap[row-1][col]){
            dp[row][col] += dp[row-1][col];
        }
        if(!puddleMap[row][col-1]){
            dp[row][col] += dp[row][col-1];
        }
        dp[row][col] %= 1000000007;
    }

    public void makePuddleMap(boolean[][] puddleMap, int[][] puddles) {
        for(int[] puddle: puddles) {
            int row = puddle[0];
            int col = puddle[1];
            puddleMap[col][row] = true;
        }
    }

    public int solution(int m, int n, int[][] puddles) {
        int row =n+1;
        int col =m+1;
        int[][]dp = new int[row][col];
        boolean[][] puddleMap = new boolean[row+1][col+1];
        makePuddleMap(puddleMap, puddles);
        dp[1][1] = 1;
        for(int i=1; i< row; i++) {
            for(int j=1; j< col; j++) {
                getDp(puddleMap, dp, i, j);
            }
        }

        return dp[row-1][col-1];
    }
}