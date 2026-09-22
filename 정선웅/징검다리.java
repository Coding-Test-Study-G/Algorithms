import java.util.Arrays;

class Solution {
    public int solution(int distance, int[] rocks, int n) {
        Arrays.sort(rocks);
        int answer = 0;
        int[] subDistances = new int[rocks.length + 1];
        subDistances[0] = rocks[0];
        subDistances[rocks.length] = distance - rocks[rocks.length - 1];
        for(int i = 1; i < rocks.length; i++) {
            subDistances[i] = rocks[i] - rocks[i - 1];
        }
        int maxDistance = distance;
        int minDistance = 1;
        while(minDistance <= maxDistance) {
            int midDistance = (minDistance + maxDistance) / 2;
            int distanceSum = 0;
            int removedStone = 0;
            for(int i = 0; i < subDistances.length; i++) {
                distanceSum += subDistances[i];
                if(distanceSum < midDistance) {
                    removedStone++;
                    continue;
                }
                distanceSum = 0;
            }
            if(removedStone > n) {
                maxDistance = midDistance - 1;
                continue;
            }
            minDistance = midDistance + 1;
            answer = Math.max(answer, midDistance);
        }
        return answer;
    }
}