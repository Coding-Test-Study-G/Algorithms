import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
        Arrays.sort(times);
        long left = 0;
        long right = (long)times[times.length-1] * n;
        long answer = 0;
        while(left <= right) {
            long mid = (left+right)/2;
            long completeCount = 0;
            for(int i=0; i<times.length; i++) {
                completeCount += mid/times[i];
            }
            if(completeCount < n){
                left = mid + 1;
            } else {
                right = mid - 1;
                answer = mid;
            }
        }
        return answer;
    }
}