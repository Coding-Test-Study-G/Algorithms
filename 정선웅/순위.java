import java.util.*;

class Solution {
    int[][] weights;
    public int solution(int n, int[][] results) {
        weights = new int[n+1][n+1];
        for(int i=0; i<weights.length; i++) {
            Arrays.fill(weights[i], 0);
        }


        for(int[] result : results) {
            weights[result[0]][result[1]] = 1;
            weights[result[1]][result[0]] = -1;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                for(int k=1; k<=n; k++) {
                    if(weights[j][i] == 1 && weights[i][k] == 1) {
                        weights[j][k] = 1;
                        weights[k][j] = -1;
                    }
                    if(weights[j][i] == -1 && weights[i][k] == -1) {
                        weights[j][k] = -1;
                        weights[k][j] = 1;
                    }
                }
            }
        }

        int result = 0;
        for(int i=1; i<=n; i++) {
            int count = 0;
            for(int j=1; j<=n; j++) {
                if(weights[i][j] != 0) {
                    count++;
                }
            }
            if(count == n-1){
                result++;
            }
        }

        return result;
    }
}