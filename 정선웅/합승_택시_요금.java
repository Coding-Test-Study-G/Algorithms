import java.util.*;

class Solution {
    int[][] weights;
    public int solution(int n, int s, int a, int b, int[][] fares) {
        weights = new int[n+1][n+1];
        for(int i=0; i<weights.length; i++) {
            Arrays.fill(weights[i], 19900000);
            weights[i][i] = 0;
        }

        for(int[] fare : fares) {
            weights[fare[0]][fare[1]] = fare[2];
            weights[fare[1]][fare[0]] = fare[2];
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                for(int k=1; k<=n; k++) {
                    if(weights[j][i] != 0 && weights[i][k] != 0) {
                        weights[j][k] = Math.min(weights[j][k], weights[j][i] + weights[i][k]);
                    }
                }
            }
        }

        int min = Integer.MAX_VALUE;
        for(int i=1; i<=n; i++) {
            min = Math.min(min,
                    weights[s][i] + weights[i][a] + weights[i][b]
            );
        }
        return min;
    }
}