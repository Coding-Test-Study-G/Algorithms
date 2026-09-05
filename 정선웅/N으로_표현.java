import java.util.*;

class Solution {

    public int solution(int N, int number) {
        List<Integer>[] dp = new List[9];
        dp[1] = new ArrayList<>(List.of(N));
        if(dp[1].contains(number)){
            return 1;
        }
        String x = "11";
        for(int i=2; i<9; i++) {
            dp[i] = new ArrayList<>();
            dp[i].add(N * Integer.parseInt(x));
            x = x + "1";

            for (int j = 1; j < i; j++) {
                for (int a : dp[j]) {
                    for (int b : dp[i - j]) {
                        dp[i].add(a + b);
                        dp[i].add(a - b);
                        dp[i].add(a * b);
                        if (b != 0)
                            dp[i].add(a / b);
                    }
                }
            }

            if(dp[i].contains(number))
                return i;
        }
        return -1;
    }
}