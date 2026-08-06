import java.util.*;

class Solution {
    Set<Integer> primeCandidates = new HashSet<>();
    boolean[] visited;

    public boolean isPrime(int num) {
        if(num < 2)
            return false;

        for(int i=2; i*i<=num; i++) {
            if(num%i==0)
                return false;
        }
        return true;
    }

    public void dfs(int depth, String number, char[] numbers) {
        if(depth == numbers.length)
            return;

        for(int i=0; i<numbers.length; i++) {
            if(!visited[i]){
                primeCandidates.add(Integer.parseInt(number + numbers[i]));
                visited[i] = true;
                dfs(depth + 1, number + numbers[i], numbers);
                visited[i] = false;
            }
        }
    }

    public int solution(String numbers) {
        visited = new boolean[numbers.length()];
        dfs(0,"",numbers.toCharArray());
        int count = 0;
        for(int primeCandidate : primeCandidates) {
            if(isPrime(primeCandidate)) {
                count++;
            }
        }
        return count;
    }
}